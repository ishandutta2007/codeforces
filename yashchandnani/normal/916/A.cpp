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
bool chk(int h,int m){
	if(m%10==7||h%10==7) return true;
	return false;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,c =0;cin>>n;
	string h,m;cin>>h>>m;
	int mm = stoi(m),hh = stoi(h);
	while(!chk(hh,mm)){
		mm-=n;
		if(mm<0) mm = 60+mm,hh--;
		if(hh<0) hh+=24;
		c++;
	}
	cout<<c;
	return 0;
}