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
const int N=500005;
int h[N],n;
ll f[N],g[N],ans;
map<int,int> M;
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read();
	int top=0;
	For(i,1,n){
		h[i]=read(); 
		f[i]=f[i-1]+h[i];
		M[h[i]]++;
		while(1){
			auto it=M.upper_bound(h[i]);
			if(it==M.end())break;
			M[h[i]]+=it->second;
			f[i]-=(ll)(it->first-h[i])*it->second;
			M.erase(it);
		}
	}
	M.clear();
	Rep(i,n,1){
		g[i]=g[i+1]+h[i];
		M[h[i]]++;
		while(1){
			auto it=M.upper_bound(h[i]);
			if(it==M.end())break;
			M[h[i]]+=it->second;
			g[i]-=(ll)(it->first-h[i])*it->second;
			M.erase(it);
		}
	}
	ans=-1e18;
	For(i,1,n)ans=max(ans,f[i]+g[i]-h[i]);
	//cout<<ans<<" "<<f[1]<<" "<<g[1]<<endl;
	For(i,1,n)if(f[i]+g[i]-h[i]==ans){
		Rep(j,i-1,1)h[j]=min(h[j+1],h[j]);
		For(j,i+1,n)h[j]=min(h[j-1],h[j]);
		For(j,1,n)wri(h[j]); puts(""); return 0;
	}
}