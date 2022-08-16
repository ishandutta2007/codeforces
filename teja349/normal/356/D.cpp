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
bitset<72000> b,b1;
vector<vi> adj(71234);
int printans(int n){
	int i,j;
	rep(i,n){
		rep(j,adj[i].size()){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
vii vec,vec1;
int seen[72000];
int main(){
    std::ios::sync_with_stdio(false);
    int n,s;
    int i,val,j;
    cin>>n>>s;
    rep(i,n){
    	cin>>val;
    	vec.pb(mp(val,i));
    }
    sort(all(vec));
    s-=vec[n-1].ff;
    if(s==0){

    	fd(i,n-1,0){
    		if(i!=0){
    			adj[vec[i].ss].pb(vec[i].ff-vec[i-1].ff);
    			adj[vec[i].ss].pb(1);
    			adj[vec[i].ss].pb(vec[i-1].ss+1);
    		}
    		else{
    			adj[vec[i].ss].pb(vec[i].ff);
    			adj[vec[i].ss].pb(0);
    		}
    	}
    	printans(n);
    	return 0;
    }else if(s<0){
    	cout<<-1<<endl;
    	//cout<<"Sas"<<endl;
    	return 0;
    }
    rep(i,72000){
    	b[i]=0;
    	seen[i]=-1;
    }
    b[0]=1;	
    rep(j,n-1){
    	b1=b;
    	b|=(b<<vec[j].ff);
    	b1^=b;
    	for(i=b1._Find_first();i<b1.size();i=b1._Find_next(i)){
    		seen[i]=j;
    	}
    }
    //cout<<seen[1]<<endl;
    //cout<<b[3]<<endl;
    //cout<<s<<endl;
    if(seen[s]==-1){
    	cout<<-1<<endl;
    	return 0;
    }	
    else{
    	int s1=s;
    	fd(i,n-1,0){
    		if(seen[s1]==i){
    			//cout<<vec[i].ff<<endl;
    			adj[vec[i].ss].pb(vec[i].ff);
    			adj[vec[i].ss].pb(0);
    			s1=s1-vec[i].ff;
    		}
    		else{
    			//cout<<vec[]
    			vec1.pb(vec[i]);
    		}
    	}
    	//cout<<s1<<endl;
    	//return 0;
    	vec.clear();
    	fd(i,vec1.size()-1,0){
    		//cout<<vec1[i].ff<<endl;
    		vec.pb(vec1[i]);
    	}
    	fd(i,vec.size()-1,0){
    		if(i!=0){
    			adj[vec[i].ss].pb(vec[i].ff-vec[i-1].ff);
    			adj[vec[i].ss].pb(1);
    			adj[vec[i].ss].pb(vec[i-1].ss+1);
    		}
    		else{
    			adj[vec[i].ss].pb(vec[i].ff);
    			adj[vec[i].ss].pb(0);
    		}
    	}
    	printans(n);

    }
    return 0;  
    
}