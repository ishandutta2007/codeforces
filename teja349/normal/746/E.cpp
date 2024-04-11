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
int a[212345];
vi trash,mam,mama;
set<int> seti;
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    vi::iterator it;
    cin>>n>>m;
    int i,eve=0,odd=0,ans=0;
    rep(i,n){
    	cin>>a[i];
    	if(seti.count(a[i])){
    		trash.pb(i);
    	}
    	else{
    		seti.insert(a[i]);
    		if(a[i]%2==0){
    			mam.pb(i);
    			eve++;
    		}
    		else{
    			mama.pb(i);
    			odd++;
    		}
    	}
    }
    ans=trash.size();
    int haha=2;
    int lol=1;
    while(!trash.empty()){
    	it=trash.end();
    	it--;
    	if(eve<odd){
    		while(seti.count(haha)){
    			haha+=2;
    		}
    		if(haha>m){
    			cout<<-1<<endl;
    			return 0;
    		}
    		a[*it]=haha;
    		haha+=2;
    		eve++;
    	}
    	else{
    		while(seti.count(lol)){
    			lol+=2;
    		}
    		if(lol>m){
    			cout<<-1<<endl;
    			return 0;
    		}
    		a[*it]=lol;
    		lol+=2;
    		odd++;
    	}
    	trash.erase(it);
    }
    if(eve==odd){
    	cout<<ans<<endl;
    	rep(i,n){
    		cout<<a[i]<<" ";
    	}
    	return 0;
    }
    if(eve<odd){
    	i=0;
    	while(eve!=odd){
    		while(seti.count(haha)){
    			haha+=2;
    		}
    		if(haha>m){
    			cout<<-1<<endl;
    			return 0;
    		}
    		a[mama[i]]=haha;
    		haha+=2;
    		eve++;
    		odd--;
    		i++;
    		ans++;
    	}


    }
    else{
    	i=0;
    	while(eve!=odd){
    		while(seti.count(lol)){
    			lol+=2;
    		}
    		if(lol>m){
    			cout<<-1<<endl;
    			return 0;
    		}
    		a[mam[i]]=lol;
    		lol+=2;
    		odd++;
    		eve--;
    		i++;
    		ans++;
    	}
    }
    cout<<ans<<endl;
    rep(i,n){
    	cout<<a[i]<<" ";
    }

    
}