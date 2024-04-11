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
#define re resize
#define PB pop_back
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
int to[N],f[N],g[N],n;
char ch[N];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	n=read();
	scanf("%s",ch+1);
	to['0']=to['1']=n+1;
	Rep(i,n,1){
		if(ch[i]=='?')f[i]=f[i+1]+1;
		else {
			f[i]=to[ch[i]^1]-i;
			to[ch[i]]=i;
		}
	}
	mem(to);
	For(i,1,n){
		if(ch[i]=='?')g[i]=g[i-1]+1;
		else {
			g[i]=i-to[ch[i]^1];
			to[ch[i]]=i;
		}
		//wri(g[i]);
	}
	For(i,1,n){
		int dq=1,ans=0;
		while(dq+i-1<=n){
			if(g[dq+i-1]>=i){
				ans++; dq+=i;
			}else{
				dq+=i-g[dq+i-1];
			}
		}
		wri(ans);
	}
}