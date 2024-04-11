#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int mod=100007;
struct Edge{int st,ne,ct;}e[mod];
int p[mod+10],K,has[mod+10];
void init()
{
    memset(p,-1,sizeof(p));K=0;
    memset(has,0,sizeof(has));
}
void add(int x)
{
    int re=x%mod;
    if(has[re])
    {
        for(int i=p[re];i!=-1;i=e[i].ne)
        if(e[i].st==x)return;
    }
    has[re]=1;e[K].st=x;e[K].ct=0;
    e[K].ne=p[re];p[re]=K++;
}
int find(int x)
{
    int re=x%mod;
    if(has[re])
    {
        for(int i=p[re];i!=-1;i=e[i].ne)
        if(e[i].st==x)return i;
    }
    return -1;
}
void AD(int x)
{
    int re=x%mod;
    if(has[re])
    {
        for(int i=p[re];i!=-1;i=e[i].ne)
        if(e[i].st==x)
        {
            e[i].ct++;
            return;     
        }
    }
}
const int V=1000100;
char s[V],t[V];
const int oo=1000000000;
int id[V],r[V][26];
struct Node{int va,id;}q[30];
bool cmp(Node x,Node y)
{return x.va<y.va;}
int main()
{
    while(~scanf("%s",s))
    {
        int n=strlen(s);
        init();int Q;
        scanf("%d",&Q);
        for(int i=0;i<Q;i++)
        {
            scanf("%s",t);
            int m=strlen(t);
            int ts=0;
            for(int j=0;j<m;j++)
            ts|=(1<<(t[j]-'a'));
            if(find(ts)==-1)add(ts);
            id[i]=find(ts);
        }
        for(int i=0;i<26;i++)r[n][i]=oo;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<26;j++)
            r[i][j]=r[i+1][j];
            r[i][s[i]-'a']=i;
            for(int j=0;j<26;j++)
            q[j].va=r[i][j],q[j].id=j;
            sort(q,q+26,cmp);
            int nt=0;
            for(int j=0;j<26;j++)
            {
                if(q[j].va==oo)break;
                if(i!=0&&q[j].id==s[i-1]-'a')break;
                nt|=(1<<q[j].id);AD(nt);
            }
        }
        for(int i=0;i<Q;i++)
        printf("%d\n",e[id[i]].ct);
    }
}