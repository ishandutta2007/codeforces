#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;
int a[N], n, m, k;
string b[N];

string cnv(int x){
	int dig = 1;
	string ans = "";
	for (int i = 0; i < n; i++){
		if (x % (dig * 2) == dig){
			ans = '1' + ans;
			x -= dig;
		}
		else{
			ans = '0' + ans;
		}
		dig *= 2;
	}
	return ans;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i <= m; i++){
		cin >> a[i];
		b[i] = cnv(a[i]);
	}
	int cnt, ans = 0;
	for (int i = 0; i < m; i++){
		cnt = 0;
		for (int j = 0; j < b[i].length(); j++){
			if (b[i][j] != b[m][j]){
				cnt++;
			}
		}
		if (cnt <= k){
			ans++;
		}
	}
	cout << ans;
}