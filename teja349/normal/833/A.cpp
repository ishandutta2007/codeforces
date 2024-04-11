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
set<ll> seti;
int main(){
    //std::ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    ll i;
    rep(i,1234){
    	seti.insert(i*i*i);
    }
    while(n--){
    	int aa,ba;
    	ll a1,b1;
    	ll flag=0;
    	scanf("%d %d",&aa,&ba);
    	ll a=aa;
    	ll b=ba;
    	ll val=__gcd(a,b);
    	//ll val1=a/val;
    	a1=a/val;
    	b1=b/val;
    	if(a%(a1*a1)==0){
    		a/=(a1*a1);
    		if(a%b1==0){
    			a/=b1;
    		}
    		else{
    			flag=1;
    		}
    		if(seti.find(a)==seti.end()){
    			flag=1;
    		}
    	}
    	else{
    		flag=1;
    	}
    	a=b;
    	swap(a1,b1);
    	if(a%(a1*a1)==0){
    		a/=(a1*a1);
    		if(a%b1==0){
    			a/=b1;
    		}
    		else{
    			flag=1;
    		}
    		if(seti.find(a)==seti.end()){
    			flag=1;
    		}
    	}
    	else{
    		flag=1;
    	}
    	if(flag){
    		printf("NO\n");
    	}
    	else{
    		printf("YES\n");
    	}

    }
    return 0;

    return 0;      

}