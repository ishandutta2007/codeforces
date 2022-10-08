#include"bits/stdc++.h"
#define pb push_back
using namespace std;
const int N=35,M=155;
int n,T[N],dp[N][M+M][M+M][8];
bool fl[M+M][M+M]; int ans;
// 0: x+  1: x-  2: y+  3: y-
// 4: x+ y+ 5: x+ y- 6: x- y+ 7: x- y-
vector <int> e[8];
const int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int main(){
	//freopen ("d.in","r",stdin);
	scanf("%d",&n);
	e[0].pb(4); e[0].pb(5); e[4].pb(0); e[5].pb(0); e[1].pb(6); e[1].pb(7); e[6].pb(1); e[7].pb(1);
	e[2].pb(4); e[2].pb(6); e[4].pb(2); e[6].pb(2); e[3].pb(5); e[3].pb(7); e[5].pb(3); e[7].pb(3);
	for (int i=1; i<=n; i++) scanf("%d",&T[i]); for (int i=0; i<T[1]; i++) fl[M][i+M] = 1;
	dp [1][M][M+T[1]-1][2]=1;
	for (int t=1; t<=n-1; t++){
		for (int j=M-n*5; j<=M+n*5; j++){
			for (int k=M-n*5; k<=M+n*5; k++){
				for (int i=0; i<8; i++){
					if (dp[t][j][k][i]){
						for (int p=0; p<e[i].size(); p++){
							int nxt = e[i][p];
							dp[t+1][j+dir[nxt][0]*T[t+1]][k+dir[nxt][1]*T[t+1]][nxt] = 1;
							for (int q=1; q<=T[t+1]; q++) fl[j+dir[nxt][0]*q][k+dir[nxt][1]*q] |= 1;
						}
					}
				}
			}
		}
	}
	for (int j=M-n*5; j<=M+n*5; j++)
		for (int k=M-n*5; k<=M+n*5; k++)
			ans += fl[j][k];
	cout << ans << endl;
	return 0;
}