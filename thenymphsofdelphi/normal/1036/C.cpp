#include<bits/stdc++.h>
using namespace std;
#define int		long long
#define double	long double
#define pb		push_back
#define pob		pop_back
#define mp		make_pair
#define fi		first
#define se		second
#define pque	priority_queue
#define endl	'\n'
typedef vector <int> 	vi;
typedef pair <int, int> ii;
typedef vector <vi > 	vvi;
typedef vector <ii > 	vii;

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int q, dig[30], dp[30][4], l, r;

int cal(int i, int j, bool ck){
	if (j > 3){
	    return 0;
	}
	if (i == 0){
	    return 1;
	}
	if (!ck && dp[i][j] != -1){
	    return dp[i][j];
	}
	int n = ((ck) ? (dig[i]) : (9)), ans = 0;
	for (int k = 0; k <= n; k++){
		bool ck2 = ((ck && k == dig[i]) ? (1) : (0));
		if (k == 0){
		    ans += cal(i - 1, j, ck2);
		}
		else{
		    ans += cal(i - 1, j + 1, ck2);
		}
	}
	if (!ck){
	    dp[i][j] = ans;
	}
	return ans;
}

int cnv(int n){
	int idx = 0;
	while (n){
	    idx++;
		dig[idx] = n % 10;
		n /= 10;
	}
	return cal(idx, 0, 1);
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> q;
	memset(dp, -1, sizeof dp);
	while (q--){
		int l, r;
		cin >> l >> r;
		cout << cnv(r) - cnv(l - 1) << endl;
	}
}