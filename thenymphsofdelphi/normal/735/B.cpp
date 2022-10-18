#include<bits/stdc++.h>
using namespace std;

vector <long double> a;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long double ans, s = 0, n, n1, n2;
	cin >> n >> n1 >> n2;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	if (n1 > n2){
	    swap(n1, n2);
	}
	sort(a.begin(), a.end(), greater <long long>());
	for (int i = 0; i < n1; i++){
	    s += a[i];
	}
	ans = s * 1.0 / n1;
	s = 0; 
	for (int i = n1; i < n1 + n2; i++){
		s += a[i];
	}
	ans += s * 1.0 / n2;
	cout << fixed << setprecision(6) << ans;
}