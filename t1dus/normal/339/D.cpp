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
#define F first;
#define S second;

int x,n,m;
ll a[1000000];

void update(int pos, int val){
    pos += n;
    a[pos] = val;
    int op = 0;
    pos /= 2;
    while (pos > 0){
        if (op == 0) a[pos] = (a[pos*2] | a[pos*2+1]);
        else a[pos] = (a[pos*2] ^ a[pos*2+1]);
        pos /= 2;
        op = (op+1)%2;
    }
}

int main() {
	
	ios::sync_with_stdio(false);
	cin >> x >> m;
	n = pow(2,x);
	for (int i = n; i < 2*n; i++) cin >> a[i];
	int op = 0;
	int till = (n-1)/2;
	for (int i = n-1; i > 0; i--){
	    if (i == till){
	        till /= 2;
	        op = (op+1)%2;
	    }
	    if (op == 0) a[i] = (a[i*2] | a[i*2+1]);
	    else a[i] = (a[i*2] ^ a[i*2+1]);
	}
	
	for (int i = 0; i < m; i++){
	    int p,b;
	    cin >> p >> b;
	    p --;
	    update(p,b);
	    cout << a[1] << endl;
	}
}