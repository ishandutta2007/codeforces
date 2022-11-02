#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
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
const ll M=10004205361450474;
ll dp[6][10005];
ll dfs(ll x,ll y){ 
	ll yy=y>=10000?9999:y;
	if(x==5)return yy+1;
	if(dp[x][yy]!=-1)return dp[x][yy];
	ll dq=y;
	for(int i=1;i<=yy+2;i++){
		dq+=dfs(x+1,dq)+1; 
	}
	return dp[x][yy]=dq-y-1;
}
vector<ll> ans;
void print(){
	//while(ans.size()&&ans[ans.size()-1]>M)ans.pop_back();
	cout<<ans.size()<<" ";
	for(auto i:ans)cout<<i<<" "; puts(""); fflush(stdout);
}
void solve(ll x,ll y){ 
	ll yy=y>=10000?9999:y;
	if(x==5){
		ans.clear();
		for(int j=1;j<=yy+1;j++)ans.push_back(y+j);
		print();
		exit(0);
	}
	ll dq=y;
	ans.clear();
	for(int i=1;i<=yy+2;i++){
		dq+=dfs(x+1,dq)+1; 
		if(i<=yy+1)ans.push_back(dq);
	}
	print();
	int t=read();
	if(t==-1)exit(0);
	if(t==0)solve(x+1,y); else solve(x+1,ans[t-1]);
}
int main(){
	memset(dp,-1,sizeof(dp));//cout<<dfs(4,0)<<endl; return 0;
	dfs(1,0);
	solve(1,0);
}