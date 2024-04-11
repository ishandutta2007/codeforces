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
const int N=400005;
ll sum(ll x){
	return x*(x+1)/2;
}
ll d[N],ss,ans;
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int n=read(); ll x=read();
	For(i,0,n-1)d[i]=d[i+n]=read();
	int l=0,r=0; ll s=d[0]; ss=sum(d[0]);
	while(r<2*n){
		if(s<x){
			s+=d[++r]; ss+=sum(d[r]);
		}else{
			if(s-d[l]<=x){
				ans=max(ans,ss-sum(s-x));
			}
			s-=d[l]; ss-=sum(d[l]); l++;
		}
	}
	cout<<ans<<endl;
}