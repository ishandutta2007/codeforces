#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int MAXN = 1e5 + 10;

int s, b;
pii a[MAXN];
pii bases[MAXN];
ll ans[MAXN];

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> s >> b;
	for(int i=0; i<s; i++) cin >> a[i].x, a[i].y=i;
	for(int i=0; i<b; i++) cin >> bases[i].x >> bases[i].y;

	sort(bases, bases+b);
	sort(a, a+s);
	
	ll cuind = 0, cug = 0;
	for(int i=0; i<s; i++){
		while(cuind < b && a[i].x >= bases[cuind].x){
			cug += bases[cuind].y;
			cuind++;
		}
		ans[a[i].y] = cug;
	}

	for(int i=0; i<s; i++) cout << ans[i] << " ";
}