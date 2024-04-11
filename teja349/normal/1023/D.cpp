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
set<int> seti;
set<int>::iterator it;
int a[212345],b[212345],maxi[212345],mini[212345];
int main(){
    std::ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int i;
    int gg=-1,wow=0;
    rep(i,q+10){
    	mini[i]=inf;
    	maxi[i]=0;
    }
    rep(i,n){
    	cin>>a[i];
    	maxi[a[i]]=max(maxi[a[i]],i);
    	mini[a[i]]=min(i,mini[a[i]]);
    	wow=max(wow,a[i]);
    	if(a[i]==0){
    		gg=i;
    	}
    }


    if(wow!=q && gg==-1){
    	cout<<"NO"<<endl;
    	return 0;
    }
    rep(i,n){
    	if(a[i]==0){
    		if(seti.empty())
    			b[i]=1;
    		else{
    			it=seti.end();
    			it--;
    			b[i]=*it;
    		}

    		continue;

    	}
    	b[i]=a[i];
    	if(mini[a[i]]==i){
    		seti.insert(a[i]);
    	}
    	it=seti.end();
    	it--;
    	if(*it!=a[i]){
    		cout<<"NO"<<endl;
    		return 0;
    	}
    	if(maxi[a[i]]==i){
    		seti.erase(a[i]);
    	}

    }
    if(wow!=q){
    	b[gg]=q;
    }
    rep(i,n){
    	if(a[i]!=0 && a[i]!=b[i]){
    		cout<<"NO"<<endl;
    		 return 0;   
    	}
    }
    cout<<"YES"<<endl;
    rep(i,n){
    	cout<<b[i]<<" ";
    }
    cout<<endl;



    return 0;     
}