#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define pb push_back
#define INF 1000000000
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second


int main() {
	
	ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (m --){
        int l,r,x;
        cin >> l >> r >> x;
        int pos = x-l;
        int cnt = 0;
        for (int i = l; i <= r; i++){
            if (i == x) continue;
            else if (a[i] < a[x]) cnt ++;
        }
        if (pos == cnt) cout << "Yes\n";
        else cout << "No\n";
    }
}