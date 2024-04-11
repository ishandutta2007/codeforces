#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int a[19] = {2,3,5,7,4,9,25,49,11,13,17,19,23,29,31,37,41,43,47};
	vi v(a,a+19);
	int cnt =0;
	rep(i,19){
		cout<<v[i]<<endl;
		string s;cin>>s;
		if(s=="yes") cnt++;
	}
	if(cnt<2) cout<<"prime"<<endl;
	else cout<<"composite"<<endl;
	return 0;
}