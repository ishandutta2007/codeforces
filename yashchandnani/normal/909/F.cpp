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
vi ans[100009];
void pri(int x,int y){
	repD(i,y,x) cout<<i<<' ';
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;
	int m=0;
	ans[n+1].pb(-1);
	while(1<<m<=n+1) m++;
	repD(i,n,1){
		if(i%2){
			rep(j,m+1){
				int s = (1<<j)-1-i;
				if(s>i&&s<=n&&sz(ans[s+1])>0) ans[i].pb(s);
			}
		}
	}
	if(sz(ans[1])>0) {
		cout<<"YES\n";
		int st = 1;
		while(st<=n){
			int	en = ans[st][0];
			pri(st,en);
			st = en+1;
		}
		cout<<'\n';
	}
	else{
		cout<<"NO\n";
	}
	if(n<6||n==(1<<(m-1))){
		cout<<"NO\n";
	}
	else if(n==6){
		cout<<"YES\n3 6 1 5 4 2\n";
	}
	else{
		cout<<"YES\n3 6 1 5 4 7 2 ";
		repA(i,8,n){
			int st =i,en = min(n,2*i-1);
			cout<<en<<' ';
			repA(i,st,en-1) cout<<i<<' ';
			i = en;
		}
		cout<<endl;
	}
	return 0;
}