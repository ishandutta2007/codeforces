/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
char s[V],ch[12];
int pos[26][V],nu[26];
int dp[26][V],d[26][1200],dn[26];
int now[26],deal[26];
struct Node{int pos,id;}q[1200];
bool cmp(Node x,Node y)
{return x.pos<y.pos;}
int n,i,j,k,Q,L,R,ct,l,r,Ri[V],last[26];
int main()
{
    while(~scanf("%s",s))
    {
        int n=strlen(s);
        memset(nu,0,sizeof(nu));
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        pos[s[i]-'a'][nu[s[i]-'a']++]=i;
        for(i=0;i<26;i++)last[i]=n;
        for(i=n-1;i>=0;i--)
        {
            Ri[i]=last[s[i]-'a'];
            last[s[i]-'a']=i;
        }
        scanf("%d%d%d",&Q,&L,&R);
        for(i=0;i<Q;i++)
        {
            scanf("%s%d%d",ch,&l,&r);
            for(j=l;j<=min(r,nu[ch[0]-'a']);j++)
            dp[ch[0]-'a'][j]++;
        }
        memset(dn,0,sizeof(dn));
        for(i=0;i<26;i++)
        {
            for(j=1;j<=nu[i];j++)
            if(dp[i][j]!=dp[i][j-1])
            d[i][dn[i]++]=j;
        }
        LL ans=0;
        memset(now,-1,sizeof(now));
        ct=0;
        for(j=0;j<26;j++)
        {
            for(k=0;k<dn[j]&&now[j]+d[j][k]<nu[j];k++)
            {
                q[ct].pos=pos[j][now[j]+d[j][k]];
                q[ct++].id=j;
            }
        }
        q[ct++].pos=n;
        sort(q,q+ct,cmp);
        for(i=0;i<n;i++)
        {
        //  printf("%d : ",i);for(j=0;j<ct-1;j++)printf("%d %d   ",q[j].pos,q[j].id);cout<<ans<<" ";puts("");
            int te=0;
            memset(deal,0,sizeof(deal));
            for(j=0;j<26;j++)te+=dp[j][0];
            if(te>=L&&te<=R)ans+=q[0].pos-i;
            for(j=0;q[j].pos<n;j++)
            {
                int id=q[j].id;
                int tp=d[id][deal[id]];
                te+=dp[id][tp]-dp[id][tp-1];
                deal[id]++;
                if(te>=L&&te<=R)ans+=q[j+1].pos-q[j].pos;
            }
            now[s[i]-'a']++;
            for(j=ct-1;j>=0;j--)
            {
                if(q[j].pos>=n)continue;
                if(q[j].id==s[i]-'a')
                {
                    q[j].pos=Ri[q[j].pos];
                    k=j;
                    while(q[k].pos>q[k+1].pos)
                    {swap(q[k],q[k+1]);k++;}
                }
            }
        }
        cout<<ans<<endl;
    }
}