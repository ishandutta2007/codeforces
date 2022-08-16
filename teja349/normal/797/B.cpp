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
vi haha,lol;
int main(){
	haha.clear();
	lol.clear();
    std::ios::sync_with_stdio(false); 
    int n;
    cin>>n;
    int i,val,ans=0;
    rep(i,n){
    	cin>>val;
    	if(val%2==0 && val>0){
    		ans+=val;
    	}
    	if(val%2!=0){
    		if(val<0){
    			haha.pb(val);
    		}
    		else{
    			lol.pb(val);
    			ans+=val;
    		}
    	}
    }
    sort(haha.begin(),haha.end());
    sort(lol.begin(),lol.end());

    val=haha.size();
    int valu=lol.size();
    if(valu%2==1){
    	cout<<ans<<endl;
    }
    else{
    	if(valu==0){
    		ans+=haha[val - 1];
    		cout<<ans<<endl;
    	}
    	else if(val==0){
    		cout<<ans-lol[0]<<endl;
    	}
    	else{
    		if(lol[0]+haha[val - 1]<0){
    			cout<<ans-lol[0]<<endl;
    		}
    		else{
    			ans+=haha[val - 1];
    			cout<<ans<<endl;
    		}
    	}
    }
}