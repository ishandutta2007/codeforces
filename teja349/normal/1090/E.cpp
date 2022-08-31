//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

vii vec;
int d[8][8][8][8],arr[8][8];
pii par[8][8][8][8];
vector<pair<pii,pii> >res;

int isvalid(int x,int y){
	if(x>=8||y>=8||x<0||y<0){
		return 0;
	}
	return 1;
}
int bfs(int x,int y){
	par[x][y][x][y].ff=-1;
	par[x][y][x][y].ss=-1;
	d[x][y][x][y]=0;
	pair<pii,int>p;
	int i;
	queue<pair<pii,int> >q;
	q.push(mp(mp(x,y),0));
	while(!q.empty()){
		p=q.front();
		q.pop();
		rep(i,vec.size()){
			if(isvalid(p.ff.ff+vec[i].ff,p.ff.ss+vec[i].ss)){
				if(d[x][y][p.ff.ff+vec[i].ff][p.ff.ss+vec[i].ss]>p.ss+1){
					par[x][y][p.ff.ff+vec[i].ff][p.ff.ss+vec[i].ss].ff=p.ff.ff;
					par[x][y][p.ff.ff+vec[i].ff][p.ff.ss+vec[i].ss].ss=p.ff.ss;
					d[x][y][p.ff.ff+vec[i].ff][p.ff.ss+vec[i].ss]=p.ss+1;
					q.push(mp(mp(p.ff.ff+vec[i].ff,p.ff.ss+vec[i].ss),p.ss+1));
				}
			}
		}
	}
}
int get(int x,int y){
	int i,j,curx,cury,minn=inf,parx,pary,val;
	rep(i,8){
		rep(j,8){
			if(arr[i][j]){
				if(i>x){
					if(d[i][j][x][y]<minn){
						minn=d[i][j][x][y];
						parx=i;
						pary=j;
					}
				}
				else if(i==x&&j>y){
					if(d[i][j][x][y]<minn){
						minn=d[i][j][x][y];
						parx=i;
						pary=j;
					}
				}
			}
		}
	}

	curx=x;
	cury=y;
	vii vec1;
	//cout<<parx<<" "<<pary<<" "<<x<<" "<<y<<endl;
	//cout<<minn<<endl;
	//cout<<par[0][5][0][0].ff<<" "<<par[0][5][0][0].ss<<endl;
	while(1){
		//cout<<curx<<" "<<cury<<endl;
		if(curx==-1||cury==-1){
			break;
		}
		vec1.pb(mp(curx,cury));
		val=par[parx][pary][curx][cury].ff;
		cury=par[parx][pary][curx][cury].ss;
		curx=val;
	}
	i=0;
	j=0;
	int j1=0;

	while(j<vec1.size()){
		//cout<<arr[4][0]<<"dsa"<<endl;
		//cout<<vec1[j].ff<<" "<<vec1[j].ss<<" "<<arr[vec1[j].ff][vec1[j].ss]<<endl;
		if(arr[vec1[j].ff][vec1[j].ss]){
			//cout<<j<<endl;
			j1=j;
			while(j1>i){
				res.pb(mp(mp(vec1[j1].ff,vec1[j1].ss),mp(vec1[j1-1].ff,vec1[j1-1].ss)));
				j1--;
			}
			arr[vec1[j].ff][vec1[j].ss]=0;
			arr[vec1[i].ff][vec1[i].ss]=1;
			i=j;
		}
		j++;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int k,i,j,k1,k2;
  	string s;
  	pair<pii,pii>p;
  	cin>>k;
  	vec.pb(mp(1,2));
  	vec.pb(mp(-1,2));
  	vec.pb(mp(-1,-2));
  	vec.pb(mp(1,-2));
  	vec.pb(mp(2,1));
  	vec.pb(mp(2,-1));
  	vec.pb(mp(-2,1));
  	vec.pb(mp(-2,-1));
  	rep(i,8){
  		rep(j,8){
  			rep(k1,8){
  				rep(k2,8){
  					d[i][j][k1][k2]=inf;
  				}
  			}
  		}
  	}
  	rep(i,k){
  		cin>>s;
  		arr[s[1]-'1'][s[0]-'a']=1;
  	}
  	rep(i,8){
  		rep(j,8){
  			bfs(i,j);
  		}
  	}
  	//return 0;
  	rep(i,8){
  		rep(j,8){
  			if(!k)
  				continue;
  			k--;
  			if(arr[i][j]){
  				continue;
  			}
  			else{
  				//cout<<i<<" "<<j<<endl;
  				get(i,j);
  			}
  		}
  	}
  	//return 0;
  	cout<<res.size()<<endl;
  	rep(i,res.size()){
  		p=res[i];
  		cout<<char(p.ff.ss+'a')<<char('1'+p.ff.ff)<<"-"<<char(p.ss.ss+'a')<<char('1'+p.ss.ff)<<endl;
  	}
    return 0;   
}