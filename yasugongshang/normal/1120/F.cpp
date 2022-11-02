#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define PI pair<ll,ll>
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
const int N=100005;
ll t[N],p[N],dp[N],s[2][N],S[2][N];
#define fi first
#define se second
bool cha(PI a,PI b,PI c){
	return (b.se-a.se)*(c.fi-b.fi)>=(c.se-b.se)*(b.fi-a.fi);
}
ll get(PI a,ll x){
	return a.fi*x+a.se;
}
struct convex{
	int l,r;
	PI q[N];
	void push(PI x){
		while(l<r&&cha(q[r-1],q[r],x))r--;
		//for(int i=l;i<=r;i++)cout<<get(q[i],-2355)<<" "; puts("");
		q[++r]=x;  //for(int i=l;i<=r;i++)wri(get(q[i],-10)); puts("");
	}
	ll ask(ll pos){
		while(l<r&&get(q[l],pos)>=get(q[l+1],pos))l++;
		return get(q[l],pos);
	}
}q[2];
int main(){
	int n=read(); ll c=read(),d=read();
	q[0].l=q[1].l=1;
	q[0].push(mp(0,0)); q[1].push(mp(0,0));
	for(int i=1;i<=n;i++){ //cout<<i<<endl;
		t[i]=read()*c; p[i]=getchar()=='W';
		for(int j=0;j<2;j++){
			s[j][i]=s[j][i-1]; S[j][i]=S[j][i-1];
		}
		s[p[i]][i]++; S[p[i]][i]+=t[i];
		dp[i]=min(min((i-1)*d,dp[i-1]+d+t[i]-t[i-1]),q[p[i]^1].ask(-t[i])+s[p[i]^1][i]*t[i]-S[p[i]^1][i]+s[p[i]][i-1]*d);
		q[p[i]].push(mp(s[p[i]][i-1],dp[i]+S[p[i]][i-1]-s[p[i]^1][i-1]*d)); //cout<<i<<" fjzzq "<<dp[i]<<endl;
	}
	t[n+1]=read()*c;
	ll ans=dp[n]+d+t[n+1]-t[n]; 
	for(int i=0;i<2;i++)ans=min(ans,q[i].ask(-t[n+1])+s[i][n]*t[n+1]-S[i][n]+s[i^1][n]*d);
	cout<<min(n*d,ans)<<endl;
}