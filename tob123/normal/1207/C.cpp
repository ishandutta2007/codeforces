#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const ll INF = 1e18;
ll T, N, a, b;
string S;
ll dp[200002][2];

int main(){
	cin >> T;
	while(T--){
		cin >> N >> a >> b;
		cin >> S;
		dp[0][0] = b;
		dp[0][1] = INF;
		for(int i=1; i<=N; i++){
			if(S[i-1] == '1'){
				dp[i][0] = INF;
				dp[i][1] = dp[i-1][1] + a + 2*b;
			}
			else{
				dp[i][0] = min(dp[i-1][0] + b + a, dp[i-1][1] + b + 2*a);
				dp[i][1] = min(dp[i-1][0] + 2*a + 2*b, dp[i-1][1] + a + 2*b);
			}
		}
		/*
		for(int i=0; i<N; i++){
			cout << dp[i][0] << " " << dp[i][1] << endl;
		}
		*/
		cout << dp[N][0] << endl;
	}

  return 0;
}