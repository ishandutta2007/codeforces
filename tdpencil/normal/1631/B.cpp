#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int te;
	scanf("%d", &te);
	
	while(te--) {
		int n; scanf("%d", &n);
		vector<int> a(n);
		for(int &i : a) {
			scanf("%d", &i);
		}
		reverse(a.begin(), a.end());
		// observation: the first element must be the element that is chosen
		vector<int> dp(n);


		for(int i = n - 1; i; i--) {
			if(a[i] != a[0]) {
				dp[i / 2] = max(dp[i / 2], dp[i] + 1);
			}
			dp[i - 1] = max(dp[i - 1], dp[i]);
		}


		printf("%d\n", dp[0]);


	}
}