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
const int P=1000000007;
const int N=300100;
char s[N];  /// +1
int sa[N];  ///    1-n  i   sa[i]
int rk[N];  ///   i   rk[i]
int wa[N],wb[N],wv[N],h[N];
int sn,to[N];
bool cmp(int *y,int a,int b,int L)
{return y[a]==y[b]&&y[a+L]==y[b+L];}
void da(char *s,int *sa,int len,int dn)
{
    int i,j,p;
    int *x,*y,*t;
    x=wa;y=wb;
    for(i=0;i<dn;i++)rk[i]= 0;
    for(i=0;i<len;i++)rk[x[i]=s[i]]++;
    for(i=0;i<dn;i++)rk[i+1]+=rk[i];
    for(i=len-1;i>=0;i--)sa[--rk[x[i]]]=i;
    for(j=1,p=1;p<len;j*=2,dn=p)
    {
        for(p=0;p<j;p++)y[p]=len-j+p;
        for(i=0;i<len;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        for(i=0;i<len;i++)wv[i]=x[y[i]];
        for(i=0;i<dn;i++)rk[i]=0;
        for(i=0;i<len;i++)rk[wv[i]]++;
        for(i=0;i<dn;i++)rk[i+1]+=rk[i];
        for(i=len-1;i>=0;i--)sa[--rk[wv[i]]]=y[i];
        swap(x,y);x[sa[0]]=0;
        for(p=i=1;i<len;i++)
        {
            p+=!cmp(y,sa[i],sa[i-1],j);
            x[sa[i]]=p-1;
        }
    }
}
void find_height(char *s,int *sa,int len)
{
    int i,j,k=0;
    for(i=1;i<=len;i++)
    rk[sa[i]] = i;
    for(i=0;i<len;i++)
    {
        if(k>0)k--;
        j=sa[rk[i]-1];
        while(s[i+k]==s[j+k])k++;
        h[rk[i]]=k;
    }
}
int set[N],ct[3][N];
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y)
{
    int rx=find(x);
    int ry=find(y);
    if(rx==ry)return;
    for(int i=0;i<3;i++)
    ct[i][rx]+=ct[i][ry];
    set[ry]=rx;
}
char ss[3][N];
int ret[N],id[N],len[3];
vector<int> v[N];
int main()
{
    while(~scanf("%s%s%s",ss[0],ss[1],ss[2]))
    {
        for(int i=0;i<3;i++)len[i]=strlen(ss[i]);
        int sn=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<len[i];j++)
            s[sn++]=ss[i][j];
            s[sn++]=('0'+i);
        }
        s[sn]=0;
        da(s,sa,sn+1,128);
        find_height(s,sa,sn);
        //printf("%s\n",s);
        //for(int i=0;i<=sn;i++)printf("%d ",sa[i]);puts("");
        //for(int i=0;i<=sn;i++)printf("%d ",rk[i]);puts("");
        //for(int i=0;i<=sn;i++)printf("%d ",h[i]);puts("");
        for(int i=0;i<=sn;i++)set[i]=i;
        memset(ct,0,sizeof(ct));
        for(int i=0;i<len[0];i++)ct[0][i]=1;
        for(int i=0;i<len[1];i++)ct[1][i+len[0]+1]=1;
        for(int i=0;i<len[2];i++)
        ct[2][i+len[0]+1+len[1]+1]=1;
        for(int i=0;i<=sn;i++)v[i].clear();
        for(int i=1;i<=sn;i++)v[h[i]].push_back(i);
        int ans=0;
        for(int i=sn;i>0;i--)
        {
            int sz=v[i].size();
            for(int j=0;j<sz;j++)
            {
                int pos=v[i][j];
                int rx=find(sa[pos-1]);
                int ry=find(sa[pos]);
                ans-=(LL)ct[0][rx]*ct[1][rx]%P*ct[2][rx]%P;
                if(ans<0)ans+=P;
                ans-=(LL)ct[0][ry]*ct[1][ry]%P*ct[2][ry]%P;
               // printf("%d %d %d %d\n",rx,ct[0][rx],ct[1][rx],ct[2][rx]);
               // printf("%d %d %d %d\n",ry,ct[0][ry],ct[1][ry],ct[2][ry]);
                if(ans<0)ans+=P;
                U(rx,ry);
                rx=find(sa[pos]);
               // printf("%d %d %d %d\n",rx,ct[0][rx],ct[1][rx],ct[2][rx]);
                ans+=(LL)ct[0][rx]*ct[1][rx]%P*ct[2][rx]%P;
                if(ans>=P)ans-=P;
            }
            ret[i]=ans;
        }
        int rn=min(len[0],min(len[1],len[2]));
        for(int i=1;i<=rn;i++)
        {
            if(i!=1)printf(" ");
            printf("%d",ret[i]);
        }puts("");

    }
}