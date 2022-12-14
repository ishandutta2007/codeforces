#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rt register int
#define l putchar('\n')
#define ll long long
#define r read()
using namespace std;
inline ll read(){
    ll x = 0; char zf = 1; char ch = getchar();
    while (ch != '-' && !isdigit(ch)) ch = getchar();
    if (ch == '-') zf = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); return x * zf;
}
void write(ll y){if(y<0)putchar('-'),y=-y;if(y>9)write(y/10);putchar(y%10+48);}
void writeln(const ll y){write(y);putchar('\n');}
int i,j,k,m,n,x,y,z,cnt,sum;
char c[1010][1010];int fa[2010];
int ask(int x){
	return (x==fa[x])?x:(fa[x]=ask(fa[x]));
}
void unite(int x,int y){
	int p=ask(x),q=ask(y);
	if(p!=q)fa[q]=p;
}
struct query{
	int x,y;
}q[2000010];int t;
int F[2000010],L[2000010],N[2000010],a[2000010],du[2000010],ans[2000010];
void add(int x,int y){
	a[++k]=y;du[y]++;
	if(!F[x])F[x]=k;
	else N[L[x]]=k;
	L[x]=k;
}
int qu[2000010],h;bool vis[2000010];
int main(){
	n=r;m=r;
	for(rt i=1;i<=n+m;i++)fa[i]=i;
	for(rt i=1;i<=n;i++){
		scanf("%s",c[i]+1);
	}
	for(rt i=1;i<=n;i++)
	for(rt j=1;j<=m;j++)if(c[i][j]=='=')unite(i,j+n);
	else if(c[i][j]=='<')q[++t]={i,j+n};
	else q[++t]={j+n,i};
	for(rt i=1;i<=t;i++){
		int x=ask(q[i].x),y=ask(q[i].y);
		if(x==y){
			puts("No");
			return 0;
		}
		add(x,y);
	}
	h=t=0;
	for(rt i=1;i<=n+m;i++)if(!du[i]&&i==ask(i))qu[++t]=i,ans[i]=1;
	while(h<t){
		x=qu[++h];vis[x]=1;
		for(rt i=F[x];i;i=N[i]){
			ans[a[i]]=max(ans[a[i]],ans[x]+1);
			if(!--du[a[i]])qu[++t]=a[i];
		}
	}
	for(rt i=1;i<=n+m;i++)if(i==ask(i)&&du[i]){
		puts("No");return 0;
	}
	puts("Yes");
	for(rt i=1;i<=n;i++)write(ans[ask(i)]),putchar(' ');l;
	for(rt i=n+1;i<=n+m;i++)write(ans[ask(i)]),putchar(' ');l;
    return 0;
}