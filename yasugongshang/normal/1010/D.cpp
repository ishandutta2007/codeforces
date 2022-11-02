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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=1000005;
int n,son[N][2],dp[N],ans[N][2];
char ch[10],op[N];
inline int chu(int x){
	if(op[x]=='N')return !dp[son[x][0]];
	else if(op[x]=='X')return dp[son[x][0]]^dp[son[x][1]];
	else if(op[x]=='A')return dp[son[x][0]]&dp[son[x][1]];
	else return dp[son[x][0]]|dp[son[x][1]];
}
void dfs(int p){
	if(op[p]=='I'){
		dp[p]=son[p][0]; return ;
	}else{
		dfs(son[p][0]); if(son[p][1])dfs(son[p][1]);
		dp[p]=chu(p);
	}
}
void solve(int p,int fa){
	if(fa){
		int t=dp[p];
		for(int i=0;i<2;i++){
			dp[p]=i; ans[p][i]=ans[fa][chu(fa)];
		}
		dp[p]=t;
	}else ans[p][1]=1;
	if(op[p]=='I'){
		return;
	}else{
		solve(son[p][0],p); if(son[p][1])solve(son[p][1],p);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		op[i]=ch[0];
		if(op[i]=='A'||op[i]=='X'||op[i]=='O'){
			son[i][0]=read(); son[i][1]=read();
		}else son[i][0]=read();
	}
	dfs(1);
	solve(1,0);
	for(int i=1;i<=n;i++)if(op[i]=='I')write(ans[i][son[i][0]^1]);
}