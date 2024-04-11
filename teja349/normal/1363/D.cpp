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

int maxi;
int getmax(int n){
	cout<<"? "<<n<<endl;
	int i;
	rep(i,n){
		cout<<i+1<<" ";
	}
	cout<<endl;
	int val;
	cin>>maxi;
	int lo=1;
	int high=n,mid;
	while(lo<high){
		mid=(lo+high)/2;
		cout<<"? "<<mid-lo+1<<endl;
		f(i,lo,mid+1){
			cout<<i<<" ";
		}
		cout<<endl;
		cin>>val;
		if(val==maxi){
			high=mid;
		}
		else{
			lo=mid+1;
		}
	}
	return lo;

}
int gao[1234],val[1234],ans[1234];
vector<vi> vec(1234);
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n,k;
    	cin>>n>>k;
    	int i,j;
    	rep(i,k){
    		int siz;
    		cin>>siz;
    		vec[i].clear();
    		int boo;
    		rep(j,siz){
    			cin>>boo;
    			vec[i].pb(boo);
    		}
    	}
    	int posi=getmax(n);
    	rep(i,k){
    		int flag=0;
    		int siz=vec[i].size();
    		rep(j,siz){
    			val[j]=vec[i][j];
    			if(val[j]==posi)
    				flag=1;
    		}
    		if(flag==0){
    			ans[i]=maxi;
    		}
    		else{
    			cout<<"? "<<n-siz<<endl;
    			rep(j,n+10){
    				gao[j]=0;
    			}
    			rep(j,siz){
    				gao[val[j]]=1;
    			}
    			f(j,1,n+1){
    				if(gao[j]==0){
    					cout<<j<<" ";
    				}
    			}
    			cout<<endl;
    			int lolo;
    			cin>>lolo;
    			ans[i]=lolo;
    		}
    	}
    	cout<<"! ";
    	rep(i,k){
    		cout<<ans[i]<<" ";
    	}
    	cout<<endl;
    	string s;
    	cin>>s;
    	assert(s=="Correct");
    }
    return 0;   
}