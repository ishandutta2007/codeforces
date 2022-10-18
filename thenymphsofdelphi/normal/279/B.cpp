#include<bits/stdc++.h>
using namespace std;

int n, t, a[100005], ans, l, sum;

int main(){
	cin >> n >> t;
	l = 1;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
		while (sum > t){
			sum -= a[l++];
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
}