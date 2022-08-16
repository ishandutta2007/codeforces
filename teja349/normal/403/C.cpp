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
int visit1[12345],visit[12345],a[2003][2003],b[2003][2003],en[12345],st[12345];  
int timer=1,counti=0,n;
int dfs(int cur){
	visit[cur]=1;
	st[cur]=timer++;
	counti++;
	int i;
	rep(i,n){
		if(a[cur][i] && !visit[i]){
			dfs(i);
		}
	}
	en[cur]=timer++;
	return 0;
}
int dfs1(int cur){
	visit1[cur]=1;
	//cout<<cur<<" "<<counti<<endl;
	//st[cur]=timer++;
	counti++;
	int i;
	rep(i,n){
		if(b[cur][i] && !visit1[i]){
			dfs1(i);
		}
	}
	//en[cur]=timer++;
	return 0;
}
int main(){
    //std::ios::sync_with_stdio(false);
    //int n;
    cin>>n;
    int i,j;

    rep(i,n){
    	rep(j,n){
    		scanf("%d",&a[i][j]);

    		if(a[i][j]){
    			//cout<<i<<" "<<j<<endl;
    			//boo++;
    			a[i][j]=1;
    			b[j][i]=1;
    		}

    	}
    }
    //cout<<boo<endl;
    dfs(0);
    if(counti!=n){
    	cout<<"NO"<<endl;
    }
    else{
    	int maxi=0,val=0;
    	rep(i,n){
    		if(en[i]>maxi){
    			maxi=en[i];
    			val=i;
    		}
    	}
    	counti=0;
    	dfs1(val);
    	if(counti==n)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    }
    
}