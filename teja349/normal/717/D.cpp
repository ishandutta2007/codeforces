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

//std::ios::sync_with_stdio(false); 
double ans[150],haha[150],base[150];  
int compute(int val){

	int i,j;
	if(val==1){
		rep(i,130){
			ans[i]=base[i];
		}
		return 0;
	}
	if(val%2){
		compute(val-1);
		rep(i,128){
			rep(j,128){
				haha[i^j]+=ans[i]*base[j];
			}
		}
		rep(i,128){
			ans[i]=haha[i];
			haha[i]=0;
		}
	}
	else{
		compute(val/2);
		rep(i,128){
			rep(j,128){
				haha[i^j]+=ans[i]*ans[j];
			}
		}
		rep(i,128){
			ans[i]=haha[i];
			haha[i]=0;
		}
	}
	//cout<<val<<" "<<ans[0]<<endl;
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    int n,x;
    int i;
    cin>>n>>x;
    rep(i,x+1){
    	cin>>base[i];
    }
    compute(n);
    cout<<setprecision (14) <<1.00-ans[0]<<endl;
}