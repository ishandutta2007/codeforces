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
ll N=5000007; 
int p[5000018];
ll ans[5000018];

int main(){
    std::ios::sync_with_stdio(false);
   // p[1]=0;
    //p[2]=1;
    ll t,l,r;
    cin>>t>>l>>r;
    ll i,j;
    
    for(i=2;i*i<=N;i++){
    	if(p[i])
            continue;
    	for(j=i*i;j<=N;j+=i){
    		
    		if(!p[j]){
                p[j]=i;
            }
    	}
    }
    //cout<<p[64]<<endl;
    for(i=2;i<=N;i++){
        if(!p[i]){
            ans[i]=i*(i-1)/2;
        }
        else{
            ans[i]=p[i]*(p[i]-1)*(i/p[i])/2 + ans[i/p[i]];
        }
    }
    //return 0;
    ll sumi=0;
    sumi%=mod;
    ll t1=1;
    f(i,l,r+1){
    	ans[i]%=mod;
    	ans[i]*=t1;
    	ans[i]%=mod;
    	sumi+=ans[i];
    	t1*=t;
    	t1%=mod;
    	sumi%=mod;
    }
    sumi%=mod;
    //cout<<ans[4]<<endl;
    cout<<sumi<<endl;

    
}