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
int bit[1234567]={0};
vector<vi> adj(1234567);
int c;
int compute(int val){
	int val1=val+1;
	int i=0;
	int flag=0;
	while(i<adj[val].size() && i<adj[val1].size()){
		if(adj[val][i]<adj[val1][i]){
			bit[0]++;
			bit[c-adj[val1][i]+1]--;
			if(adj[val][i]!=1){
				bit[c-(adj[val][i]-1)]++;
				bit[c]--;
			}
			flag=1;
			break;
		}
		if(adj[val][i]>adj[val1][i]){
			bit[c-adj[val][i]+1]++;
			bit[c-adj[val1][i]+1]--;
			flag=1;
			break;
		}

		i++;
	}

	if(!flag){
		if(i==adj[val].size())
			bit[0]++;
		else
		{
			cout<<-1<<endl;
			exit(0);
		}
	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,val;
	cin>>n>>c;
	int i,j,l;
	rep(i,n){
		cin>>l;
		rep(j,l){
			cin>>val;
			adj[i].pb(val);
		}
	}
	rep(i,n-1){
		compute(i);
	}
	rep(i,c){
		if(bit[i]==n-1){
			cout<<i<<endl;
			return 0;
		}
		bit[i+1]=bit[i+1]+bit[i];
	}
	cout<<-1<<endl;
	return 0;

}