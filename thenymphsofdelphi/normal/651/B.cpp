#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second
//typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int mod = 1e9 + 7, inf = 1e18 + 7, N = 1e3 + 5;

int a[N], cnt[N], n;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(".inp", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	int sum = n, ans = 0, t;
	while (sum){
		t = 0;
		for (int i = 0; i < N; i++){
			if (cnt[i]){
				cnt[i]--;
				t++;
			}
		}
		ans += t - 1;
		sum -= t;
	}
	cout << ans;
}

/*

*/