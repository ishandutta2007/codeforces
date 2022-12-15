//Submitting someone else's code so that Lockout bot knows I tested this contest

#include <bits/stdc++.h>

using namespace std;
const int N = 5e5+1;
int n,m;
int a[4][N];
int dp3[N][8];
int dp2[N][4];
bool ok3[8][8];
bool ok2[4][4];

void fill3(){
	for(int i = 0;i < 8;i++){
		for(int j = 0;j < 8;j++){
			bool bad = 0;
			for(int st = 0;st < 2;st++){
				int bits = (bool)(i&(1<<st))+(bool)(i&(1<<(st+1)));
				bits += (bool)(j&(1<<st))+(bool)(j&(1<<(st+1)));
				if(bits%2 == 0){
					bad = 1;
				}
			}
			if(!bad){
				ok3[i][j] = 1;
			}
		}
	}
}

void fill2(){
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++){
			bool bad = 0;
			for(int st = 0;st < 1;st++){
				int bits = (bool)(i&(1<<st))+(bool)(i&(1<<(st+1)));
				bits += (bool)(j&(1<<st))+(bool)(j&(1<<(st+1)));
				if(bits%2 == 0){
					bad = 1;
				}
			}
			if(!bad){
				ok2[i][j] = 1;
			}
		}
	}
}


void solve2(){
	for(int i = 1;i <= m;i++){
		int mask = a[1][i]+2*a[2][i];
		for(int cur = 0;cur < 4;cur++){
			dp2[i][cur] = 1e9;
			for(int prev = 0;prev < 4;prev++){
				if(!ok2[prev][cur])continue;
				dp2[i][cur] = min(dp2[i][cur],dp2[i-1][prev]+__builtin_popcount(cur^mask));
			}
		}
	}
	int ans = 1e9;
	for(int i = 0;i < 4;i++)ans = min(ans,dp2[m][i]);
	cout << ans;
}

void solve3(){
	for(int i = 1;i <= m;i++){
		int mask = a[1][i]+2*a[2][i]+4*a[3][i];
		for(int cur = 0;cur < 8;cur++){
			dp3[i][cur] = 1e9;
			for(int prev = 0;prev < 8;prev++){
				if(!ok3[prev][cur])continue;
				dp3[i][cur] = min(dp3[i][cur],dp3[i-1][prev]+__builtin_popcount(cur^mask));
			}
		}
	}
	int ans = 1e9;
	for(int i = 0;i < 8;i++)ans = min(ans,dp3[m][i]);
	cout << ans;
}

void solve(){
	cin >> n >> m;
	if(min(n,m) > 3){
		cout << -1;
		return;
	}
	if(min(n,m) == 1){
		cout << 0;
		return;
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			char o;cin >> o;
			a[i][j] = o-'0';
		}
	}
	if(n == 3)solve3();
	else solve2();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fill2();
	fill3();
	solve();
	return 0;
}