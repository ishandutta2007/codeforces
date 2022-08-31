#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define pb push_back
#define INF 100000000
#define mp make_pair

int main() {
	
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int a[n][m];
	int b[n][m];
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < m; j++){
	        cin >> a[i][j];
	    }
	}
	for (int i = 0; i < n; i++){
	    for (int j = 0; j < m; j++){
	        if (i == 0) b[i][j] = 0;
	        else{
	            if (a[i-1][j] <= a[i][j]) b[i][j] = 1;
	            else b[i][j] = 0;
	        }
	    }
	}
	int d[n];
	for (int i = 0; i < n; i++) d[i] = i;
	
	int l,r;
	
	for (int j = 0; j < m; j++){
	    bool c = false;
	    for (int i = 0; i < n; i++){
	        if (b[i][j] == 0){
	            if (c) d[l] = max(d[l],r);
	            l = i;
	            r = i;
	        }    
	        else{
	            c = true;
	            r += 1;
	        }
	    }
	    d[l] = max(d[l],r);
	}
	for (int i = 1; i < n; i++) d[i] = max(d[i],d[i-1]);
	int k;
	cin >> k;
	for (int i = 0; i < k; i++){
	    cin >> l >> r;
	    l --;
	    r --;
	    if (d[l] >= r) cout << "Yes\n";
	    else cout << "No\n";
	}
}