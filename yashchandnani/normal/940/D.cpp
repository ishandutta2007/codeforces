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
int mx(int a,int b,int c){
	return max(a,max(b,c));
}
int mn(int a,int b,int c){
	return min(a,min(b,c));
}
int a[100009],b[100009];
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;	
	rep(i,n) cin>>a[i];
	char c;
	rep(i,n){
		cin>>c;
		b[i] = c-'0';
	}
	int l=-1e9,r=1e9;
	repA(i,4,n-1){
		if(b[i]==1&&b[i-1]==0){
			repD(j,i,i-4){
				l = max(l,a[j]+1);
			}
		}
		else if(b[i]==0&&b[i-1]==1){
			repD(j,i,i-4){
				r=min(r,a[j]-1);
			}
		}
	}
	cout<<l<<' '<<r;
	return 0;
}