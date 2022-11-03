#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y)	for(ll i=(ll)x;i<=(ll)y;++i)
#define FOr(i,x,y)	for(ll i=(ll)x;i>=(ll)y;--i)
#define rep(i,x,y)	for(ll i=(ll)x;i<(ll)y;++i)
#define clr(a,v)	memset(a,v,sizeof(a))
#define cpy(a,b)	memcpy(a,b,sizeof(a))
#define fi	first
#define se	second
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
const ll N=200100;
vector<ll>ff[N];
ll a[N];
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
	}
int main(){
	ll n=read();
	ll ans=1;
//	For(i,2,200000)pri[i]=1;
//	For(i,2,200000)for(ll j=i<<1;j<=200000;j+=i)pri[j]=0;
	For(i,1,n){
		ll tmp=a[i]=read();
		for(ll j=2;j*j<=tmp;++j)if (a[i]%j==0){
			ll sum=0;
			while(a[i]%j==0)a[i]/=j,++sum;
			ff[j].push_back(sum);
		}
		if (a[i]>1)	ff[a[i]].push_back(1);
	}
	For(i,2,200000)	if (ff[i].size()>=n-1){
		if (ff[i].size()==n-1)ff[i].push_back(0);
		sort(ff[i].begin(),ff[i].end());
		For(j,1,ff[i][1])ans*=i;
	}
	cout<<ans<<endl;
}