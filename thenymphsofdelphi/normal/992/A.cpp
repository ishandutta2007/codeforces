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

const int mod = 1e9 + 7, inf = 1e18 + 7, N = 2e5 + 5;

int a[N], n;
bool ck[N];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(".inp", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		ck[a[i] + 100000] = 1;
	}
	int ans = 0;
	for (int i = 0; i < N; i++){
		if (ck[i] && i != 100000){
			ans++;
		}
	}
	cout << ans;
}

/*

*/