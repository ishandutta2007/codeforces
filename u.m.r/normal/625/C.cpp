#include<bits/stdc++.h>

using namespace std;

const int MAXN = 600;

int a[MAXN][MAXN];

int main(){
	int n,k;
	cin>>n>>k;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < k; j++)
			a[i][j] = ++cnt;
	for(int i = 1; i <= n; i++)
		for(int j = k; j <= n; j++)
			a[i][j] = ++cnt;
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += a[i][k];
	cout<<ans<<endl;
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= n; j++)
		printf("%d%c", a[i][j], " \n"[j== n]);
	return 0;
}