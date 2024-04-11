#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define PI pair<ll,ll>
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
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const ll inf=1e18;;
ll n,l,r,k,t;
PI jiao(PI x,PI y){
	return mp(max(x.first,y.first),min(x.second,y.second));
}
inline ll chu(ll x,ll y){
	if(y==0)return -inf;
	return x%y==0?x/y:x/y+1;
}
void solve(ll l,ll r,int id){
	ll ans=-1;
	for(ll i=n,pos,jb,L,R;i<=2*n;i=pos+1){
		jb=k/i; pos=jb?k/jb:inf;
		if(id&2){
			L=chu(k-2*t,jb); if(jb==0&&k>2*t)L=inf;
			//k-i*jb<=2*t
		}else{
			L=chu(k-t+n,jb+1);
			//k-i*jb<=t+i-n
		}
		if(id&1){
			R=(k+2*n+1-2*t)/(jb+1); //k-i*jb>=2*t-1+(i-n) k-n*jb-i*jb>=2*t-1+i-n
		}else{
			R=jb?(k-t)/jb:inf; if(jb==0&&k<t)R=-inf;
			//k-i*jb>=t
		}
		PI T=jiao(jiao(mp(l+n,r+n),mp(L,R)),mp(i,pos)); 
		//if(l<=2&&r>=2)cout<<id<<" "<<T.first<<" "<<T.second<<" "<<k-jb*n+n+1-2*t<<" "<<jb<<" "<<i<<" "<<pos<<" "<<L<<" "<<R<<" "<<l<<" "<<r<<endl;
		if(T.first<=T.second)ans=max(ans,T.second);
	}
	if(ans>=0){
		cout<<ans-n<<endl; exit(0);
	}
}
signed main(){
	n=read(); l=read(); r=read(); k=read();
	t=(r-l+n)%n+1; 
	if(t==n){
		ll ans=-1;
		for(ll i=1;i*i<=k;i++)if(k%i==0){
			if(i>=n&&i<=2*n)ans=max(ans,i-n);
			if(k/i>=n&&k/i<=2*n)ans=max(ans,k/i-n);
		}
		for(ll i=1;i*i<=k+1;i++)if((k+1)%i==0){
			if(i>n&&i<=2*n)ans=max(ans,i-n);
			if((k+1)/i>n&&(k+1)/i<=2*n)ans=max(ans,(k+1)/i-n);
		}
		cout<<ans<<endl; return 0;
	}
	if(t<=(n-(t-1))){
		solve(n-t+1,n,3);
		solve(t,n-t+1,2);
		solve(0,t,0);
	}else{
		solve(t,n,3);
		solve(n-t+1,t,1);
		solve(0,n-t+1,0);
	}
	puts("-1");
}
/*
	for(ll i=n;i>=0&&i>n-X;i--){
		ll zs=k%(n+i)?k%(n+i):n+i;// if(i==3)cout<<zs<<" "<<i-(n-(t-1))<<" "<<endl;
		if(zs>max((ll)0,i-(n-(t-1)))+t-1&&zs<=min(t,i)+t){
			cout<<i<<endl; return 0;
		}
	}
i
tk 
t<=k%(n+i)<=2*t 
t n-(t-1)
n%(k+i)=n-(k+i)*jb
k-(n+i)*jb<=2*t
(n-k*jb-2*t)/jb<=i
k-(n+i)*jb<=t+i
(n-n*jb-t)/(jb+1)<=i
n-(n+i)*jb>2*t+i-n
t+i 2*t
t 2*t+(i-n))
*/