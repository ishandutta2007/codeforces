#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
const int N=1000005;
PI dp[N];
int n,k,l,a[N];
char ch[N];
PI check(int x){
	For(i,1,l)dp[i]=min(mp(a[i],0),mp(x,1));
	For(i,l+1,n){
		dp[i]=dp[i-l];
		dp[i].fi+=x; dp[i].se++;
		dp[i]=min(dp[i],mp(dp[i-1].fi+a[i]-a[i-1],dp[i-1].se));
		//cout<<dp[i].fi<<" fjz "<<dp[i].se<<" "<<i<<endl;
	}
	return dp[n];
}
int solve(){
	For(i,1,n)a[i]+=a[i-1];
	int L=0,R=l;
	//cout<<check(1).fi<<" "<<check(1).se<<endl;
	while(L<R){
		int mid=(L+R)>>1; 
		if(check(mid).se<=k)R=mid; else L=mid+1;
	}//<=k
	return (check(L).fi-L*k);
}
int main(){
	n=read(),k=read(),l=read(); 
	if((ll)k*l>n){puts("0"); return 0;}
	scanf("%s",ch+1);
	For(i,1,n)a[i]=ch[i]<='Z';
	int ans=solve();// return 0;
	For(i,1,n)a[i]=ch[i]>'Z';
	ans=min(ans,solve());
	cout<<ans<<endl;
}
/*
7 1 4
pIKmIKE

*/