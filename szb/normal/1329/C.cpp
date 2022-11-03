#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
#define FOr(i,x,y)	for(ll i=(x);i>=(y);--i)
#define rep(i,x,y)	for(ll i=(x);i<(y);++i)
#define clr(a,v)	memset(a,v,sizeof(a))
#define cpy(a,b)	memcpy(a,b,sizeof(a))
#define fi	first
#define se	second
#define	pb	push_back
#define mk	make_pair
#define pa	pair<ll,ll>
#define y1	y11111111111111
#define debug	puts("@@@@@@@@@@@@@@@@@@@@@@@")
ll read(){
	ll x=0,f=1;	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';
	return x*f;
}
void write(ll x){
	if (x<0)	putchar('-'),write(-x);
	else{
		if (x>=10)	write(x/10);
		putchar(x%10+'0');
	}
}
const ll N=3000000;
vector<ll>Ans;
ll a[N],son[N],dep[N],len[N],h,g,n;
void updata(ll x){
	son[x]=a[x*2]>a[x*2+1]?x*2:(x*2+1);
	if (a[son[x]]==0)son[x]=0;
	len[x]=len[son[x]]+1;
}
void del(ll x){
	a[x]=a[son[x]];
	if (son[x])del(son[x]);
	updata(x);
}
void dfs(ll root){
	while(dep[root]+len[root]-1>g){
		Ans.pb(root);
		del(root);
	}
	if (a[root*2])dfs(root*2);
	if (a[root*2+1])dfs(root*2+1);
}
int main(){
	for(ll T=read();T--;){
		h=read();	g=read();	n=(1<<h)-1;	Ans.clear();
		For(i,1,n)	a[i]=read(),dep[i]=dep[i/2]+1;
		FOr(i,n,1)	updata(i);
		dfs(1);
		ll sum=0;	For(i,1,n)sum+=a[i];
		cout<<sum<<endl;
		rep(i,0,Ans.size())cout<<Ans[i]<<' ';
		puts("");
		For(i,1,n)a[i]=len[i]=son[i]=dep[i]=0;
	}
}