#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define maxn 100000
#define pb push_back
using namespace std;
typedef long long ll;
int fa[maxn+5],val[maxn+5],n,m,q;
map<string,int> M;
string s,s1,s2;
int getfa(int now)
{
    if(fa[now]==now) return now;
    int oldfa=fa[now];
    fa[now]=getfa(oldfa);
    val[now]=val[now]^val[oldfa];
    return fa[now];
}
int check(int v,int x,int y)
{
    int xfa=getfa(x),yfa=getfa(y);
    if(xfa!=yfa) return 2;
    if(v==(val[x]^val[y])) return 1;
    return 0;
}
void modify(int v,int x,int y)
{
    int xfa=getfa(x),yfa=getfa(y);
    if(xfa==yfa) return;
    fa[xfa]=yfa;
    val[xfa]=v^val[y]^val[x];
    return;
}
int main()
{
    int i,v,x,y;
    scanf("%d%d%d",&n,&m,&q);
    rep(i,1,n)
    {
        cin>>s;
        M[s]=i;
        fa[i]=i;
    }
    rep(i,1,m)
    {
        scanf("%d",&v);
        cin>>s1>>s2;
        x=M[s1];
        y=M[s2];
        if(check(v-1,x,y)>0)
        {
            printf("YES\n");
            modify(v-1,x,y);
        }
        else printf("NO\n");
    }
    rep(i,1,q)
    {
        cin>>s1>>s2;
        x=M[s1];
        y=M[s2];
        int judge=check(1,x,y);
        if(judge==2) printf("3\n");
        else if(judge==1) printf("2\n");
        else if(judge==0) printf("1\n");
    }
    return 0;
}