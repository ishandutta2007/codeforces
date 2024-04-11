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
const int P=10000007;
struct Edge{int len,va,ne,cnt,va2;}e[P];
int p[P],K;
void add(int len,int va,int va2)
{
    int re=((LL)len*101010%P+va)%P;
    for(int i=p[re];i!=-1;i=e[i].ne)
    {
        if(e[i].len==len&&e[i].va==va&&e[i].va2==va2)
        {
            e[i].cnt++;
            return;
        }
    }
    e[K].len=len;e[K].va=va;e[K].va2=va2;
    e[K].ne=p[re];e[K].cnt=1;p[re]=K++;
}
int find(int len,int va,int va2)
{
    int re=((LL)len*101010%P+va)%P;
    for(int i=p[re];i!=-1;i=e[i].ne)
    {
        if(e[i].len==len&&e[i].va==va&&e[i].va2==va2)
        {
            return i;
        }
    }
    return 0;
}
const int Ex=37;
const int mod=1000000009;
char s[2100],t[2100];
int l[120],r[120],n;
int can[2100][2100];
int main()
{
    while(~scanf("%s",s))
    {
        scanf("%d",&n);
        memset(can,0,sizeof(can));
        memset(p,-1,sizeof(p));K=1;
        if(n==0)
        {
            int m=strlen(s);
            int ret=0;
            for(int i=0;i<m;i++)
            {
                int va=0,va2=0;
                for(int j=i;j<m;j++)
                {
                    va=((LL)va*Ex+(s[j]-'a'))%P;
                    va2=va2*Ex+(s[j]-'a');
                    add(j-i+1,va,va2);
                }
            }
            printf("%d\n",K-1);
            continue;
        }
        e[0].cnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",t);
            scanf("%d%d",&l[i],&r[i]);
            memset(p,-1,sizeof(p));K=1;
            int m=strlen(t);
            for(int j=0;j<m;j++)
            {
                int va=0,va2=0;
                for(int k=j;k<m;k++)
                {
                    va=((LL)va*Ex+(t[k]-'a'))%P;
                    va2=va2*Ex+(t[k]-'a');
                    add(k-j+1,va,va2);
                }
            }
            m=strlen(s);
            for(int j=0;j<m;j++)
            {
                int va=0,va2=0;
                for(int k=j;k<m;k++)
                {
                    va=((LL)va*Ex+(s[k]-'a'))%P;
                    va2=va2*Ex+(s[k]-'a');
                    int x=e[find(k-j+1,va,va2)].cnt;
                    if(x<l[i]||x>r[i])
                    can[j][k]=1;
                }
            }
        }
        memset(p,-1,sizeof(p));K=1;
        int ret=0;
        int m=strlen(s);
        for(int j=0;j<m;j++)
        {
            int va=0,va2=0;
            for(int k=j;k<m;k++)
            {
                if(can[j][k])continue;
                va=((LL)va*Ex+(s[k]-'a'))%P;
                va2=va2*Ex+(s[k]-'a');
                int x=e[find(k-j+1,va,va2)].cnt;
                if(x==0)
                {
                    ret++;
                    add(k-j+1,va,va2);
                }
            }
        }
        printf("%d\n",ret);
    }
}