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
const int N=1000005;
const ll inf=8e18;
ll jb;
int main(){
	#ifdef Brollan
		//freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		int n=read(),k=read();
		if((n-k*(k+1)/2)%(k+1)==0){
			int t=n-k*(k+1)/2; if(t<0)jb=inf; else {
			t/=(k+1);
			vector<int> v; 
			for(int i=t,j=0;i;i-=min((j?9:9-k),i),j++)v.pb(min((j?9:9-k),i));
			reverse(v.begin(),v.end());
			jb=0;
			for(auto i:v)jb=jb*10+i;	
			}
		}else jb=inf;
		For(i,10-k,9){// 
			For(j,1,17){// 
				int sum=n;
				For(o,0,9-i)sum-=j*9-o;
				For(o,0,k-(9-i+1))sum-=o+1;
				if(sum%(k+1)||sum<0)continue;
				ll ans=0;
				sum/=(k+1);
				sum++;
				ans=sum%9;
				For(o,1,sum/9)ans=ans*10+9;
				ans--;
				For(o,1,j-1)ans=ans*10+9;
				ans=ans*10+i;
				jb=min(jb,ans);
				//t,t+1,...,t+9-i,t+9
			}
		}
		writeln(jb>=inf?-1:jb);
	}
}