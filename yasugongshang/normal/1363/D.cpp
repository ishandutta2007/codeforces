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
const int N=1005;
vector<int> v[N];
int po,mx,n,k,to[N];
int ask(vector<int> jb){
	if(!jb.size())return -1;
	cout<<"? "; cout<<jb.size()<<" ";
	for(auto i:jb)cout<<i<<" "; cout<<endl;
	return read();
}
int ask(int l,int r){
	vector<int> jb;
	For(i,l,r)for(auto j:v[i])jb.pb(j);
	return ask(jb);
}
void solve(int l,int r){
	if(l==r){
		po=l; return;
	}
	int mid=(l+r)>>1;
	if(ask(l,mid)==mx)solve(l,mid); else solve(mid+1,r);
}
int main(){
	#ifdef Brollan
		//freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		n=read(),k=read();
		mem(to);
		For(i,1,k){
			v[i].clear(); int c=read(); 
			while(c--){
				int t=read(); to[t]=1; v[i].pb(t);
			}
		}
		v[0].clear(); For(i,1,n)if(!to[i])v[0].pb(i);
		mx=ask(0,k);
		solve(0,k);
		vector<int> jb;
		For(i,0,k)if(i!=po){
			for(auto j:v[i])jb.pb(j);
		}
		int j=ask(jb);
		cout<<"! ";
		For(i,1,k)wri(i==po?j:mx); cout<<endl;
	}
}