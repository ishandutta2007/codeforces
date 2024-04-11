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
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

#define int ll
int a[412345];
int diff[412345];
int s[412345],t[412345];
int lcp[412345],pos[412345];
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    ll n,m;
    cin>>n>>m;

    int i,j;
    rep(i,n){
    	cin>>a[i];
    }
    if(n==1){
    	cout<<1<<endl;
    	cout<<(a[0]+a[0])%m<<endl;
    	return 0;
    }
    rep(i,n){
    	diff[i]=a[(i+1)%n]-a[i];
    	diff[i]%=m;
    	diff[i]+=m;
    	diff[i]%=m;
    }
    rep(i,2*n){
    	s[i]=diff[i%n];
    }
    rep(i,n-1){
    	t[n-2-i]=diff[i];
    }
    int tlen=n-1;
    int slen=2*n;
    i=1;
    j=0;
    lcp[0]=0;
    while(i<tlen){
    	if(t[i]==t[j]){
    		lcp[i]=j+1;
    		j++;
    		i++;
    	}
    	else{
    		if(j==0){
    			lcp[i]=0;
    			i++;
    		}
    		else{
    			j=lcp[j-1];
    		}
    	}
    }
    i=0;
    j=0;
    while(i<slen){
    	if(s[i]==t[j]){
    		i++;
    		j++;
    	}
    	else{
    		if(j==0){
    			i++;
    		}
    		else{
    			j=lcp[j-1];
    		}
    	}
    	if(j==tlen){
    		pos[i-1]=1;
    		j=lcp[j-1];
    	}
    }
    int cnt=0;
    f(i,n-1,2*n-1){
    	if(pos[i]==1){
    		cnt++;
    	}
    }
    cout<<cnt<<endl;
    vl vec;
    f(i,n-1,2*n-1){
    	if(pos[i]){
    		vec.pb((a[i+1-n]+a[0])%m);
    	}
    }
    sort(all(vec));
    rep(i,vec.size()){
    	cout<<vec[i]<<" ";
    }


    return 0;   
}