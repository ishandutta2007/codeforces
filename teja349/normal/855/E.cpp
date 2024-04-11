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
vector< vector< vector< ll > > > vec(12,vector< vector<ll > > (70)); 

ll compute(ll val,ll b){
	//cout<<val<<endl;
	ll val1=val,lol=0;
	if(val==0)
		return 1;
	vi haha;
	while(val!=0){
		haha.pb(val%b);
		val/=b;
	}
	ll i,j,ans=0;
	ll flag=1;
	//return 0;
	fd(i,haha.size()-1,0){
		f(j,0,haha[i]){
			//cout<<j<<endl;
			if(flag==1 && j==0)
			{
				flag=0;
				continue;
			}

			ans+=vec[b][i][(lol^(1<<j))];

		}
		if(i!=0){
			//cout<<ans<<"   "<<i<<"  ";
			ans+=vec[b][i][0]-vec[b][i-1][1];
			//cout<<ans<<endl;
		}
		
		//ans+=vec[b][i][0];
		lol^=(1<<haha[i]);

	}
	if(lol==0)
		ans++;
	
		
		ans++;
	return ans;


}
int main(){
    std::ios::sync_with_stdio(false);
    
    ll i,j,k,p;
    f(i,2,11){
    	vec[i][0].resize((1<<i)+10,0);

    	vec[i][0][0]=1;

    	f(k,1,67){

    		vec[i][k].resize((1<<i)+10,0);
    		//return 0;
    		rep(j,(1<<i)){
    			rep(p,i){
    				vec[i][k][j]+=vec[i][k-1][(j^(1<<p))];
    			}
	    	}
    	}
    	
    }
    //return 0;
    int q;
    cin>>q;
    while(q--){
    	ll b,l,r;
    	cin>>b>>l>>r;
    	ll ans=compute(r,b)-compute(l-1,b);
    	cout<<ans<<endl;

    }
    return 0;  
    
}