#include <iostream>
#include <algorithm>

using namespace std;

typedef long long lint;

const int MAX = 100010;

typedef pair<lint, int> pii;

int main(){
	int n, m;
	cin >> n >> m;
	lint a[MAX], b[MAX], distA[2*MAX], distB[2*MAX]; 
	pii c[2*MAX];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	int o = m + n;
	for(int i = 1; i <= o; i++) {
		if(i <= n) c[i] = make_pair(a[i], 1);
		else c[i] = make_pair(b[i - n], 2);
	}
	sort(c + 1, c + 1 + o);
	c[0] = c[1 + o] = make_pair(0LL, 0);
	distA[0] = distB[m + 1] = 0;
	for(int i = 1, k = 0; i <= o; i++) {
		distA[i] = (c[i].first - c[i - 1].first)*k + distA[i - 1];
		if(c[i].second == 1) k++;
	}
	for(int i = o, k = 0; i > 0; i--) {
		distB[i] = (c[i + 1].first - c[i].first)*k + distB[i + 1];
		if(c[i].second == 2) k++;
	}
	lint ans = -1;
	for(int i = 1 ; i <= o; i++) {
		if(ans == -1 || ans > distB[i] + distA[i]) ans = distA[i] + distB[i];
	}
	cout << ans << endl;
	return 0;
}