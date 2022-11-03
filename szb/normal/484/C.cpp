#include<bits/stdc++.h>
using namespace std;
#define ll int
ll read(){	ll x=0,f=1;	char ch=getchar();	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';	return x*f;	}
void write(ll x){	if (x<0)	putchar('-'),x=-x;	if (x>=10)	write(x/10);	putchar(x%10+'0');	}
void writeln(ll x){	write(x);	puts("");	}
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define rep(i,x,y)	for(ll i=x;i<y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
#define Add(x,y)	((x)=((x)+(y))%mod)
#define Mul(x,y)	((x)=((x)*(y))%mod)
#define Abs(x)		((x)<0?(-(x)):(x))
#define Fpn			freopen
#define IL			inline
IL void Max(ll &x,ll y){x=x<y?y:x;}
IL void Min(ll &x,ll y){x=x<y?x:y;}
IL ll max(ll x,ll y){return x<y?y:x;}
IL void Print(ll *a,ll x,ll y){	For(i,x,y)	write(a[i]),putchar(' ');	}
#define Min(x,y)	((x)=((x)<(y)?(x):(y)))
const ll N=2000010;
vector<ll>g[N];
ll q[N],c[N],d[N],ans[N],mark[N],dfn[N],k,dd,tim,n;
char s[N],t[N];
void dfs(ll x,ll dep){
	dfn[dep]=x;
	if (dep<=tim)	ans[dep]=x;
	else			ans[1+n-k+dfn[dep-tim]]=x;
	mark[x]=1;
	rep(i,0,g[x].size())dfs(g[x][i],dep+1);
}
void Get_P(){
	For(i,0,n){
		c[i]=d[i]=t[i]=ans[i]=dfn[i]=mark[i]=0;
		g[i].clear();
	}
	For(i,1,dd)	for(ll j=i;j<=k;j+=dd)
		c[j]=++*c;
	For(i,1,k-1)	d[i]=c[i]-1,g[d[i]].push_back(i);
	d[k]=c[k]-1;
	
	dfs(0,0);
//	For(i,1,n)write(ans[i]),putchar(' ');puts("");
	
	For(i,1,k-1)if (!mark[i]){
		*q=0;
		for(ll j=i;!mark[j];j=d[j]){
			mark[j]=1;
			q[++*q]=j;
		}
		For(j,1,*q){
			ll to=(j+tim-1)%(*q);
			if (!to)	to=*q;
			ans[n-k+c[q[to]]]=q[j]; 
		}
	}
	
//	For(i,1,n)write(ans[i]),putchar(' ');puts("");
	ll now=k,ak_lsg=0;
	For(i,0,tim-1){
		if (now==0){
			ans[n-i-k+ak_lsg]=n-i;
		}else{
			ans[n-k+c[now]]=n-i;
			now=d[now];
			if (now==0)	ak_lsg=i+1;
		}
	}
//	For(i,1,n)write(ans[i]),putchar(' ');puts("");
//	for(;;);
	For(i,1,n)	t[i]=s[ans[i]];
	For(i,1,n)	s[i]=t[i];
}
int main(){
	scanf("%s",s+1);	n=strlen(s+1);
	ll T=read();
	for(;T--;){
		k=read();dd=read();tim=n-k+1;
		Get_P();
		puts(s+1);
	}
//	printf("%lf\n",1.0*clock()/CLOCKS_PER_SEC);
}