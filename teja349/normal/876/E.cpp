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
vector<vi> out(123456);
int printno(){
	cout<<"No"<<endl;
	exit(0);
}
int cap[123456];
int dfs(int cur){
	int i,val;
	rep(i,out[cur].size()){
		val=out[cur][i];
		if(cap[val]){
			if(val>cur)
				printno();

		}
		else {
			if(val>cur)
				printno();
			cap[val]=1;
			dfs(val);
		}
	}
	return 0;
}
vector< vi> vec(123456);
vii papa;
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,j,val,lol;
    rep(i,n){
    	cin>>val;
    	rep(j,val){
    		cin>>lol;
    		vec[i].pb(lol);
    	}
    }
    int flag=0;
    rep(i,n-1){
    	flag=0;
    	val=min(vec[i].size(),vec[i+1].size());
    	rep(j,val){
    		if(vec[i][j]!=vec[i+1][j]){
    			//cout<<i<<" "<<vec[i][j]<<" "<<vec[i+1][j]<<endl;
    			papa.pb(mp(vec[i][j],vec[i+1][j]));
    			out[vec[i+1][j]].pb(vec[i][j]);
    			flag=1;
    			break;
    		}
    	}
    	if(!flag && vec[i].size()>vec[i+1].size())
    		printno();
    }
    int u,v;
    rep(i,papa.size()){
    	u=papa[i].ff;
    	v=papa[i].ss;
    	//cout<<u<< " "<<v<<endl;
    	if(u<v && !cap[u] && !cap[v])
    		continue;
    	if(cap[u]){
    		continue;
    	}
    	cap[u]=1;
    	//cout<<"buu";
    	dfs(u);

    }
    cout<<"Yes"<<endl;
    int ans=0;
    rep(i,m+12){
    	ans+=cap[i];
    }
    cout<<ans<<endl;
    rep(i,m+12){
    	if(cap[i])
    		cout<<i<<" ";
    }
    return 0;  
    
}