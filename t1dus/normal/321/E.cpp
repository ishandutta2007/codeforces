/*input
3 2
0 2 0
2 0 3
0 3 0

*/		
#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)

int n,k;
int a[4005][4005],pref[4005][4005],b[4005][4005],dp[4005][2];

// dp[i][j] = min[ dp[k-1][j-1]+b[k][i] ] :::: k -> {1,i}

inline int scan(){
    char c = getchar();
    int x = 0;
    while(c<'0'||c>'9'){
            c=getchar();
        }
    while(c>='0'&&c<='9'){
            x=(x<<1)+(x<<3)+c-'0';
            c=getchar();
        }
    return x;
}

void solve(int l,int r,int bl,int br,int j){
	if(r < l) return;
	int m = (l+r)/2,k = m,val = dp[k-1][(j-1)&1]+b[k][k];
	for(int i = min(br,m-1); i >= bl; i--){
		int lol = dp[i-1][(j-1)&1]+b[i][m];
		if(lol < val){
			val = lol;
			k = i;
		}
	}
	dp[m][j&1] = val;
	solve(l,m-1,bl,k,j);
	solve(m+1,r,k,br,j);
}

signed main(){
	// cin >> n >> k;
	n = scan();
	k = scan();
	FOR(i,1,n+1) FOR(j,1,n+1) a[i][j] = scan();
	FOR(i,1,n+1){
		FOR(j,1,n+1){
			pref[i][j] = a[i][j]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
		}
	}
	FOR(i,1,n+1){
		FOR(j,i,n+1){
			b[i][j] = pref[j][j]+pref[i-1][i-1]-pref[i-1][j]-pref[j][i-1];
		}
	}
	dp[0][1] = 0;
	FOR(i,1,n+1) dp[i][1] = b[1][i];
	FOR(j,2,k+1){
		solve(1,n,1,n,j);
	}
	printf("%d\n",dp[n][k&1]/2);
}