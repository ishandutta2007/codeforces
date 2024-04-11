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
int arr[212345],par[212345],haha[212345],mama[123456];
vector<vi> vec(212345),lol(212345);
vi ans;
int update(int val){
	int i;
	rep(i,vec[val].size()){
		if(arr[vec[val][i]]+haha[val]>=haha[vec[val][i]]){
			haha[vec[val][i]]=arr[vec[val][i]]+haha[val];
			par[vec[val][i]]=val;
		}
	}
	return 0;
}

ll gcd(ll a,ll b){
	while(b!=0){
		
		a=a%b;
		swap(a,b);
	}
	return a;
}

ll extend_gcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll x1,y1;
	ll ans =extend_gcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;

	return ans;
}
int n,m;
int compute(int ind ){
	ll val1=__gcd(ans[ind],m);
	ll val2=__gcd(ans[ind-1],m);
	ll x,y;
	extend_gcd(m/val2,ans[ind-1]/val2,x,y);
	//y*=val2;
	y%=(m/val2);
	y+=(m/val2);
	y%=(m/val2);
	 // if(ans[ind]==6){
		// cout<<ans[ind-1]/val2<<endl;
	 // }
	//y*=val2;
	//y%=val2;
	y*=ans[ind];
	y/=val1;
	y*=(val1/val2);
	y%=m;
	return y;
}
set<int> seti;
int main(){
    std::ios::sync_with_stdio(false); 
    
    cin>>n>>m;
    int i,j;
    rep(i,n){
    	cin>>j;
    	seti.insert(j);
    }
    for(i=1;i<=200010;i++){

    	for(j=2*i;j<=200010;j+=i){
    		vec[j].pb(i);
    	}
    }
   // return 0;
    f(i,1,m){
    	if(seti.find(i)!=seti.end())
    		continue;
    	int val=__gcd(i,m);
    	arr[val]++;
    	lol[val].pb(i);
    }
    fd(i,m-1,1){
    	update(i);
    }
    //return 0;
    i=1;
    int val=1;
    while(par[i]!=0){
    	rep(j,lol[i].size()){
    		ans.pb(lol[i][j]);
    	}
    	i=par[i];
    	//cout<<i<<endl;
    }
    //return 0;
    if(seti.find(0)==seti.end()){
    	 cout<<ans.size()+1<<endl;
    }
    else
    	cout<<ans.size()<<endl;
    if(!ans.empty()){
    	cout<<ans[0]<<" ";
    }
    f(i,1,ans.size()){
    	mama[i]=compute(i);
    }
    f(i,1,ans.size()){
    	cout<<mama[i]<<" ";
    }
    if(seti.find(0)==seti.end()){
    	 cout<<0<<endl;
    }



}