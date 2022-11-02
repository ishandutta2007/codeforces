#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int a[100][100], f[100][100];
char s[100], t[100];

int main(){
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
			a[i][j] = 0;
	for(int i = 1; i <= m; i++){
		scanf("%s%s", s, t);
		a[t[0] - 'a'][s[0] - 'a']++;
	}
	for(int i = 0; i < 6; i++)
		f[1][i] = 0;
	f[1][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 6; j++)
			if (f[i][j]){
				for(int k = 0; k < 6; k++)
					f[i+1][k] += f[i][j] * a[j][k];
			}
	}
	int ans = 0;
	for(int i = 0; i < 6; i++)
		ans += f[n][i];
	cout<<ans<<endl;
	return 0;
}