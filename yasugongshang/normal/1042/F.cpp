#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
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
const int N=1000005;
vector<int> v[N];
int n,dp[N],k,ans;
void dfs(int p,int fa){
	if(v[p].size()==1)return; 
	vector<int> V;
	for(auto i:v[p])if(i!=fa){
		dfs(i,p);
		V.push_back(dp[i]+1);
	}
	sort(V.begin(),V.end());
	while(V.size()>=2&&V[V.size()-1]+V[V.size()-2]>k){V.pop_back(); ans++;}
	dp[p]=V[V.size()-1];
}
int main(){
	n=read(); k=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	for(int i=1;i<=n;i++)if(v[i].size()>1){
		dfs(i,0);
		cout<<ans+1<<endl;
		return 0;
	}
}