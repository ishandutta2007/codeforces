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
ll x[123456],y[123456];
vl vec;
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;

    if(n<3){
    	cout<<"YES"<<endl;
    	return 0;
    }
    ll i;
    rep(i,n){
    	cin>>x[i]>>y[i];
    	//x[i]=i;
    	//y[i]=i;
    }

    ll sx,sy,haha,lol,wow,flag=0;
    sy=y[1]-y[0];
    sx=x[1]-x[0];

    f(i,2,n){
    	haha=x[i]-x[0];
    	lol=y[i]-y[0];
    	if(lol*sx!=sy*haha){
    		flag=i;
    		break;
    	}
    }
    wow=flag;
    if(flag==0){
    	cout<<"YES"<<endl;
    	return 0;
    }
    f(i,1,n){
    	haha=x[i]-x[0];
    	lol=y[i]-y[0];
    	if(lol*sx!=sy*haha){
    		vec.pb(i);
    	}
    }
    if(vec.size()<3){
    	cout<<"YES"<<endl;
    	return 0;
    }
    sy=y[vec[1]]-y[vec[0]];
    sx=x[vec[1]]-x[vec[0]];
    flag=0;
    f(i,2,vec.size()){
    	haha=x[vec[i]]-x[vec[0]];
    	lol=y[vec[i]]-y[vec[0]];
    	if(lol*sx!=sy*haha){
    		flag=1;
    		break;
    	}
    }
    if(!flag){
    	cout<<"YES"<<endl;
    	return 0;
    }


    sy=y[wow]-y[0];
    sx=x[wow]-x[0];
    vec.clear();
    f(i,1,n){
    	haha=x[i]-x[0];
    	lol=y[i]-y[0];
    	if(lol*sx!=sy*haha){
    		vec.pb(i);
    	}
    }
    if(vec.size()<3){
    	cout<<"YES"<<endl;
    	return 0;
    }
    sy=y[vec[1]]-y[vec[0]];
    sx=x[vec[1]]-x[vec[0]];
    flag=0;
    f(i,2,vec.size()){
    	haha=x[vec[i]]-x[vec[0]];
    	lol=y[vec[i]]-y[vec[0]];
    	if(lol*sx!=sy*haha){
    		flag=1;
    		break;
    	}
    }
    if(!flag){
    	cout<<"YES"<<endl;
    	return 0;
    }



     sy=y[wow]-y[1];
    sx=x[wow]-x[1];
    flag=0;
    //cout<<"Dsa"<<endl;
    vec.clear();
    f(i,0,n){
    	haha=x[i]-x[1];
    	lol=y[i]-y[1];
    	if(lol*sx!=sy*haha){
    		vec.pb(i);
    	}
    }
    if(vec.size()<3){
    	cout<<"YES"<<endl;
    	return 0;
    }
    sy=y[vec[1]]-y[vec[0]];
    sx=x[vec[1]]-x[vec[0]];
    flag=0;
    f(i,2,vec.size()){
    	haha=x[vec[i]]-x[vec[0]];
    	lol=y[vec[i]]-y[vec[0]];
    	if(lol*sx!=sy*haha){
    		flag=1;
    		break;
    	}
    }
    if(!flag){
    	cout<<"YES"<<endl;
    	return 0;
    }
    cout<<"NO"<<endl;

    return 0;  
    
}