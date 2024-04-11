#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pob pop_back
#define mp make_pair
#define bd(a) a.begin(), a.end()
#define fi first
#define se second
#define endl '\n'
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <ii > vii;

const int mod = 1e9 + 7, N = 2e5 + 5, inf = 1e18 + 5;

int a[N], b[N];
int n, mx, f, ans;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
	    cin >> a[i];
	}
	cin >> mx >> f;
	for (int i = 0; i < n; i++){
	    b[i] = a[i] - mx;
	    if (b[i] > 0){
	        ans += ceil(1.0 * b[i] / (f + mx));
	    }
	}
	cout << f * ans;
}