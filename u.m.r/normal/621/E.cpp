#include<bits/stdc++.h>

using namespace std;

const int MM = 1e9 + 7;

long long a[111][111], c[111][111], dp[111][111];
int cnt[111];

int main(){
	int n, B, K, X;
	cin>>n>>B>>K>>X;
	for(int i = 1; i <=n; i++){
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	for(int i = 0; i < X; i++)
		for(int j = 0; j < 10; j++)
			a[(i * 10 + j) % X][i] += cnt[j];
	for(int i = 0; i < X; i++)
		for(int j = 0; j < X; j++)
			dp[i][j] = a[i][j];
	B--;
	for(; B; B >>= 1){
		if (B & 1){
			for(int i = 0; i < X; i++)
				for(int j = 0; j < X; j++)
					c[i][j] = 0;
			for(int k = 0; k < X; k++)
				for(int i = 0; i < X; i++)
					for(int j = 0; j < X; j++)
						c[i][j] += dp[i][k] * a[k][j] % MM;
			for(int i = 0; i < X; i++)
				for(int j = 0; j < X; j++)
					dp[i][j] = c[i][j] % MM;
		}
		for(int i = 0; i < X; i++)
			for(int j = 0; j < X; j++)
				c[i][j] = 0;
		for(int k = 0; k < X; k++)
			for(int i = 0; i < X; i++)
				for(int j = 0; j < X; j++)
					c[i][j] += a[i][k] * a[k][j] % MM;
		for(int i = 0; i < X; i++)
			for(int j = 0; j < X; j++)
				a[i][j] = c[i][j] % MM;
	}
	cout<<dp[K][0]<<endl;
	return 0;
}