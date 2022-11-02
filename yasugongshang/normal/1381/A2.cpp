#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<int>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define mem(a) (memset(a,0,sizeof(a)))
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
const int N=100005;
char a[N],b[N];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	int T=read();
	while(T--){
		int n=read()+1;
		vector<int> ans;
		scanf("%s%s",a+1,b+1);
		int l=1,r=n,dq=1;
		Rep(i,n,1){
			int t=dq?r:l;
			if((a[t]^dq)==b[i]){
				//cout<<i<<" fjz "<<l<<" "<<r<<" "<<t<<endl;
				if(a[l+r-t]==a[t]){
					dq^=1; 
				}else{
					ans.pb(1); dq^=1;
				}
				ans.pb(i);
			}
			if(dq)r--; else l++;
		}
		wri(ans.size());
		for(auto i:ans)wri(i); 
		puts("");
	}
}
/*
10100
*/