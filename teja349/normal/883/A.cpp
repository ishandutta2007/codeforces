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
ll pass,a,n,m,d;
ll t[123456];
ll nexti (ll curtim){
	ll val1=curtim/a;
	val1++;
	return val1;
}
ll previ(ll ind){
	ll val1=t[ind]/a;

	return val1;
}
ll eval(ll curtim){

	ll val1=nexti(curtim);
	if(val1>n)
		return 0;
	ll val2=n;
	ll ans=(val2-val1+1)/pass;
		
	if(((val2-val1+1))%pass){
		ans++;

	}
	return ans;
}
ll visitor(ll curtim,ll ind){
	ll i,ans=0;
	//cout<<d<<endl;
	f(i,ind,m){
		///cout<<curtim<<" "<<t[ind]<<endl;
		if(curtim >=t[i])continue;
		curtim=t[i]+d;
		ans++;
	}

	return ans;
}
ll findcount(ll curtim,ll ind){
	ll ans=0;
	while(ind<m && t[ind]<=curtim){
		ind++;
	}

	if(ind==m){

		return eval(curtim);
	}
	ll val1=nexti(curtim);
	ll val2=previ(ind);
	if(val1>n){
		//cout<<"dads";
		return visitor(curtim,ind);
	}
	val2=min(val2,n);
	if(val1<=val2){
		ans=(val2-val1+1)/pass;
		
		if(((val2-val1+1))%pass){
			ans++;

		}
		curtim=((ans-1)*pass + val1)*a+d;


	}
	else{
		return 1+findcount(t[ind]+d,ind+1);
	}
	//cout<<val1<<" "<<val2<<endl;
	//cout<<curtim<<endl;
	return ans+findcount(curtim,ind);

}
int main(){
    std::ios::sync_with_stdio(false);
    //ll n,m,a,d;
    cin>>n>>m>>a>>d;
    pass=d/a;
    pass++;
    ll i;
    rep(i,m){
    	cin>>t[i];
    }
    sort(t,t+m);
   
   	cout<<findcount(0,0)<<endl;
    return 0;  
    
}