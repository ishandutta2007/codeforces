#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
using namespace std;
int main() {
	long long q,n,i,j,k,a[333333],b[333333],dp[333333][3],ans;
	scanf("%I64d",&q);
	for (; q > 0; q--) {
		scanf("%I64d",&n);
		for (i = 0; i < n; i++)
			scanf("%I64d%I64d",&a[i],&b[i]);
		dp[n][0] = 0;
		dp[n][1] = 0;
		dp[n][2] = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < 3; j++)
				dp[i][j] = 1e18;
		for (i = n - 1; i >= 0; i--) {
			if (i == 0)
				for (j = 0; j < 3; j++)
					dp[i][0] = min(dp[i][0], b[i] * j + dp[i + 1][j]);
			else
				for (j = 0; j < 3; j++)
					for (k = 0; k < 3; k++)
						if (a[i - 1] + j != a[i] + k)
							dp[i][j] = min(dp[i][j], b[i] * k + dp[i + 1][k]);
		}
		printf("%I64d\n",dp[0][0]);
	}
}