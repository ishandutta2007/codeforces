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
const int N=100005;
int n,a[N];
ll ans[3][N];
ll check(ll x,int id){
	ll sum=0;
	For(i,1,n){
		int l=0,r=a[i];
		while(l<r){
			int mid=(l+r)>>1; 
			if(a[i]-(ll)mid*mid*3-3*mid-1>=x)l=mid+1; else r=mid;
		}
		if(id)ans[id][i]=l;
		sum+=l;
	}//exit(0);
	return sum;
}
int main(){
	n=read(); ll k=read();
	For(i,1,n)a[i]=read(); 
	ll l=-4e18,r=1e9;
	while(l<r){
		ll mid=(l+r)>>1; mid++;
		if(check(mid,0)>=k)l=mid; else r=mid-1;
	}
	check(l,1);
	check(l+1,2);
	ll sum=0;
	For(i,1,n)sum+=ans[1][i];
	For(i,1,n)if(sum>k){
		ll t=min(ans[1][i]-ans[2][i],sum-k);
		ans[1][i]-=t;
		sum-=t;
	}
	For(i,1,n)wri(ans[1][i]);
}