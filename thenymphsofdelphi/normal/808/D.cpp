#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
int a[N], s[N], sum = 0, n;

bool find(int l, int r, int x){
	while (l <= r){
		int mid = (l + r) / 2;
		if (s[mid] == x){
			return 1;
		}
		if (s[mid] < x){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return 0;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i]; s[i] = s[i - 1] + a[i];
	}
	if (sum % 2 == 1){
		cout << "NO";
		return 0;
	}
	sum /= 2;
	for (int i = 1; i <= n; i++){
		if (find(i + 1, n, sum + a[i])){
			cout << "YES";
			return 0;
		}
	}
	for (int i = 1; i <= n; i++){
		if (find(1, i - 1, sum - a[i])){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}