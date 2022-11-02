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
	ull ans=0;
	For(i,0,4)ans=ans<<15^rand();
	return ans;
}
const int N=200005,M=1000005;
const ll inf=1e18;
ll mn=inf;
int n,q[M];
ll a[N];
bitset<M> vis,heshu;
void solve(ll t){
	if(t<=1)return;
	if(t<M){
		if(vis[t])return;
		vis[t]=1;
	}
	ll ans=0;
	For(i,1,n){
		ll k=a[i]%t; 
		ans+=min(k==a[i]?inf:k,t-k);
		if(ans>=mn)return;
	}
	mn=min(mn,ans);
}
void check(ll t){
	for(int i=1;(ll)q[i]*q[i]<=t;i++)if(t%q[i]==0){
		while(t%q[i]==0)t/=q[i];
		solve(q[i]);
	}
	if(t>1)solve(t);
}
int main(){
	double ttt=clock();
	srand(time(0));
	For(i,2,M-1){
		if(!heshu[i])q[++*q]=i;
		for(int j=1;j<=*q&&i*q[j]<M;j++){
			heshu[i*q[j]]=1;
			if(i%q[j]==0)break;
		}
	}q[*q+1]=1e9;
	n=read();
	For(i,1,n)a[i]=read();
	For(i,1,n)swap(a[rnd()%i+1],a[i]);
	For(i,1,n){
		check(a[i]);
		check(a[i]+1);
		check(a[i]-1);
		if((clock()-ttt)/CLOCKS_PER_SEC>2)break;
	}
	cout<<mn<<endl;
}
/*
5
9 8 7 3 1

*/