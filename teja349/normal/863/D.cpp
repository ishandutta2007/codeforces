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

//std::ios::sync_with_stdio(false);   
int a[212345],typ[212345],l[212345],r[212345],b[11212];
int main(){
    std::ios::sync_with_stdio(false);
    int n,q,m;
    cin>>n>>q>>m;
    int i,j;
    rep(i,n){
    	cin>>a[i];
    }
    rep(i,q){
    	cin>>typ[i]>>l[i]>>r[i];
    	l[i]--;
    	r[i]--;
    }
    rep(i,m){
    	cin>>b[i];
    	b[i]--;
    }
    fd(i,q-1,0){
    	if(typ[i]==1){
    		rep(j,m){
    			if(b[j]>r[i] || b[j]<l[i])
    				continue;
    			if(b[j]>l[i]){
    				b[j]=b[j]-1;
    			}
    			else{
    				b[j]=r[i];
    			}
    		}

    	}
    	else{
    		rep(j,m){
    			if(b[j]>r[i] || b[j]<l[i])
    				continue;
    			b[j]=r[i]-(b[j]-l[i]);
    		}
    	}
    }
    rep(i,m){
    	cout<<a[b[i]]<<" ";
    }
    cout<<endl;
    return 0;  
    
}