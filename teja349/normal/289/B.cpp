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
vi vec;
int a[123][123];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m,d,i,j,haha=-1;
    cin>>n>>m>>d;
    rep(i,n){
    	rep(j,m){
    		cin>>a[i][j];
    		if(haha==-1){
    			haha=a[i][j]%d;

    		}
    		else{
    			if(haha!=a[i][j]%d){
    				cout<<-1<<endl;
    				return 0;
    			}
    		}
    		vec.pb(a[i][j]);
    	}
    }
    sort(vec.begin(),vec.end());
    int elem=vec[vec.size()/2];
    haha=0;
    rep(i,vec.size()){
    	haha+=abs(vec[i]-elem);
    }
    cout<<haha/d<<endl;
    return 0;
}