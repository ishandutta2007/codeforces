#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
long long cur = 0;
int a[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
	    cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (cur <= a[i]){
		    cur += a[i];
		    ans++;
		}
	}
	cout << ans;
}