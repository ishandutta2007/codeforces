#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define int long long
using namespace std;
const int N = 100005;

int a[N], cnt[N];
bool ck[N];
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x;
	cin >> n >> m;
	memset(ck, 0, sizeof(ck));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = n - 1; i >= 0; i--){
		cnt[i] = cnt[i + 1];
		if (!ck[a[i]]){
			cnt[i]++;
			ck[a[i]] = 1;
		}
	}
	while (m--){
		cin >> x;
		x--;
		cout << cnt[x] << endl;
	}
}