#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
const int N=2005;
bitset<N> s[N];
int n,m;
vector<int> v[N];
signed main(){
	int T=read();
	while(T--){
		n=read(); m=read();
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=m;i++){
			int s=read(),t=read();
			v[s].push_back(t); v[t].push_back(s);
		}
		int ans=1;
		for(int i=1;i<=n;i++)if(v[i].size()&1)ans=2;
		writeln(ans);
		if(ans==1){for(int i=1;i<=n;i++)wri(1); puts(""); continue;}
		for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)s[i][j]=0;
		for(int i=1;i<=n;i++){
			for(auto j:v[i])s[i][j]=s[i][j]^1; if(v[i].size()&1){s[i][i]=s[i][i]^1; s[i][0]=1;}
		}
		//for(int i=1;i<=n;i++){for(int j=0;j<=n;j++)wri(s[i][j]); puts("");} puts("");
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)if(s[j][i]){
				swap(s[j],s[i]); break;
			}
			for(int j=1;j<=n;j++)if(i!=j&&s[j][i])s[j]^=s[i];
		}
		for(int i=1;i<=n;i++)wri(s[i][0]+1); puts("");
	}
}