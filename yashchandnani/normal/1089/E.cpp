//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define rep(i,a) for(int i=0;i<(int)a;i++)
#define repp(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define fill(a,x) memset(a,x,sizeof(a))
#define foreach( gg, itit) for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define mp make_pair
#define pb push_back
#define all(s) s.begin(),s.end()
#define present(c,x) ((c).find(x) != (c).end())
typedef vector<int> VI;
const int mod  = 1e9+7;
const int N = 1e6+10;
const ll INF = 1e18;
#define N5 100005

#define ld long double
//#define double long double
const ld EPS=1e-12;

vector<pii> vec;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	int n;
	cin>>n;
	pii pre = mp(1,1);
	vec.pb(pre);
	int fl=0;
	if(n > 50){
		for(int i=8;i>=2;i--){
			vec.pb(mp(1,i));
			n--;
		}
		vec.pb(mp(2,2));
		n--;
		vec.pb(mp(2,1));
		n--;
		vec.pb(mp(2,3));
		n--;
		fl=1;
		pre = mp(2,3);
	}

	while(1){
		if(n == 2){
			if(pre.X == 8){
				vec.pb(mp(8,7));
				vec.pb(mp(8,8));
			}else if(pre.Y == 8){
				vec.pb(mp(7,8));
				vec.pb(mp(8,8));
			}else{
				vec.pb(mp(8,pre.Y));
				vec.pb(mp(8,8));
			}
			break;
		}
		pii nxt;
		if((pre.X+fl)%2){
			if(pre.Y < 8){
				nxt.X = pre.X;
				nxt.Y = pre.Y+1;
			}else{
				nxt.X = pre.X + 1;
				nxt.Y = pre.Y;
			}
		}else{
			if(pre.Y > 1){
				nxt.X = pre.X;
				nxt.Y = pre.Y-1;
			}else{
				nxt.X = pre.X + 1;
				nxt.Y = pre.Y;
			}
		}
		pre = nxt;
		vec.pb(pre);
		n--;
	}
	rep(i,vec.size()){
		cout<<(char)((vec[i].Y-1)+'a')<<vec[i].X<<" ";
	}
	cout<<endl;
	return 0;
}