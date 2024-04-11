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
ll b[1234567],a[1234567];
int main(){
    std::ios::sync_with_stdio(false);
    ll n, i;
    cin>>n;
    ll maxi=0;
    rep(i,n){
    	cin>>b[i];
    	
    	maxi=max(maxi,b[i]);
    }
    if(maxi==0){
    	cout<<"YES"<<endl;
    	rep(i,n){
    		cout<<1<<" ";
    	}
    	return 0;
    }
    ll flag=0;
    rep(i,n){
    	if(b[i]!=maxi){
    		flag=1;
    		break;
    	}
    }
    if(flag==0){
    	cout<<"NO"<<endl;
    	return 0;
    }
    cout<<"YES"<<endl;
    flag=i;
    rep(i,n){
    	if(b[(i+flag)%n]==maxi){
    		break;
    	}
    }
    ll cur,val=0;
    ll first=1;
    cur=(i+flag)%n;
    fd(i,cur,0){
    	if(first==1 && i!=cur){
    		if(b[i]==0){
    			b[i]=b[cur];
    		}
    		first=0;
    	}
    	val+=b[i];
    	a[i]=val;
    }
    fd(i,n-1,cur+1){
    	if(first==1 && i!=cur){
    		if(b[i]==0){
    			b[i]=b[cur];
    		}
    		first=0;
    	}
    	val+=b[i];
    	a[i]=val;
    }
    rep(i,n){
    	cout<<a[i]<<" ";
    }


    return 0;   
}