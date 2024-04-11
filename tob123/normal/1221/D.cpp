#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 3e5+10;

int Q, N;
ll A[n], B[n];
ll dp[n][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> Q;
	while(Q--){
		cin >> N;
		A[0] = -100;
		for(int i=1; i<=N; i++){
			cin >> A[i] >> B[i];
		}
		for(int i=1; i<=N; i++){
			for(int j=0; j<3; j++){
				dp[i][j] = 1e17;
				for(int k=0; k<3; k++){
					if(A[i-1]+k != A[i]+j){
						dp[i][j] = min(dp[i][j], j*B[i] + dp[i-1][k]);
					}
				}
			}
		}
		cout << min(dp[N][0], min(dp[N][1], dp[N][2])) << "\n";
	}

  return 0;
}