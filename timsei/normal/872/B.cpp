#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int a[N] , n , k;

int main(void) {
	scanf("%d%d",&n , &k);
	for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
	if(k == 1) {
		int Min = 2e9;
		for(int i = 1;i <= n;i ++) Min = min(Min , a[i]);
		cout << Min << endl;
		return 0;
	}
	else if(k == 2) {
		cout << max(a[n] , a[1]) << endl;
		return 0;
	}
	int Max = -2e9;
	for(int i = 1;i <= n;i ++) Max = max(Max , a[i]);
	cout<<Max;
}