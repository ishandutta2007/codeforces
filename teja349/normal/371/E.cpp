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
ll a[412345],pre[312345];
map<int,int> inv;
int main(){
    std::ios::sync_with_stdio(false);
    int n,i,k;
    ll ans,sumi=0,maxi;
    cin>>n;
    rep(i,n){
    	cin>>a[i];
    	inv[a[i]]=i;
    }
    cin>>k;
    sort(a,a+n);
    pre[0]=a[0];
    f(i,1,n){
    	pre[i]=pre[i-1]+a[i];
    }
    rep(i,k){
    	sumi+=pre[k-1]-pre[i] -(k-1-i)*a[i];
    	sumi+=(i+1)*a[i]-pre[i];
    }
    ans=0;
    maxi=sumi;
    f(i,1,n-k+1){
    	sumi-=pre[i+k-2]-pre[i-1]-(k-1)*a[i-1];
    	sumi+=k*a[i+k-1]-pre[i+k-1]+pre[i-1];
    	if(sumi<maxi){
    		sumi=maxi;
    		ans=i;
    	}
    }
    //return 0;
    rep(i,k){
    	cout<<inv[a[ans+i]]+1<<" ";
    }
    return 0;      

}