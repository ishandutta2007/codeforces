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
int haha[123][123][13],arr[123][123][13];
   
int compute(int a,int b){
	int i;
	rep(i,12){
		haha[a][b][i]=haha[a-1][b][i]+haha[a][b-1][i]-haha[a-1][b-1][i];
		haha[a][b][i]+=arr[a][b][i];
	}
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    int n,q,c;
    cin>>n>>q>>c;
    int i,u,v,val,j;
    rep(i,n){
    	cin>>u>>v>>val;
    	arr[u][v][val]++;
    }
    f(i,1,103){
    	f(j,1,103){
    		compute(i,j);

    	}
    }
    int t,x1,x2,y1,y2;
    while(q--){
    	cin>>t;
    	cin>>x1>>y1>>x2>>y2;
    	int sumi=0;
    	rep(i,12){
    		val=haha[x2][y2][i]+haha[x1-1][y1-1][i]-haha[x2][y1-1][i]-haha[x1-1][y2][i];
    		//cout<<val;
    		sumi+=val*((i+t)%(c+1));

    		//cout<<val<<"  "<<(i+t)<<endl;
    		//cout<<sumi<<endl;
    		//cout<<(i+t)%c<<endl;
    	}

    	cout<<sumi<<endl;

    }

    return 0;      

}