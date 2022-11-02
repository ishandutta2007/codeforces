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
const int N=1005;
map<poly,int> dp[N];
int n,x;
char ch[N];
int main(){
	#ifdef Brollan
		freopen("1.in","r",stdin);
	#endif
	scanf("%s",ch+1);
	x=read();
	n=strlen(ch+1);
	dp[1][{}]=0;
	For(i,1,n){
		dp[i+1]=dp[i];
		for(auto &j:dp[i+1])j.se++;
		int mn=1e9;
		for(auto &j:dp[i])mn=min(mn,j.se);
		for(auto j:dp[i]){
			poly v=j.fi; int t=j.se; if(x>15&&t>mn+5)continue;
			v.pb(ch[i]-'0');
			int sum=0,pos=-1,fff=0;
			Rep(j,v.size()-1,0){
				sum+=v[j];
				if(sum==x&&pos==-1)fff=1;
				if((x%sum==0||sum>=x)&&pos==-1)pos=j;
			}
			if(fff)continue;
			poly zs;
			if(sum>=x)pos=max(pos,0);
			For(j,pos+1,v.size()-1)zs.pb(v[j]);
			//cerr<<i<<" "<<t<<" "<<endl;
			if(dp[i+1].count(zs))dp[i+1][zs]=min(dp[i+1][zs],t);
			else dp[i+1][zs]=t;
		}
		dp[i].clear();
	}
	int ans=n;
	//for(auto j:dp[n+1])cerr<<j.se<<endl;
	for(auto j:dp[n+1])ans=min(ans,j.se);
	cout<<ans<<endl;
}