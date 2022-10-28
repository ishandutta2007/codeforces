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
	int n;cin>>n;
	int a[n];
	rep(i,n){
		cin>>a[i];
	}
	if(n%2){
		cout<<"Conan";
	}
	else{
		sort(a,a+n);
		while(n>0){
			n-=2;
			if(a[n]!=a[n+1]) cout<<"Conan",exit(0);
		}
		cout<<"Agasa";
	}
	return 0;
}