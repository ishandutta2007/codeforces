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
#define int ll


int sumi[123],gg[123],r[123];

main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		int a,b,m;
		cin>>a>>b>>m;
		if(b==a){
			cout<<"1 "<<a<<endl;
			continue;
		}
		if(b-a<=m){
			cout<<2<<" "<<a<<" "<<b<<endl;
			continue;
		}
		int left,j,mini,req;
		int i = 2,flag=0;
		while(1){
			left=b-(1LL<<(i-1))*a;
			if(left<0){
				break;
			}
			mini=(1LL<<(i-1));
			if(mini>left){
				break;
			}
			mini*=m;
			if(mini>=left){
				
				left-=(1LL<<(i-1));
				gg[0]=a;
				gg[i]=b;
				m--;
				if(left<=m){
					r[i]=left;
					left=0;
				}
				else{
					r[i]=m;
					left-=m;
				}
				req=(i-2);
				f(j,1,i){
					r[j]=left>>req;
					r[j]=min(r[j],m);
					left-=r[j]<<req;
					req--;
				}
				sumi[0]=gg[0];
				f(j,1,i+1){
					r[j]++;
					gg[j]=sumi[j-1]+r[j];
					sumi[j]=sumi[j-1]+gg[j];
				}
				cout<<i+1<<" ";
				rep(j,i+1){
					cout<<gg[j]<<" ";
				}
				cout<<endl;
				assert(gg[i]==b);
				flag=1;
				break;
			}
			assert(i<=55);
			i++;
		}
		if(!flag){
			cout<<"-1"<<endl;
		}
	}
    return 0;   
}