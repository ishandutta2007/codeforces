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
const double eps = 1e-7;
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
const ll N=1000100;
ll sum,ans,n,m,k,now,answ,c[N],b[N],a[N],dep[N];
bool cmp(ll a,ll b){return a>b;}
int main(){
//	freopen("mk.in","r",stdin);
//	freopen("g.out","w",stdout);
	n=read();	k=read()+1;
	For(i,1,n)c[i]=read();
	sort(c+1,c+n+1,cmp);
	For(i,1,n)a[i]=c[i];
	m=n;
	For(i,1,n)if (c[i]<0){
		m=i-1;	break;
	}
	For(i,1,m){
		ans+=sum;
		sum+=a[i];
	}
	if (m==n){
		cout<<ans<<endl;
		return 0;
	}
	FOr(i,n,m+1){
		dep[i]=dep[i+k]+1;
		c[i]=dep[i+k]*a[i];
		b[i]=b[i+1]+c[i];
	}answ=-1e18;
	For(i,m+1,n+1){
		answ=max(answ,ans+b[i]+sum*dep[i]);
		ans+=sum;
		sum+=a[i];
	}
	write(answ);
}