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
const int N=100005;
int n,tong[4],dp[N];
vector<int> v[N];
void check(int p,int fa){
	for(auto i:v[p])if(i!=fa){
		check(i,p);
	}
	memset(tong,0,sizeof(tong));
	for(auto i:v[p])if(i!=fa)tong[dp[i]]++;
	if(!tong[1]&&!tong[2]&&!tong[3]&&tong[0]<=1)dp[p]=0;
	else if(!tong[1]&&!tong[2]&&!tong[3]&&tong[0]<=2)dp[p]=1;
	else if(!tong[3]&&tong[2]<=1)dp[p]=2;
	else if(!tong[3]&&tong[2]<=2)dp[p]=3;
	else{
		puts("No"); exit(0);
	}
}
void dfs(int p,int fa){
	for(auto i:v[p])if(i!=fa){
		dfs(i,p);
	}
	memset(tong,0,sizeof(tong));
	for(auto i:v[p])if(i!=fa)tong[dp[i]]++;
	if(!tong[1]&&!tong[2]&&!tong[3]&&tong[0]<=1)dp[p]=0;
	else if(!tong[1]&&!tong[2]&&!tong[3]&&tong[0]<=2)dp[p]=1;
	else if(!tong[3]&&tong[2]<=1)dp[p]=2;
	else if(!tong[3]&&tong[2]<=2)dp[p]=3;
	else{
		puts("No"); exit(0);
	}
	if(dp[p]==3){
		check(p,0); puts("Yes"); exit(0);
	}
	//cout<<p<<" wzp "<<dp[p]<<" "<<tong[0]<<" "<<tong[1]<<" "<<tong[2]<<" "<<tong[3]<<endl;
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	dfs(1,0);
	puts("Yes");
}