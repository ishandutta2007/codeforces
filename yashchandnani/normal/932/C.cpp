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
int ar[1000009];
void ne(int x,int y){
	int c = ar[x];
	repA(i,x,y-2){
			ar[i] = ar[i+1];
	}
	ar[y-1] = c;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n,a,b,x=0,y;cin>>n>>a>>b;
	if(a==1 || b==1) {
		rep(i,n) cout<<i+1<<' ';
		return 0;}
	int cpn = n;
	bool f = false;
	while(n>=0){
		if(n%b==0){
			f = true;
			y = n/b;
			break;
		}
		else n-=a,x++;
	}
	if(!f) cout<<-1,exit(0);
	int st = 0;
	rep(i,cpn) ar[i]=i+1;
	while(x>0||y>0){
		if(x){
			ne(st,st+a);
			st+=a;
			x--;
		}
		else {
			ne(st,st+b);
			st+=b;
			y--;
		}
	}
	rep(i,cpn) cout<<ar[i]<<' ';
	return 0;
}