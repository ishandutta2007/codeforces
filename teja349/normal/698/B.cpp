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
int p[223456];
vi vec;
int dsu[223456];
int find(int u){
	if(dsu[u]<0) return u;
	dsu[u]=find(dsu[u]);
	return dsu[u];
}
int merge(int u,int v){
	if(dsu[u]<dsu[v]){
		dsu[v]=u;
	}
	else if(dsu[v]<dsu[u]){
		dsu[u]=v;
	}
	else{
		dsu[u]=v;
		dsu[v]--;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int root=-1;
    int i,a,b;
    rep(i,n+22){
    	dsu[i]=-1;
    }
    f(i,1,n+1){
    	cin>>p[i];
    	if(p[i]==i){
    		if(root==-1){
    			root=i;
    		}
    		else{
    			vec.pb(i);
    		}
    	}
    	else{
    		a=find(i);
    		b=find(p[i]);
    		if(a!=b){
    			merge(a,b);
    		}
    		else{
    			vec.pb(i);
    		}
    	}

    }
    cout<<vec.size()<<endl;
    if(root==-1){
    	root=vec[0];    	
    }
    rep(i,vec.size()){
    	p[vec[i]]=root;
    }
    f(i,1,n+1){
    	cout<<p[i]<<" ";
    }
    return 0;

}