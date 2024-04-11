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


int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vi vec1,vec2;
    int i,j;
    int x,x1,x2;
    rep(i,n){
    	cin>>x;
    	vec1.pb(x);
    }
    vec1.pb(1e9);
    sort(all(vec1));
    vec1.resize(unique(all(vec1))-vec1.begin());
    rep(i,m){
    	cin>>x1>>x2>>x;
    	if(x1!=1)
    		continue;
    	vec2.pb(x2);
    }
    sort(all(vec2));
    j=0;
    int siz=vec2.size();
    int mini=n+m,rem;
    rep(i,vec1.size()){
    	while(j<siz && vec2[j]<vec1[i]){
    		j++;
    	}
    	rem=siz-j;
    	rem+=i;
    	mini=min(mini,rem);
    }
    cout<<mini<<endl;

    return 0;   
}