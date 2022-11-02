#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define LL long long
#define st first
#define nd second
#define endl '\n'
using namespace std;

const int MAXN = 1000005;
int pr[MAXN], t, ans[MAXN], x;
LL tx;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	ans[1] = 1;
	for(int i = 2; i < MAXN; ++i)
		if(!pr[i]) {
			for(int j = i + i; j < MAXN; j += i)
				pr[j] = 1;
		}
	for(int i = 2; i < MAXN; ++i) {
		ans[i] += ans[i - 1];
		if(!pr[i]) {
			//cout << i << endl;
			++ans[i];
			tx = i;
			tx *= i;
			if(tx < MAXN) --ans[tx];
		}
	}	
	while(t--) {
		cin >> x;
		cout << ans[x] << endl;
	}
	
}