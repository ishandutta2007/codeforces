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
ll n,k,m;   
int valid(ll a,ll b){
	if(a>=0 && a<n && b>=0 && b<m)
		return 1;
	return 0;
}
ll check(ll a,ll b){
	//cout<<a<<" "<<b<<endl;
	if(!valid(a,b))
		return 0;
	ll val=n/(a+1);

	val*=m/(b+1);
	return val;
}
ll checkin(ll len){
	if(len>n)
		return -1;
	ll cuts=n/len;
	ll newle=n/cuts;
	if(len!=newle)
		return -1;
	cuts--;
	cuts=min(cuts,k);
	return check(cuts,k-cuts);

}

int main(){
    std::ios::sync_with_stdio(false);
   // ll n,m,k;
    cin>>n>>m>>k;
    
    if(n+m-2<k){
    	cout<<-1<<endl;
    	return 0;
    }
    ll maxi=-1,i;
    for(i=0;i*i<n+100;i++){
    	maxi=max(check(i,k-i),maxi);

    }

    for(i=(int)sqrt(n)+20;i>=1;i--){
    	
    	//if(maxi<checkin(i)){
    		maxi=max(checkin(i),maxi);

    		//lolo=i;
    	//}
    }
    cout<<maxi<<endl;
    return 0;
    
}