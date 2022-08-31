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
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
 
using namespace std; 
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
#define int ll

int maxi = 0;
int computeans(int a,int b,int c){
	a/=2;
	b/=2;
	c/=2;
	maxi=min(maxi,(a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c));
	return 0;
}
vector<vi> vec(4);
vii gao;
signed main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int i,val;
		rep(i,3){
			vec[i].clear();
		}
		rep(i,a){
			cin>>val;
			val*=2;
			vec[0].pb(val);
		}
		rep(i,b){
			cin>>val;
			val*=2;
			vec[1].pb(val);
		}
		rep(i,c){
			cin>>val;
			val*=2;
			vec[2].pb(val);
		}
		sort(all(vec[0]));
		sort(all(vec[1]));
		sort(all(vec[2]));
		vi perm;
		perm.clear();
		perm.pb(0);
		perm.pb(1);
		perm.pb(2);
		maxi=inf;
		maxi*=maxi;
		maxi*=3;
		int lol,boo;
		while(1){
			int val1=perm[0];
			int val2=perm[1];
			int val3=perm[2];
			vector<int>::iterator it;
			vector<pii>::iterator it1;
			gao.clear();
			rep(i,vec[val3].size()){
				it=upper_bound(all(vec[val2]),vec[val3][i]);
				if(it==vec[val2].begin()){
					continue;	
				}
				it--;
				gao.pb(mp(*it,i));
			}
			rep(i,vec[val1].size()){
				it1=lower_bound(all(gao),mp(vec[val1][i],0LL));
				if(it1==gao.end())
					break;
				lol=vec[val3][it1->ss];
				boo=(lol+vec[val1][i])/2;
				it=lower_bound(all(vec[val2]),boo);
				if(it!=vec[val2].end() && *it<=lol){
					computeans(vec[val1][i],*it,lol);
				}
				if(it!=vec[val2].begin()){
					it--;
					if(*it>=vec[val1][i]){
						computeans(vec[val1][i],*it,lol);
					}
				}
			}
			if(!next_permutation(all(perm)))
				break;
		}
		cout<<maxi<<endl;
	}
}