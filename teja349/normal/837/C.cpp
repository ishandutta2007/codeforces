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
int x[1234],y[1234];
int main(){
    std::ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>a>>b;
    int i,j;
    rep(i,n){
    	cin>>x[i]>>y[i];
    }
    int flag=0;
    int ans=0;
    rep(i,n){
    	f(j,i+1,n){
    		flag=0;
    		if(x[i]+x[j]<=a){
    			if(max(y[i],y[j])<=b){
    				flag=1;
    			}
    		}
    		if(x[i]+x[j]<=b){
    			if(max(y[i],y[j])<=a){
    				flag=1;
    			}
    		}
    		if(x[i]+y[j]<=a){
    			if(max(y[i],x[j])<=b){
    				flag=1;
    			}
    		}
    		if(x[i]+y[j]<=b){
    			if(max(y[i],x[j])<=a){
    				flag=1;
    			}
    		}
    		if(y[i]+y[j]<=a){
    			if(max(x[i],x[j])<=b){
    				flag=1;
    			}
    		}
    		if(y[i]+y[j]<=b){
    			if(max(x[i],x[j])<=a){
    				flag=1;
    			}
    		}
    		if(y[i]+x[j]<=a){
    			if(max(x[i],y[j])<=b){
    				flag=1;
    			}
    		}
    		if(y[i]+x[j]<=b){
    			if(max(x[i],y[j])<=a){
    				flag=1;
    			}
    		}
    		if(flag){
    			ans=max(x[i]*y[i]+x[j]*y[j],ans);
    		}
    	}
    }
    cout<<ans<<endl;
    return 0;      

}