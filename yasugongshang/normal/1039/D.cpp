#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((ll)(x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
    ll x = 0; char ch = gc(); bool positive = 1;
    for (; !isdigit(ch); ch = gc())    if (ch == '-')    positive = 0;
    for (; isdigit(ch); ch = gc())    x = x * 10 + ch - '0';
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
const int N=100005;
int dp[N],n,ti,quan,an[N],ans;
vector<int> v[N];
inline void dfs(int p){
	int mx=0,mm=0;
	for(auto i:v[p]){
		if(dp[i]>mx){
			mm=mx; mx=dp[i];
		}else mm=max(mm,dp[i]);
	}
	if(mx+mm+1>=quan){
		dp[p]=0; ans++;
	}else dp[p]=mx+1;
}
int pos[N];
void solve(int l,int r,int L,int R){
	if(l>r)return;
	if(L==R){
		for(int i=l;i<=r;i++)an[i]=L;
		return;
	}
	int mid=quan=(l+r)>>1; ans=0;
	for(int i=n;i;i--)dfs(pos[i]);  an[quan]=ans; int t=ans;
	solve(mid+1,r,L,t);
	solve(l,mid-1,t,R);
}
void init(int p,int fa){
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]==fa){
		v[p].erase(v[p].begin()+i); break;
	}
	//for(auto i:v[p])cout<<i<<" "; puts("");
	pos[++ti]=p;
	for(auto i:v[p])init(i,p);
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	init(1,0);
	solve(1,n,0,n);
	for(int i=1;i<=n;i++)writeln(an[i]);
}