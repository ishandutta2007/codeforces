#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 56; 

int n; 
int a[maxn][maxn], s[maxn][maxn]; 
int f[maxn][maxn][maxn][maxn]; 
bool v[maxn][maxn][maxn][maxn]; 

bool check(int x1, int y1, int x2, int y2) {
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1] == 0; 
}

int dfs(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) return 0; 
	if (check(x1,y1,x2,y2)) return 0; 
	//cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl; 
	if (f[x1][y1][x2][y2] != -1) 
		return f[x1][y1][x2][y2]; 
	int ans = max(x2-x1+1,y2-y1+1);
	if (x2-x1 > y2-y1) {
		for (int i = x1; i <= x2; ++i) 
			if (check(i,y1,i,y2))
				ans = min(ans, dfs(x1,y1,i-1,y2)+dfs(i+1,y1,x2,y2)); 
	}
	else {
		for (int j = y1; j <= y2; ++j) 
			if (check(x1,j,x2,j))
				ans = min(ans, dfs(x1,y1,x2,j-1)+dfs(x1,j+1,x2,y2));
	}
	f[x1][y1][x2][y2] = ans; 
	return ans;  
}

int main() {
	ios::sync_with_stdio(false); 
	cin>>n; 
	for (int i = 1; i <= n; ++i) {
		string S; 
		cin>>S; 
		for (int j = 1; j <= n; ++j) 
			a[i][j] = (S[j-1]=='#'); 
	}
	memset(s, 0, sizeof(s)); 
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= n; ++j) 
			s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j]; 
	for (int i = 0; i <= n+1; ++i) 
	for (int j = 0; j <= n+1; ++j) 
	for (int k = 0; k <= n+1; ++k) 
	for (int l = 0; l <= n+1; ++l)
		f[i][j][k][l] = -1;
	cout<<dfs(1,1,n,n)<<endl; 
}