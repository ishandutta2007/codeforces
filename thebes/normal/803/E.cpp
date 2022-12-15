#include <bits/stdc++.h>
using namespace std;

const int MN = 1005;
int N, K, i; char d[MN][2*MN]; string s;
bitset<2*MN> dp[MN], sol[MN];
bool solve(int n,int k){
	if(n==N&&abs(k)==K) return 1;
	else if(n==N) return 0;
	else if(abs(k)>=K) return 0;
	else if(sol[n][k+MN]) return dp[n][k+MN];
	sol[n][k+MN] = 1;
	if((s[n]=='L'||s[n]=='?')&&solve(n+1,k-1)) dp[n][k+MN]=1,d[n][k+MN]='L';
	if((s[n]=='W'||s[n]=='?')&&solve(n+1,k+1)) dp[n][k+MN]=1,d[n][k+MN]='W';
	if((s[n]=='D'||s[n]=='?')&&solve(n+1,k)) dp[n][k+MN]=1,d[n][k+MN]='D';
	return dp[n][k+MN];
}

int main(){
	cin>>N>>K>>s;
	if(!solve(0,0)) printf("NO\n");
	else{
		int tot = 0;
		for(i=0;i<N;i++){
			putchar(d[i][tot+MN]);
			if(d[i][tot+MN]=='L') tot--;
			else if(d[i][tot+MN]=='W') tot++;
		}
	}
	return 0;
}