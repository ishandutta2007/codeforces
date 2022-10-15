#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define INF (int)0x3f3f3f3f
#define LINF (long long)0x3f3f3f3f3f3f3f3fll
 
typedef long long int int64;
typedef unsigned long long int  uint64;
 
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n, k; cin >> n >> k;
	vector <int> arr(n);

	int sum = 0;
	for (int &x : arr){
		cin >> x;
		sum += x;
	}

	if (sum%k != 0){
		cout << "No" << endl;
		exit(0);
	}

	vector <int> ans;
	int cnt = sum/k;
	//cout << cnt << endl;
	int tmp = 0, sz = 0;
	for (int i = 0; i < n; i++){
		//cout << tmp << endl;
		tmp += arr[i];
		sz++;
		if (tmp == cnt){
			ans.push_back(sz);
			sz = 0;
			tmp = 0;
		}
	}

	if (ans.size() == k){
		cout << "Yes" << endl;
		for (auto x : ans)
			cout << x << ' ';
		cout << endl;
	}else cout << "No" << endl;

	return 0;
}