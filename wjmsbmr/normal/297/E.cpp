#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 100010
int n,px[N],py[N],p[N],s[N],t[N];
bool cmpx(int x,int y){return px[x]<px[y];}
int f[N*2];
int ask(int x)
{
    int S=0;
    for(;x;x-=(x&-x))S+=f[x];
    return S;
}
void add(int x)
{
    for(;x<=2*n;x+=(x&-x))f[x]++;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",px+i,py+i);
        if(px[i]>py[i])swap(px[i],py[i]);
        p[i]=i;
    }
    sort(p,p+n,cmpx);
    for(int i=0;i<n;i++)
    {
        int x=p[i];
        s[x]+=ask(py[x])-ask(px[x]);
        add(py[x]);
    }
    memset(f,0,sizeof f);
    for(int i=0;i<n;i++)
    {
        swap(px[i],py[i]);
        px[i]=2*n+1-px[i];
        py[i]=2*n+1-py[i];
    }
    sort(p,p+n,cmpx);
    for(int i=0;i<n;i++)
    {
        int x=p[i];
        s[x]+=ask(py[x])-ask(px[x]);
        add(py[x]);
    }
    //for(int i=0;i<n;i++)printf("%d%c",s[i],i==n-1?'\n':' ');
    memset(f,0,sizeof f);
    for(int i=0;i<n;i++)
    {
        swap(px[i],py[i]);
        px[i]=2*n+1-px[i];
        py[i]=2*n+1-py[i];
    }
    sort(p,p+n,cmpx);
    reverse(p,p+n);
    for(int i=0;i<n;i++)
    {
        int x=p[i];
        //printf("ASK %d %d\n",px[x],py[x]);
        t[x]+=ask(py[x])-ask(px[x]);
        add(py[x]);
        //printf("ADD %d\n",py[x]);
    }
    //for(int i=0;i<n;i++)printf("%d%c",t[i],i==n-1?'\n':' ');
    ll S=(ll)n*(n-1)*(n-2)/6;
    ll T=0;
    for(int i=0;i<n;i++)T+=(ll)s[i]*(n-s[i]-1);
    S-=T/2;
    //cout<<S<<endl;
    for(int i=0;i<n;i++)S-=(ll)t[i]*(n-s[i]-1-t[i]);
    cout<<S<<endl;
    return 0;
}