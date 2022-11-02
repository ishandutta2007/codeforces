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
const int V=200100;
int tr[27][V],N[27];
int find(int id,int k)
{
    int idx = 0;
    for (int i = 20; i >= 0; i--)
    {
        idx ^= 1 << i;
        if (idx <=N[id]&& tr[id][idx] < k) k -= tr[id][idx];
        else idx ^= 1 << i;
    }
    return idx + 1;
}
void update(int id,int k,int v)
{
    while(k<=N[id])
    {
        tr[id][k]+=v;
        k+=k&-k;
    }
}
int read(int id,int k)
{
    int ret=0;
    while(k)
    {
        ret+=tr[id][k];
        k-=k&-k;
    }
    return ret;
}
char s[120],ch[120];
int pos[120],i,j,id,K,Q,k,va;
int main()
{
    while(~scanf("%d",&K))
    {
        scanf("%s",s);
        int le=strlen(s);
        memset(N,0,sizeof(N));
        memset(tr,0,sizeof(tr));
        for(i=0;i<le;i++)
        N[s[i]-'a']++;
        for(i=0;i<26;i++)N[i]*=K,N[i]+=2;
        for(i=0;i<26;i++)
        for(j=1;j<=N[i];j++)
        update(i,j,1);
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%d%s",&k,ch);
            id=find(ch[0]-'a',k);
            update(ch[0]-'a',id,-1);
        }
        memset(pos,0,sizeof(pos));
        for(i=0;i<K;i++)
        for(j=0;j<le;j++)
        {
            id=s[j]-'a';
            va=++pos[id];
            if(read(id,va)!=read(id,va-1))
            printf("%c",s[j]);
        }puts("");
    }
}