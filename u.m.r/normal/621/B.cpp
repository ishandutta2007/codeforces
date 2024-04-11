#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int a[MAXN][MAXN];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
	}
	long long ans = 0;
	n = 1000;
	for(int i = 2; i <= 2 * n; i++){
		long long tot = 0;
		for(int j = 1; j <= n; j++)
			if ((0 < j && j <= n && 0 < i - j && i - j <= n) && a[j][i-j])
				tot++;
		ans += tot * (tot - 1) / 2;
	}
	for(int i = 1 - n; i <= n - 1; i++){
		long long tot =0;
		for(int j = 1; j <= n; j++)
			if ((0 < j && j <= n && i + j > 0 && i + j <= n) && a[j][i + j])
				tot++;
		ans += tot * (tot - 1) / 2;
	}
	cout<<ans<<endl;
	return 0;
}