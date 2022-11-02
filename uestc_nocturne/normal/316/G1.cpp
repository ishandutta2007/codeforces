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
struct Edge{int id,len,va,ne,cnt;}e[P];
int p[P],K;
void add(int id,int len,int va)
{
    int re=((LL)(id*101010+len)*10101010%P+va)%P;
    for(int i=p[re];i!=-1;i=e[i].ne)
    {
        if(e[i].id==id&&e[i].len==len&&e[i].va==va)
        {
            e[i].cnt++;
            return;
        }
    }
    e[K].id=id;e[K].len=len;e[K].va=va;
    e[K].ne=p[re];e[K].cnt=1;p[re]=K++;
}
void DEL(int id,int len,int va)
{
    int re=((LL)(id*101010+len)*10101010%P+va)%P;
    for(int i=p[re];i!=-1;i=e[i].ne)
    {
        if(e[i].id==id&&e[i].len==len&&e[i].va==va)
        {
            e[i].cnt=-1;
            return;
        }
    }
    e[K].id=id;e[K].len=len;e[K].va=va;
    e[K].ne=p[re];e[K].cnt=-1;p[re]=K++;
}
int find(int id,int len,int va)
{
    int re=((LL)(id*101010+len)*10101010%P+va)%P;
    for(int i=p[re];i!=-1;i=e[i].ne)
    {
        if(e[i].id==id&&e[i].len==len&&e[i].va==va)
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
int main()
{
    while(~scanf("%s",s))
    {
        scanf("%d",&n);
        memset(p,-1,sizeof(p));K=1;
        if(n==0)
        {
            int m=strlen(s);
            int ret=0;
            for(int i=0;i<m;i++)
            {
                int va=0;
                for(int j=i;j<m;j++)
                {
                    va=((LL)va*Ex+(s[j]-'a'))%P;
                    add(0,j-i+1,va);
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
            int m=strlen(t);
            for(int j=0;j<m;j++)
            {
                int va=0;
                for(int k=j;k<m;k++)
                {
                    va=((LL)va*Ex+(t[k]-'a'))%P;
                    add(i,k-j+1,va);
                }
            }
        }
        int m=strlen(s);
        int ret=0;
        for(int i=0;i<m;i++)
        {
            int va=0;
            for(int j=i;j<m;j++)
            {
                va=((LL)va*Ex+(s[j]-'a'))%P;
                bool can=true;
                for(int k=0;k<n;k++)
                {
                    int x=e[find(k,j-i+1,va)].cnt;
                    if(x<l[k]||x>r[k]){can=false;break;}
                }
                if(can)
                {
                    //printf("%d %d\n",i,j);
                    ret++;
                    DEL(0,j-i+1,va);
                }
            }
        }
        printf("%d\n",ret);
    }
}