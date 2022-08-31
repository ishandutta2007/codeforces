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
#define mod (1000*1000*1000+9)
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
#define int ll

ll bit[212345][4],ans1[4];
int gg=727999983;
int gg1=1234561;
int query(int pos){
	int i;
	rep(i,4){
		ans1[i]=0;
	}
	while(pos>0){
		rep(i,3){
			ans1[i]^=bit[pos][i];
		}
		ans1[3]+=bit[pos][3];
		pos-=pos&(-pos);
	}
	return 0;
}

int update(int pos,ll val){
	int i;
	val+=gg;
	ll val1=val*val;
	val1%=mod;
	while(pos<212345){
		bit[pos][0]^=(val+gg1);
    	bit[pos][1]^=val;
    	bit[pos][2]^=val1;
    	bit[pos][3]+=val1;
    	pos+=pos&(-pos);
	}
	return 0;
}
int boo[123456][4],gao[123456][4],fuck[123456],ans[4];
viii vec;
int solve(){
	int i,j;
	ll val;
	int sig;
	rep(i,4){
		ans[i]=0;
	}
	rep(i,vec.size()){
		val=vec[i].ss.ss;
		sig=vec[i].ss.ff;
    	if(sig==1){
    		rep(j,4){
    			boo[val][j]=ans[j];	
    		}
    	}
    	val+=gg;
    	ans[0]^=(val+gg1);
    	ans[1]^=val;
    	val*=val;
    	val%=mod;
    	ans[2]^=val;
    	ans[3]+=sig*val;
    	
    }
    int sz=vec.size();
    fd(i,sz-1,0){
    	if(vec[i].ss.ff==-1)
    		continue;
    	val=vec[i].ss.ss;
		sig=vec[i].ss.ff;
    	query(fuck[val]);
    	rep(j,3){
    		boo[val][j]^=ans1[j];	
    	}
    	boo[val][3]+=ans1[j];
    	update(vec[i].ff,val);
    }
    return 0;
}
int sa[123456],ea[123456],sb[123456],eb[123456];
map<int,int> map1,map2;
main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i,j;
    rep(i,n){
    	cin>>sa[i]>>ea[i];
    	cin>>sb[i]>>eb[i];
    	map1[sa[i]]=0;
    	map1[ea[i]]=0;
    	map2[sb[i]]=0;
    	map2[eb[i]]=0;
    }
    int counter=1;
    map<int,int>::iterator it;
    for(it=map1.begin();it!=map1.end();it++){
    	it->ss=counter++;
    }
    counter=1;
    for(it=map2.begin();it!=map2.end();it++){
    	it->ss=counter++;
    }
    
    rep(i,n){
    	sa[i]=map1[sa[i]];
    	ea[i]=map1[ea[i]];
    	vec.pb(mp(sa[i],mp(1,i)));
    	vec.pb(mp(ea[i]+1,mp(-1,i)));
    }
    sort(all(vec));
    rep(i,n){
    	fuck[i]=ea[i];
    }
    solve();
    rep(i,n){
    	rep(j,4){
    		gao[i][j]=boo[i][j];
    	}
    }
    vec.clear();
    rep(i,n){
    	sb[i]=map2[sb[i]];
    	eb[i]=map2[eb[i]];
    	vec.pb(mp(sb[i],mp(1,i)));
    	vec.pb(mp(eb[i]+1,mp(-1,i)));
    }
    sort(all(vec));
    rep(i,n){
    	fuck[i]=eb[i];
    }
    rep(i,212345){
    	rep(j,4){
    		bit[i][j]=0;
    	}
    }
    solve();
    int flag=0;
    rep(i,n){
    	rep(j,4){
    		if(gao[i][j]!=boo[i][j]){
	    		flag=1;
	    		//cout<<boo[i][j]<<endl;
	    		break;
	    	}
    	}
    	if(flag)
    		break;
    }
    if(flag){
    	cout<<"NO"<<endl;
    }
    else{
    	cout<<"YES"<<endl;
    }
    return 0;   
}