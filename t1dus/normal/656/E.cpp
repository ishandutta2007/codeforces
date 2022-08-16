#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

#def\
ine loop fo\
r


int main() {
	
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[101][101];
	loop (int i = 0; i < n; i++){
	    loop (int j = 0; j < n; j++){
	        cin >> a[i][j];
	    }
	}
	int ans = 0;
	loop (int k = 0; k < n; k++){
	    loop (int i = 0; i < n; i++){
	        loop (int j = 0; j < n; j++){
	            a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
	        }
	    }
	} 
	loop (int i = 0; i < n; i++){
	    loop (int j = 0; j < n; j++){
	        ans = max(ans,a[i][j]);
	    }
	}
	cout << ans << endl;
}