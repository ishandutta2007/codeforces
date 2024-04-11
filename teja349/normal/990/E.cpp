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
ll wow[1234567],haha[1234567],a[1234567];

int main(){
    std::ios::sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m>>k;
    ll i,j,val;
    rep(i,m){
    	cin>>val;
    	wow[val]=1;
    }
    wow[n]=1;

   	f(i,1,k+1){
   		cin>>a[i];
   	}
   	if(wow[0]){
   		cout<<-1<<endl;
   		return 0;
   	}
   	ll flag=0;
   	ll ans=0;

   	f(i,1,n+2){
   		if(wow[i])
   			haha[i]=ans;
   		else{
   			ans=i;
   			haha[i]=i;
   		}
   		//cout<<haha[i]<<endl;
   	}
   	ll iinf=inf;
   	iinf*=inf;
   	ll mini=iinf;
   	f(i,1,k+1){
   		j=0;
   		flag=0;
   		ll cnt=0;
   		ll dd;
   		while(j<n){
   			dd=haha[j];
   			dd+=i;
   			if(dd<=j){
   				//cout<<j<<" "<<dd<<endl;
   				flag=1;
   				break;
   			}
   			j=dd;
   			cnt++;  

   		}

   		if(flag==0)
   			mini=min(mini,cnt*a[i]);
   	}
   	if(mini!=iinf){
   		cout<<mini<<endl;
   	}
   	else{
   		cout<<-1<<endl;
   	}
    return 0;  
    
}