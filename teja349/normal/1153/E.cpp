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
int n;
int askquery(int x1,int y1,int x2,int y2){
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	fflush(stdout);
	int val;
	cin>>val;
	return val;
}
vii lolo;
int solverow(int id){
	int low=1;
	int high=n;
	int mid,ans,val;
	while(low<=high){
		mid=(low+high)/2;
		val=askquery(id,1,id,mid);
		if(val%2){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	lolo.pb(mp(id,ans));
	return 0;
}
int solvecol(int id){
	int low=1;
	int high=n;
	int mid,ans,val;
	while(low<=high){
		mid=(low+high)/2;
		val=askquery(1,id,mid,id);
		if(val%2){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	lolo.pb(mp(ans,id));
	return 0;
}
int printans(){
	cout<<"! "<<lolo[0].ff<<" "<<lolo[0].ss<<" "<<lolo[1].ff<<" "<<lolo[1].ss<<endl;
	fflush(stdout);
	exit(0);
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
	//int n;
	cin>>n;
	int i,val,found=0;
	f(i,1,n){
		val=askquery(1,1,i,n);
		if(val%2==1){
			if(found==0){
				solverow(i);
				found++;
			}
			
		}
		else{
			if(val%2==0){
				if(found==1){
					solverow(i);
					found++;
					break;
				}
			}
		}
	}
	if(found==1){
		solverow(n);
		found++;
	}
	if(found){
		printans();
	}
	f(i,1,n){
		val=askquery(1,1,n,i);
		if(val%2==1){
			if(found==0){
				solvecol(i);
				found++;
			}
			
		}
		else{
			if(val%2==0){
				if(found==1){
					solvecol(i);
					found++;
					break;
				}
			}
		}
	}
	if(found==1){
		solvecol(n);
		found++;
	}
	if(found){
		printans();
	}
    return 0;   
}