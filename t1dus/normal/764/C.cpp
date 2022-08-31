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
	int n;
	cin >> n;
	vector<ii> bzz;
	vector<ii> v;
	for (int i = 0; i < n-1; i++){
	    int x,y;
	    cin >> x >> y;
	    bzz.pb(mp(x,y));
	}
	int c[n+5];
	for (int i = 1; i <= n; i++) cin >> c[i];
	
	for (int i = 0; i < bzz.size(); i++){
	    if (c[bzz[i].first] != c[bzz[i].second]) v.pb(bzz[i]);
	}
	if (v.size() == 0){
	    cout << "YES\n" << 1;
	    return 0;
	} 
	int vert1 = v[0].first;
	int vert2 = v[0].second;
	bool verf1 = true;
	bool verf2 = true;
	for (int i = 1; i < v.size(); i++){
	    if (!(vert1 == v[i].first || vert1 == v[i].second)) verf1 = false;
	    if (!(vert2 == v[i].first || vert2 == v[i].second)) verf2 = false;
	}
	if (verf1){
	    cout << "YES\n" << vert1;
	}
	else if (verf2){
	    cout << "YES\n" << vert2;
	}
	else cout << "NO";
}