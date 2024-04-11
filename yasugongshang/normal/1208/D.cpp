#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
const int N=200005;
ll c[N],s[N];
int n,ans[N];
#define lowbit(i) i&-i
ll get(int pos){
	ll ans=0;
	for(int i=pos;i;i-=lowbit(i))ans+=c[i];
	return ans;
}
void upd(int pos){
	for(int i=pos;i<=n;i+=lowbit(i))c[i]+=pos;
}
int main(){
	n=read();
	For(i,1,n)s[i]=read();
	Rep(i,n,1){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)>>1; mid++;
			if(s[i]+get(mid-1)>=(ll)mid*(mid-1)/2)l=mid; else r=mid-1;
			//cout<<s[i]<<" "<<get(mid-1)<<" "<<l<<" "<<r<<endl;
		}
		upd(l);
		ans[i]=l;
	}
	For(i,1,n)wri(ans[i]);
}