#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, a[N], cur, mx;

int main(){
	cin >> n;
	int lst = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if (lst < a[i]) cur++;
		else cur = 1;
		lst = a[i];
		mx = max(mx, cur);
	}
	cout << mx;
}