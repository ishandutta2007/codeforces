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
vector<vll> vec(123456);
ll maxh[123456],sth[123456],regen[123456];
struct total{
	ll tim,heal,enem;
};
total foo[123456];
vll fool;
bool cmp(total a,total b){
	return a.tim<b.tim;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    ll bounty,inc,dam;
    cin>>bounty>>inc>>dam;
    ll i,j,ans=0,maxi,val;
    ll ans11=0;
    rep(i,n){
    	cin>>maxh[i]>>sth[i]>>regen[i];
    	
    	ans++;
    	ans11++;
    	if(regen[i]==0){
    		if(sth[i]>dam){
    			vec[i].pb(mp(0,-1));
    		}
    		continue;
    	}
    	if(sth[i]>dam){
    		ans11--;
    	}
    	if(maxh[i]>dam){
    		val=(dam+1-sth[i]+regen[i]-1)/regen[i];
    		if(sth[i]>dam)
    			val=0;
    		vec[i].pb(mp(val,-1));
    	}
    }
    rep(i,m){
    	cin>>foo[i].tim>>foo[i].enem>>foo[i].heal;
    	foo[i].enem--;    	
    }
    sort(foo,foo+m,cmp);
    vll::iterator it;
    ll anss;
    pll papa;
    rep(i,m){
    	j=foo[i].enem;
    	if(regen[j]==0){
    		if(sth[j]>dam && foo[i].heal<=dam){
    			vec[j].pb(mp(foo[i].tim,1));
    		}
    		else if(sth[j]<=dam && foo[i].heal>dam){
    			vec[j].pb(mp(foo[i].tim,-1));
    		}
    		sth[j]=foo[i].heal;
    		continue;
    	}
    	while(!vec[j].empty()){
    		papa=vec[j][(int)vec[j].size()-1];
    		it=vec[j].end();
    		it--;
    		if(papa.ff>=foo[i].tim){
    			vec[j].erase(it);
    		}
    		else{
    			break;
    		}
    	}
    	anss=1;
    	if(!vec[j].empty()){
    		papa=vec[j][vec[j].size()-1];
    		anss=papa.ss;
    	}
    	if(foo[i].heal<=dam){
    		if(anss==-1){
    			vec[j].pb(mp(foo[i].tim,1));
    		}
    		if(maxh[j]>dam){
	    		val=(dam+1-foo[i].heal+regen[j]-1)/regen[j];
	    		//cout<<val<<" "<<j<<endl;
	    		vec[j].pb(mp(val+foo[i].tim,-1));
	    	}
    	}
    	else{
    		if(anss==1){
    			vec[j].pb(mp(foo[i].tim,-1));
    		}
    	}
    }
    rep(i,n){
    	rep(j,vec[i].size()){
    		fool.pb(vec[i][j]);
    	}
    }
    sort(fool.begin(),fool.end());
    maxi=ans11*bounty;
    //cout<<maxi<<endl;
    if(!fool.empty())
   		j=fool[0].ff;
    rep(i,fool.size()){
    	if(j!=0){
    		maxi=max(maxi,ans*(bounty+(j-1)*inc));
    		//cout<<j<<" "<<maxi<<endl;
    	}
    	while(i<fool.size() && j==fool[i].ff){
    		ans+=fool[i].ss;
    		i++;
    	}
    	
    	maxi=max(maxi,ans*(bounty+(j)*inc));
    	
    	if(i!=fool.size()){
    		j=fool[i].ff;
    		i--;
    	}


    }
    //cout<<maxi<<endl;
    if(ans>0 && inc!=0)
    	maxi=-1;
    cout<<maxi<<endl;
    return 0;  
    
}