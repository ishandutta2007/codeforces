#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second

const int N = 1000 + 5, mod = 1e9 + 7, inf = 1e8 + 7;

string a, b;
int dp[N][N], la, lb;

void print(){
	while (la != 0 || lb != 0){
		if (a[la - 1] == b[lb - 1] && la > 0 && lb > 0){
			la--;
			lb--;
		}
		else{
			if (dp[la][lb] == dp[la - 1][lb - 1] + 1 && la > 0 && lb > 0){
				cout << "REPLACE " << la << ' ' << b[lb - 1] << endl;
				la--;
				lb--;
			}
			else{
				if (dp[la][lb] == dp[la][lb - 1] + 1 && lb > 0){
					cout << "INSERT " << la + 1 << ' ' << b[lb - 1] << endl;
					lb--;
				}
				else{
					cout << "DELETE " << la << endl;
					la--;
				}
			}
		}
	}
	return;
}

signed main(){
	cin >> a >> b;
	la = a.length();
	lb = b.length();
	for (int i = 1; i <= la; i++){
		dp[i][0] = i;
	}
	for (int i = 1; i <= lb; i++){
		dp[0][i] = i;
	}
	for (int i = 1; i <= la; i++){
		for (int j = 1; j <= lb; j++){
			if (a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
			}
		}
	}
	cout << dp[la][lb] << endl;
	print();
}