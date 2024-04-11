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
int n,m;
string s;
int a[50][50];
pii p[4];
bool valid(int x,int y){
	if(x<0||y<0||x>=n||y>=m||a[x][y]==1) return false;
	return true;
}
bool chk(int x,int y,int x2,int y2){
	if(x==x2&&y==y2) return true;
	trav(i,s){
		int z = i-'0';
		x = x+p[z].fst;
		y = y+p[z].snd;
		if(!valid(x,y)) return false;
		if(x==x2&&y==y2) return true;
	}
	return false;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	p[0] = mp(1,0);
	p[1] = mp(-1,0);
	p[2] = mp(0,1);
	p[3] = mp(0,-1);
	int sx,sy,dx,dy;
	rep(i,n){
		rep(j,m){
			char c;cin>>c;
			if(c=='#') a[i][j]=1;
			if(c=='S') sx=i,sy=j;
			if(c=='E') dx = i,dy=j;
		}
	}
	cin>>s;
	int ans = 0;
	rep(i,24){
		next_permutation(p,p+4);
		if(chk(sx,sy,dx,dy)) ans++;
	}
	cout<<ans;
	return 0;
}