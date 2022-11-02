#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
ll rnd(){
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans%((ull)1<<63);
}
const int N=4000005;
const ll inf=8e18;
int a[N];
ll mn[2];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		int n=read();
		For(i,1,n)a[i*2-1]=a[i*2-1+n*2]=read();
		For(i,1,n)a[i*2]=a[i*2+n*2]=-read();
		n*=4;
		ll ans=0,sum=0;
		mn[0]=mn[1]=1e18; mn[0]=0;
		For(i,1,n){
			sum+=a[i];
			mn[i%2]=min(mn[i%2],sum);
			if(i%2==0)ans=max(ans,sum-mn[1-i%2]);
			//cout<<i<<" "<<sum<<" "<<a[i]<<" "<<ans<<endl;
		}
		if(ans>0||sum>0)puts("NO"); else puts("YES");
	}
}