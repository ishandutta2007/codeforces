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
	string s;cin>>s;
	int a[3] = {0};
	int j = 0;
	trav(i,s){ 
		if(j==0&&i=='b') {j++;}
		else if(j==1&&i=='c') {j++;}
		else if(j==0&&i=='c') j=2;
		else if((j==1&&i=='a')||(j==2&&i!='c')) break;
		a[j]++;
	}
	if(a[0]>0&&a[1]>0&&(a[2]==a[0]||a[2]==a[1])&&(a[0]+a[1]+a[2]==sz(s))) cout<<"YES";
	else cout<<"NO";
	return 0;
}