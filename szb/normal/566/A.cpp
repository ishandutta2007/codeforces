#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#define ll int
#define lf else if
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
const ll N=800010;
ll c[N][26],pre[N],q[N],X[N],Y[N],fa[N],n,cnt,gg,use[N];
long long ans;
char s[N];	vector<ll>tr[N],del[N];
void insert(ll id){
	ll n=strlen(s+1),now=0;	tr[0].push_back(id);
	For(i,1,n){
		if (!c[now][s[i]-'a'])	c[now][s[i]-'a']=++cnt,pre[cnt]=now;
		now=c[now][s[i]-'a'];	tr[now].push_back(id);
	}
}
void dfs(ll x,ll dep){
	ll son=0;
	For(i,0,25)	if (c[x][i])	dfs(c[x][i],dep+1);
	ll tot=0;
	for(ll i=0;i<tr[x].size();i++)	if (!use[tr[x][i]])	q[++tot]=tr[x][i];
	ll l=1,r=tot;
	while(l<r&&(q[l]<=n)&&(q[r]>n))	use[q[l]]=1,use[q[r]]=1,X[++gg]=q[l++],Y[gg]=q[r--],ans+=dep;
}
int main(){
//	freopen("shenzhebei.in","r",stdin);
	n=read();
	For(i,1,n*2){
		scanf("%s",s+1);
		insert(i);
	}
	dfs(0,0);
	printf("%I64d\n",ans);
	For(i,1,n)	printf("%d %d\n",X[i],Y[i]-n);
}