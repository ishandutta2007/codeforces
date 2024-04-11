//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : (a))
#define all(x) (x).begin(),(x).end()
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const int N = (int)1e3 + 3;

int n, s;
int a[N], b[N];
bool can[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	--s;
	F(i, 0, n)
		cin >> a[i];
	F(i, 0, n)
		cin >> b[i];
	can[0] = 1;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int i = q.front();
		q.pop();
		if(a[i])
			F(j, i + 1, n){
				if(!a[j])cont;
				if(!can[j])q.push(j);
				can[j] = 1;
			}
		if(b[i])
			F(j, 0, i){
				if(!b[j])cont;
				if(!can[j])q.push(j);
				can[j] = 1;
			}
	}
	if(can[s])cout << "YES";
	else cout << "NO";
	return 0;
}