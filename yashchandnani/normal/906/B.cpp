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
	int n,m;cin>>n>>m;
	if(n==1&&m==1) {cout<<"YES\n1";return 0;}
	if(n>=4&&m>=4){
		cout<<"YES\n";
		int r[n],c[m];
		bool st = false;
		vi x,y;
		repA(i,0,n-1){
			if(!st) x.pb(i);
			else y.pb(i);
			st=!st;
		}
		rep(i,n){
			if(!x.empty()) r[i] = x.back(),x.pop_back();
			else r[i] = y.back(),y.pop_back();
		}
		st = false;
		repA(i,1,m){
			if(!st) x.pb(i);
			else y.pb(i);
			st=!st;
		}
		rep(i,m){
			if(!x.empty()) c[i] = x.back(),x.pop_back();
			else c[i] = y.back(),y.pop_back();
		}
		rep(i,n){
			rep(j,m){
				cout<<m*r[i]+c[j]<<' ';
			}
			cout<<'\n';
		}
		return 0;
	}
	if(n==3&&m==3){
		cout<<"YES\n2 7 5\n6 1 9\n8 3 4";return 0;
	}
	bool f = false;
	if(n>m) {swap(n,m);f=true;}
	int a[n][m];
	fill(a);
	if(m<=3){cout<<"NO";return 0;}
	cout<<"YES\n";
	int st = 1;
	bool tt = false;
	rep(i,n){
		bool t = tt;
		vi x,y;
		rep(j,m){
			if(!t){
				x.pb(st);
			}
			else y.pb(st);
			st++;t=!t;
		}
		rep(j,m){
			if(!x.empty()) a[i][j] = x.back(),x.pop_back();
			else a[i][j] = y.back(),y.pop_back();
		}
		tt = !tt;
	}
	if((n==2||n==3)&&m==4){
		a[0][0]=5;a[0][1]=4;a[0][2]=7;a[0][3]=2;a[1][0]=3;a[1][1]=6;a[1][2]=1;a[1][3]=8;
	}
	else if(n==4&&m==4){
		a[0][0] = 1 ; a[0][1] = 14;a[0][2]=3;a[0][3]=16;
		a[1][0]=7;a[1][1] = 12;a[1][2]=5;a[1][3]=10;
		a[2][0]=9;a[2][1]=6;a[2][2]=11;a[2][3]=8;
		a[3][0]=15;a[3][1]=4;a[3][2]=13;a[3][3]=2;
	}
	if(n==3&&m==4){
		a[2][0]=11;a[2][1]=9;a[2][2]=12;a[2][3]=10;
	}

	if(f){
		rep(j,m){
			rep(i,n){
				int xx = (a[i][j]-1)/m,yy = (a[i][j]-1)%m;
				a[i][j] = yy*n+xx+1;
				cout<<a[i][j]<<' ';
			}cout<<'\n';
		}
	}
	else{
		rep(i,n){
			rep(j,m){
				cout<<a[i][j]<<' ';
			}
			cout<<'\n';
		}
	}


	return 0;
}