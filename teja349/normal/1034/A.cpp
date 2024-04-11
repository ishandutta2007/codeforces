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
//cout<<fixed<<setprecision(15)<<ans;
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

bool pr[15345688];
int a[312345],b[15345678];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j;
    rep(i,n){
    	cin>>a[i];
    }
    int gg=a[0];
    rep(i,n){
    	gg=__gcd(gg,a[i]);
    }
    rep(i,n){
    	a[i]/=gg;
    }
    rep(i,n){
    	b[a[i]]++;
    }
    int ans=0, maxi=0;
    for(i=2;i<15145678;i++){
    	if(pr[i])
    		continue;
    	ans=0;
    	for(j=i;j<=15145678;j+=i){
    		pr[j]=1;
    		ans+=b[j];
    	}
    	maxi=max(maxi,ans);
    }
    maxi=n-maxi;
    if(maxi==n)
    	maxi=-1;
    cout<<maxi<<endl;
    return 0;   
}