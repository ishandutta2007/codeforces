#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 2000; 

int a[maxn][5]; 
int n; 

bool check(int x, int y, int z) {
	ll ret = 0; 
	for (int i = 0; i < 5; ++i) 
		ret += (a[y][i]-a[x][i]) * (a[z][i]-a[x][i]); 
	
	//ll u = 0; 
	//for (int i = 0; i < 5; ++i) 
		//u += (a[y][i]-a[x][i]) * (a[y][i]-a[x][i]); 
	//ll v = 0; 
	//for (int i = 0; i < 5; ++i) 
		//v += (a[z][i]-a[x][i]) * (a[z][i]-a[x][i]); 
		
	return ret > 0; 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) 
		for (int j = 0; j < 5; ++j) 
			scanf( "%d", &a[i][j] ); 
			
	if (n > 100) {
		puts( "0" ); 
		return 0; 
	}
			
	vi ans; 
	
	for (int i = 1; i <= n; ++i) {
		bool flag = true; 
		for (int j = 1; j <= n; ++j) 
			if (i != j) 
				for (int k = 1; k <= n; ++k) 
					if (i != j && j != k) {
						if (check(i,j,k)) flag = false;
					}
		if (flag) ans.pb(i); 
	}
	cout<<ans.size()<<endl; 
	for (auto i : ans) cout<<i<<endl; 
	return 0;
}