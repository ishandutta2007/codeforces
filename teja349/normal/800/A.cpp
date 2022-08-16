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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
double a[123456],b[123456];
  ll n;double p;
  double eps;
int check(double mid){
	double sumi=0;
	int i;
	rep(i,n){
		sumi+=max((a[i]*mid-b[i])/p,(double)0);
	}
	if(sumi<=mid || abs(sumi-mid)<eps)
		return 1;
	else
		return 0;
}
int main(){
    std::ios::sync_with_stdio(false); 
    eps=0.0000000001;
    cin>>n>>p;
    int i;
    rep(i,n){
    	cin>>a[i]>>b[i];
    	
    }
    double iinf=inf;
    iinf*=iinf;
    double low=0;
    double high=iinf;
    double mid;
    double ans=-1;
    int counter=100;
    while(counter--){

    	mid=(low+high)/2;
    	if(check(mid)){
    		//cout<<mid<<endl;
    		ans=mid;
    		low=mid;
    	}
    	else{
    		high=mid;
    	}
    }
    iinf/=10;
    if(ans>iinf){
    	cout<<-1<<endl;
    }
    else
    	cout << setprecision (8) << ans << endl;
    //cout<<check(2.)<<endl;

}