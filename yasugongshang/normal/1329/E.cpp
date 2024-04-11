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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=400005;
ll n,k,p[N],a[N];
PI q[N];
int m;
ll checks(ll x){
	ll sum=0;
	For(i,0,m)sum+=(a[i]+x-1)/x;
	return sum<=k;
}
ll checkx(ll x){
	ll sum=0;
	For(i,0,m)sum+=a[i]/x;
	return sum>=k;
}
int main(){
	int T=read();
	while(T--){
		n=read(); m=read(); k=read()+m+1;
		For(i,1,m)p[i]=read(); 
		For(i,0,m)a[i]=p[i+1]-p[i];
		a[m]=n-p[m];
		ll l=1,r=1e15;
		while(l<r){
			ll mid=(l+r)>>1;
			if(checks(mid))r=mid; else l=mid+1;
		}
		ll U=l;
		l=1; r=1e15;
		while(l<r){
			ll mid=(l+r)>>1; mid++;
			if(checkx(mid))l=mid; else r=mid-1;
		}
		ll D=l;
		int tot=0;
		//cout<<D<<" "<<U<<endl;
		For(i,0,m){
			ll d=a[i]/D; 
			if(d==0)q[++tot]=mp(a[i],1e18);
			else if((a[i]+d-1)/d>U){
				q[++tot]=mp(a[i]/(d+1),(a[i]+d-1)/d);
			}
		}
		q[++tot]=mp(D,1e18);
		//cout<<U<<" "<<D<<endl;
		sort(q+1,q+tot+1);
		ll dq=U,ans=1e18;
		For(i,1,tot){
		//	cout<<q[i].fi<<" "<<dq<<" "<<q[i].se<<endl;
			ans=min(ans,dq-q[i].fi);
			
			dq=max(dq,q[i].se);
		}
		cout<<ans<<endl;
	}
}
/*
D<=a[i]/x
1
152 4 14
19 77 85 118 

*/