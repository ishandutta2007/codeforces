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

const int N = 3e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

vector <int> a(N), b(N), cnta(N), cntb(N);
int n, m, suma = 0, sumb = 0, ans = 0;
int la = 0, ra = 1, lb = 0, rb = 1, idx;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	a[0] = 0; b[0] = 0;
	cnta[0] = 0; cntb[0] = 0;
	cin >> n;
	n++;
	for (int i = 1; i <= n - 1; i++){
	    cin >> a[i];
	    cnta[i] = cnta[i - 1] + a[i];
	    suma += a[i];
	}
	cin >> m;
	m++;
	for (int i = 1; i <= m - 1; i++){
	    cin >> b[i];
	    cntb[i] = cntb[i - 1] + b[i];
	    sumb += b[i];
	}
	if (suma != sumb){
	    cout << "-1";
	    return 0;
	}
	while (ra < n){
	    idx = lower_bound(cntb.begin() + lb + 1, cntb.begin() + m, cnta[ra] - cnta[la] + cntb[lb]) - cntb.begin();
	    //cout << idx << ' ' << cnta[ra] - cnta[la] + cntb[lb] << endl;
	    if (cntb[idx] == cnta[ra] - cnta[la] + cntb[lb]){
	        ans++;
	        la = ra;
	        lb = idx;
	    }
	    ra++;
	}
	cout << ans;
}

/*

*/