#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
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
const int N=105;
int n,tt,dp[N][N*3],mid[N],l[N],r[N],q[N*3];
PI a[N];
int get(int x){
	return lower_bound(q+1,q+tt+1,x)-q;
}
int solve(int i,int L){
	if(dp[i][L]!=-1)return dp[i][L];
	int ans=0,dq=L;
	Rep(j,i-1,1){
		ans=max(ans,solve(j,min(dq,mid[j]))+q[min(L,r[j])]-q[min(dq,mid[j])]);
		ans=max(ans,solve(j,min(dq,l[j]))+q[min(L,mid[j])]-q[min(dq,l[j])]);
		dq=min(dq,l[j]);
		//if(i==2&&j==1&&q[L]==1)cout<<dq<<" "<<q[r[j]]<<endl;
	}
	//cout<<ans<<" "<<i<<" "<<q[L]<<" "<<L<<endl;
	return dp[i][L]=ans;
}
int main(){
	n=read();
	For(i,1,n){
		a[i].fi=read(); a[i].se=read();
		q[++tt]=a[i].fi-a[i].se;
		q[++tt]=a[i].fi;
		q[++tt]=a[i].fi+a[i].se;
	}
	sort(q+1,q+tt+1);
	tt=unique(q+1,q+tt+1)-q-1;
	sort(a+1,a+n+1);
	For(i,1,n){
		mid[i]=get(a[i].fi);
		l[i]=get(a[i].fi-a[i].se);
		r[i]=get(a[i].fi+a[i].se);
	}
	memset(dp,-1,sizeof(dp)); 
	cout<<solve(n+1,tt)<<endl;
}