#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int maxn=500010, inf=1e9;
struct poi{int too, pre;}e[maxn<<1];
struct tjm{int nxt[26], size;}tree[maxn];
int n, x, y, ans, cnt, tot;
int last[maxn], c[maxn];
char s[maxn];
inline void read(int &k)
{
    int f=1; k=0; char c=getchar();
    while(c<'0' || c>'9') c=='-' && (f=-1), c=getchar();
    while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
    k*=f;
}
inline void add(int x, int y){e[++tot]=(poi){y, last[x]}; last[x]=tot;}
void merge(int &x, int y)
{
    if(!x || !y) {x+=y; return;}
    tree[x].size=1;
    for(int i=0;i<26;i++)
        merge(tree[x].nxt[i], tree[y].nxt[i]), tree[x].size+=tree[tree[x].nxt[i]].size;
}
void dfs(int x, int fa)
{
    tree[x].size=1;
    for(int i=last[x], too;i;i=e[i].pre)
    if((too=e[i].too)!=fa)
    {
        dfs(too, x); int tmp=tree[tree[x].nxt[s[e[i].too]-'a']].size;
        merge(tree[x].nxt[s[e[i].too]-'a'], e[i].too);
        tree[x].size+=tree[tree[x].nxt[s[e[i].too]-'a']].size-tmp; 
    }
    if(tree[x].size+c[x]>ans) ans=tree[x].size+c[x], cnt=1;
    else if(tree[x].size+c[x]==ans) cnt++;
}
int main()
{
    read(n);
    for(int i=1;i<=n;i++) read(c[i]); scanf("%s", s+1);
    for(int i=1;i<n;i++) read(x), read(y), add(x, y), add(y, x);
    dfs(1, 0); printf("%d\n%d", ans, cnt);
}