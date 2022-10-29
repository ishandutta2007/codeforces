#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9+7;
const int N = 1e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, q, i, stk[4][251], top[4];
int dp[251][251][251], nxt[N][26], tmp[N];
char ch, s[N];

void upd(int x,int y,int z){
	dp[x][y][z] = min(y?nxt[dp[x][y-1][z]][stk[2][y]]:n+1, z?nxt[dp[x][y][z-1]][stk[3][z]]:n+1);
	dp[x][y][z] = min(dp[x][y][z], x?nxt[dp[x-1][y][z]][stk[1][x]]:n+1);
}

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d%d",&n,&q);
	scanf("%s\n",s+1);
	rep(i,0,25) tmp[i] = n+1;
	rrep(i,n+1,0){
		rep(j,0,25) nxt[i][j] = tmp[j];
		if(i<=n && i>=1) tmp[s[i]-'a'] = i;
	}
	//rep(i,0,n+1) cout<<i<<" "<<nxt[i][0]<<endl;
	while(q--){
		scanf("%c ",&ch);
		if(ch=='+'){
			scanf("%d %c\n",&i,&ch);
			stk[i][++top[i]] = ch-'a';
			int x = top[i];
			if(i==1) rep(y,0,top[2]) rep(z,0,top[3]) upd(x,y,z);
			if(i==2) rep(y,0,top[1]) rep(z,0,top[3]) upd(y,x,z);
			if(i==3) rep(y,0,top[1]) rep(z,0,top[2]) upd(y,z,x);
		}else{
			scanf("%d\n",&i);
			--top[i];
		}
		//cout<<q<<" "<<top[1]<<" "<<top[2]<<" "<<top[3]<<" "<<dp[top[1]][top[2]][top[3]]<<endl;
		//cout<<"dp[0][3][0]: "<<dp[0][3][0]<<endl;
		printf(dp[top[1]][top[2]][top[3]]<=n?"YES\n":"NO\n");
	}
	return 0;
}