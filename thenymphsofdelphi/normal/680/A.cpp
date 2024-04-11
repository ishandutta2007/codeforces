#include<bits/stdc++.h>
using namespace std;

int main(){
	int t[5];
	for (int i = 0; i < 5; i++){
		cin >> t[i];
	}
	sort(t, t + 5);
	int ans = 0;
	for (int i = 0; i < 5; i++){
		if (i + 1 < 5 && t[i] == t[i + 1]){
			ans = max(ans, 2 * t[i]);
		}
		if (i + 2 < 5 && t[i] == t[i + 2]){
			ans = max(ans, 3 * t[i]);
		}
	}
	printf("%d", t[0] + t[1] + t[2] + t[3] + t[4] - ans);
}