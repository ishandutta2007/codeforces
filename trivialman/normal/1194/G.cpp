#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int P = 998244353;
const int N = 110;
 
int n,x,y,a[N];
int dp[N][20][20][20][2];
string s;
 
int dfs(int cur,int pre,int mask1,int mask2,bool tie){
	if(cur>n) return pre==0 && (mask1&mask2);
	int &res = dp[cur][pre+9][mask1][mask2][tie];
	if(res>=0) return res;
	res = 0;
	int up = tie ? a[cur] : 9;
	//find (a,b), s.t. ax-by=0, a<input, a and b contain corresponding numbers
	rep(i,0,up)rep(j,0,9){
		int now = pre*10 - i*x + j*y, m1=0, m2=0;
		if(now<=-y || now>=x) continue;
		if(i && i%y==0) m1 = 1<<(i/y-1);
		if(j && j%x==0 && j/x*y<=9) m2 = 1<<(j/x-1);
		res = (res + dfs(cur+1, now, mask1|m1, mask2|m2, tie&&i==up)) % P;
	}
	return res;
}
 
int main(){
	cin>>s;
	n = s.size();
	rep(i,1,n) a[i] = s[i-1] - 48;
	int ans = 0;
	rep(i,1,n) ans = (ans*10ll+a[i]) % P;
	for(x=1;x<=8;++x)for(y=x+1;y<=9;++y)if(__gcd(x,y)==1){
		memset(dp,-1,sizeof dp);
		ans = (ans + dfs(1, 0, 0, 0, true) * 2ll) % P;
	}
	cout<<ans<<endl;
	return 0; 
}