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
#define lld long double
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
#define int ll
// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int x[1234567],y[1234567];
pii line[1234567];
vector< vector< pair<lld , int > > > vec(1234567);
lld getdist(int i){
	return sqrt(x[i]*x[i] + y[i]*y[i]);
}
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int i,j;
    int zero=-1;
    map<pii,int> mapi;
    int cnt=0;
    int xx,yy,gg;
    rep(i,n){
    	cin>>x[i]>>y[i];
    	if(x[i]==0 && y[i]==0){
    		zero=i;
    		continue;
    	}
    	if(y[i]==0){
    		if(x[i]>0)
    			line[i]=mp(1,0);
    		else
    			line[i]=mp(-1,0);		
    	}
    	else if(x[i]==0){
    		if(y[i]>0){
    			line[i]=mp(0,1);
    		}
    		else
    			line[i]=mp(0,-1);
    	}
    	else{
    		xx=abs(x[i]);
    		yy=abs(y[i]);
    		gg=__gcd(xx,yy);
    		line[i]=mp(x[i]/gg,y[i]/gg);
    	}
    	if(mapi.find(line[i])==mapi.end()){
    		mapi[line[i]]=cnt++;
    	}
    	//cout<<getdist(i)<<endl;
    	vec[mapi[line[i]]].pb(mp(getdist(i),i));
    }
    vector< pair< lld, int > > lol;
    lol.pb(mp(0.0,zero));
    //cout<<cnt<<endl;
    rep(i,cnt){
    	sort(all(vec[i]));
    	int siz=vec[i].size();
    	int boo=1;
    	fd(j,siz-1,0){
    		if(k-boo<0)
    			break;
    		lol.pb(mp((k-boo)*vec[i][j].ff,vec[i][j].ss));
    		//cout<<j<<" "<<(k-boo)*vec[i][j].ff<<endl;
    		boo+=2;
    	}
    	lld sumi=0;
    	lld pre=0;
    	int ii;
    	rep(ii,j+1){
    		lol.pb(mp((k-boo)*vec[i][ii].ff-sumi,vec[i][ii].ss));
    		sumi+=2.0*vec[i][ii].ff;
    	}
    	//sort(all(lol));
    }
    sort(all(lol));
    int siz=n-1;
    lld answ=0;
    rep(i,k){
    	//cout<<lol[siz-i].ff<<endl;
    	answ+=lol[siz-i].ff;
    }
    cout<<setprecision(30)<<answ<<endl;


    return 0;   
}