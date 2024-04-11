#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pll pair<ll, ll>
#define R(a) cin>>a;

#define forn(i, a) for(int i =0; i < a; i++)
#define mp make_pair
#define str(a) string a;cin>>a
#define print(a) cout<<a<<'\n'
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0);ios::sync_with_stdio(NULL)
ll a, b, c, n, m, k, i, j;
const int template_array_size = 1e6+20;
int ar[template_array_size];
string s;
int main() {
	fastio;
	
	cin >> n;
	while(n--) {
		cin >> m;
		if(m==1) {
			cout << 0 << '\n';
		} else if(m==2) {
			cout << 1 << '\n';
		} else if(m==3) {
			cout << 2 << '\n';
		} else if(m%2==0) {
			cout << 2 << '\n';
		} else {
			cout << 3 << '\n';
		}
	}
}