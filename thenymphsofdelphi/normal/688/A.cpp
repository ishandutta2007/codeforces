#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, m;
	cin >> n >> m;
	bool a[m];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < m; i++){
		string s;
		cin >> s;
		for (int j = 0; j < n; j++){
			if (s[j] == '0'){
				a[i] = true;
			}
		}
	}
	int mx = -1, t = 0;
	for (int i = 0; i < m; i++){
		if (a[i]){
			t++;
		}
		else{
			mx = max(mx, t);
			t = 0;
		}
	}
	mx = max(mx, t);
	cout << mx;
}