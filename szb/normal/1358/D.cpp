#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
const int N = 400005;
ll n,x;
ll a,b,Mx;
ll sum[N],sum2[N];
ll A[N];
int main(){
//	for(ll T=read();T--;){
		n = read(); x = read();
		For(i,1,n) A[i] = read(),A[i+n] = A[i],sum[i] = (1+A[i])*A[i]/2;
		For(i,n+1,2*n) sum[i] = (1+A[i])*A[i]/2;
		For(i,1,n) sum2[i] = sum2[i-1]+sum[i];
		ll MAX1 = 0;
		For(i,1,n) MAX1 = max(MAX1,A[i]);
		if(MAX1 >= x){
			ll d = MAX1-x;
			Mx = (MAX1+d+1)*x/2;
			cout<<Mx<<endl;
			return 0;
		}
		a = 1,b = 1; ll d = x;
		ll ans =0 ;
		For(i,1,n){
			if(d >= A[i]){
				d -= A[i];
				ans += sum[i];
				++b;
			}else{
				ans += (1+d)*d/2;
				break;
			}
		}
		Mx = ans;
//		printf("%lld %lld\n",ans,d);
		For(i,1,n){
				ll ans2 = ans;
			if(d != 0){
				if(A[i] < A[b]-d){
					ans -= sum[i];
					ans -= (1+d)*d/2;
					ans += (1+d+A[i])*(d+A[i])/2;
				}else{
					ans -= (1+d)*d/2;
					ans -= (A[b]-d+1)*(A[b]-d)/2;
					ans += (1+A[b])*A[b]/2;
				}
			}
			Mx = max(Mx,ans);
//			printf("# %lld %lld\n",i,ans);
			ans = ans2;
			ans -= A[i]*(A[i]+1)/2;
			ans -= (1+d)*d/2;
			d = d+A[i];
			while(b <= 2*n){
				if(d >= A[b]){
					d -= A[b];
					ans += sum[b];
					++b;
				}else{
					ans += (1+d)*d/2;
					break;
				}					
			}
			Mx = max(Mx,ans);
//			printf("@ %lld %lld %lld\n",i,ans,d);
		}
		cout<<Mx<<endl;
//	}
}