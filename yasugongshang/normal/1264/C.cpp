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
const int N=200005,M=N<<2,mod=998244353;
struct data{
	ll a,b,c;
};
data tr[M];
ll p[N];
set<int> s;
int n,q,vis[N];
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
data operator +(data a,data b){//cout<<a.c<<" "<<b.c<<" "<<a.b<<endl;
	return (data){(a.a+a.b*b.a)%mod,a.b*b.b%mod,(a.c+b.c*a.b)%mod};
}
data ask(int l,int r,int i,int j,int nod){
	if(l==i&&r==j)return tr[nod];
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,nod<<1); 
	else if(i>mid)return ask(mid+1,r,i,j,nod<<1|1);
	else return ask(l,mid,i,mid,nod<<1)+ask(mid+1,r,mid+1,j,nod<<1|1);
}
void build(int l,int r,int nod){
	if(l==r){
		tr[nod].a=mod+1-p[l]; tr[nod].b=p[l]; tr[nod].c=1; return;
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	tr[nod]=tr[nod<<1]+tr[nod<<1|1];
}
ll solve(int l,int r){
	r--; //cout<<l<<" "<<r<<endl;
	data t=ask(1,n,l,r,1);  //cout<<t.a<<" "<<t.b<<" "<<t.c<<endl;
	return (t.c)*ksm(mod+1-t.a,mod-2)%mod;
}
int main(){
	n=read(),q=read();
	ll inv=ksm(100,mod-2);
	For(i,1,n)p[i]=read()*inv%mod;
	build(1,n,1);
	s.insert(1); s.insert(n+1);
	ll ans=solve(1,n+1);  //cout<<solve(1,2)<<" "<<solve(2,3)<< " fjzq "<<solve(1,3)<<endl;
	while(q--){
		int x=read();
		auto it=vis[x]?s.find(x):s.insert(x).fi,l=it,r=it;
		l--; r++;
		if(vis[x]){
			ans=(ans+solve(*l,*r)-solve(*l,*it)-solve(*it,*r)+2*mod)%mod;
			s.erase(it);
		}else{
			ans=(ans-solve(*l,*r)+solve(*l,*it)+solve(*it,*r)+mod)%mod;
		}
		vis[x]^=1;
		writeln((ans)%mod);
	}
	
}