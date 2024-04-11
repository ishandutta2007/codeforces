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

#define ld long double
ld x[123456],y[123456],l[123456],r[123456];
int n;
int check(ld mid){
	int i;
	ld val,haha,maxi,mini;
	rep(i,n){
		if(y[i]>2*mid)
			return 0;
		val=abs(y[i]-mid);
		haha=sqrt(mid+val);
		ld zee=0;
		haha*=sqrt(max(zee,mid-val));
		l[i]=x[i]-haha;
		r[i]=x[i]+haha;
		if(i){
			mini=min(mini,r[i]);
			maxi=max(maxi,l[i]);
		}
		else{
			mini=r[i];
			maxi=l[i];
		}
		
	}
	if(maxi<mini)
		return 1;
	return 0;


}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>n;
    int i;
    int cnt1=0,cnt2=0;
    rep(i,n){
    	cin>>x[i]>>y[i];
    	if(y[i]<0)
    		cnt1++;
    	else
    		cnt2++;
    }
    if(cnt1*cnt2){
    	cout<<-1<<endl;
    	return 0;
    }
    rep(i,n){
    	y[i]=abs(y[i]);
    }
    ld high=inf;
    high*=inf;
    high/=10;
    ld mid,low=0;
    int iter=0;

    while(iter<100){
    	mid=(low+high)/2;
    	if(check(mid)){
    		high=mid;
    	}
    	else{
    		low=mid;
    	}
    	iter++;
    }
    cout<<setprecision(30)<<mid<<endl;

    return 0;   
}