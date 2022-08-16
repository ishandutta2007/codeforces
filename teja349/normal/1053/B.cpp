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
#define int ll
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}



ll a[312345];
ll pre[312345],cnt[312345][2];
ll findbits(ll val){
	int ans=0;
	while(val>0){
		if(val%2)
			ans++;
		val/=2;
	}
	return ans;
}
signed main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j;
    rep(i,n){
    	cin>>a[i];
    }
    rep(i,n){
    	a[i]=findbits(a[i]);
    	if(i==0)
    		pre[i]=a[i];
    	else
    		pre[i]=pre[i-1]+a[i];
    	pre[i]%=2;
    	
    }
    fd(i,n-1,0){
    	cnt[i][0]=cnt[i+1][0];
    	cnt[i][1]=cnt[i+1][1];
    	cnt[i][pre[i]]++;
    }

    int sumi,maxi,ans=0,val;
    rep(i,n){
    	sumi=0;
    	maxi=0;
    	rep(j,68){
    		if(i+j<n){
    			sumi+=a[i+j];
    			maxi=max(maxi,a[i+j]);
    		}
    		else{
    			break;
    		}
    		if(sumi%2==0 && maxi*2<=sumi){
    			ans++;
    		}	
    	}
    	if(i==0){
    		val=0;
    	}
    	else{
    		val=pre[i-1];
    	}
    	if(i+68<n){
    		ans+=cnt[i+68][val];
    	}
    }
    cout<<ans<<endl;
    return 0;   
}