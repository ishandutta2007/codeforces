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
ll pr[1234567],a[1234567];
ll findans(ll val){
	if(pr[val]==val)
		return inf;
	ll lol=val,maxi=0;
	while(pr[val]){
		maxi=max(pr[val],maxi);
		val/=pr[val];
	}
	return lol-maxi+1;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll i,j;
    for(i=2;i<1234567;i++){
    	if(pr[i])
    		continue;
    	pr[i]=i;
    	for(j=i*i;j<1234567;j+=i){
    		if(!pr[j])
    			pr[j]=i;
    	}
    }
    ll val;
    cin>>val;
    set<ll> seti;
    ll val1=val;
    while(pr[val]!=0){
    	seti.insert(pr[val]);
    	val/=pr[val];
    }
    //cout<<val<<endl;
    set<ll>::iterator it;
    ll haha;
    for(it=seti.begin();it!=seti.end();it++){
    	val=*it;
    	haha=val1/val;
    	a[val*(haha-1)+1]++;
    	a[val*haha+1]--;
    }
    ll mini=inf;
    f(i,1,1234567){
    	a[i]+=a[i-1];
    	if(a[i]){
    		//cout<<i<<endl;
    		mini=min(mini,findans(i));
    	}
    }
    cout<<mini<<endl;
    return 0;  
    
}