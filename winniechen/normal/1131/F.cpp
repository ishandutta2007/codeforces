#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rt register int
#define l putchar('\n')
#define ll long long
#define r read()
#define p 998244353
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
int F[450010],N[450010],L[450010],a[450010],fa[450010];
void add(int x,int y){
	a[++k]=y;fa[y]=x;
	if(!F[x])F[x]=k;
	else N[L[x]]=k;
	L[x]=k;
}
int ask(int x){
	return (x==fa[x])?x:(fa[x]=ask(fa[x]));
}
void dfs(int x){
	if(x<=n)write(x),putchar(' ');
	for(rt i=F[x];i;i=N[i])dfs(a[i]);
}
int main(){
	n=r;
	for(rt i=1;i<=n;i++)fa[i]=i;
	cnt=n;
	for(rt i=1;i<n;i++){
		x=r;y=r;
		cnt++;fa[cnt]=cnt;
		int id1=ask(x),id2=ask(y); 
		add(cnt,id1);add(cnt,id2);
	}
	dfs(cnt);
    return 0;
}