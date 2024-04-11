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
int f(int x){
	int ans=1;
	while(x){
		int y = x%10;
		if(y) ans*=y;
		x/=10;
	}
	return ans;
}
int g(int x){
	if(x<10) return x;
	else return g(f(x));
}
int cal[1000009][10];
void pre(){
	repA(i,1,1000000){
		rep(j,10) cal[i][j]=cal[i-1][j];
		int y = g(i);
		cal[i][y]++;
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int q;cin>>q;
	rep(i,q){
		int l,r,k;cin>>l>>r>>k;
		cout<<cal[r][k]-cal[l-1][k]<<'\n';
	}
	return 0;
}