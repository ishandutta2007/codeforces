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
ll n,a[N],ans;
int main(){
	n=read();	ans=1e7;
	For(i,1,n)a[i]=read();
	For(i,2,n){
		ll res1=0,res2;
		FOr(j,i-1,max(1ll,i-64)){
			res1^=a[j];
			res2=0;
			For(k,i,min(n,i+64)){
				res2^=a[k];
				if (res1>res2){
					ans=min(ans,k-j);
				}
			}
		}
	}
	if (ans==1e7)	cout<<-1<<endl;
	else			cout<<ans-1<<endl;
}