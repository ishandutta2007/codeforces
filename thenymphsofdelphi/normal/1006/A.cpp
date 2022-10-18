#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push_back pb
#define pop_back pob
#define make_pair mp
#define endl "\n"

const int N = 1005, mod = 1000000007, inf = 1000000000000000000;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] % 2 == 0) a[i]--;
		cout << a[i] << " ";
	}
}