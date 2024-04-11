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

#define int ll
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    ll a,b;
    cin>>a>>b;
    //int a,b;
    ll tot=a+b;
    ll i,j;
    f(i,0,123456){
    	if(i*(i+1)/2>tot)
    		break;
    }
    i--;
    //cout<<i<<endl;
    if(i*(i+1)/2<=a){
    	cout<<i<<endl;
    	f(j,1,i+1){
    		cout<<j<<" ";
    	}
    	cout<<endl;
    	cout<<0<<endl;
    	return 0;
    }
    else{
    	set<int> set1;
    	set<int>::iterator it;
    	
    	f(j,1,i+1){
    		set1.insert(j);
    	}

    	f(j,1,i+1){
    		if(j*(j+1)/2>a){
    			break;
    		}
    		else{
    			set1.erase(j);
    		}
    		
    	}
    	j--;
    		//return 0;
    		cout<<j<<endl;
    		int left=a-j*(j+1)/2;
    		int lol=j;
    		if(left!=0){
    			set1.erase(j+1);
    			set1.insert(j+1-left);
    		}
    		f(j,1,i+1){
    			if(set1.find(j)==set1.end()){
    				cout<<j<<" ";
    			}
    		}
    		cout<<endl;
    		cout<<i-lol<<endl;
    		for(it=set1.begin();it!=set1.end();it++){
    			cout<<*it<<" ";
    		}
    		cout<<endl;
    	
    }
    return 0;   
}