
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
#define inf 1000*1000*1000+5
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000*1000*1000+7
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

vector< vector< int > > vec(100004);
vi v1,v2;
int visit[100002]={0};


int dfs(int i,int color);

int main(){
	int n,m,i,p,q;
	cin>>n>>m;
	rep(i,m){
		cin>>p>>q;
		vec[p].pb(q);
		vec[q].pb(p);
	}

	f(i,1,n+1){
		//cout<<"Hiii   "<<i<<endl;
		if(visit[i]==0){
			dfs(i,1);
			v1.pb(i);

		}
		else{
			if(visit[i]==1){
				v1.pb(i);

			}
			else{
				v2.pb(i);
			}
		}
	}
	cout<<v1.size()<<endl;
	for (int i = 0; i < v1.size(); ++i)
	{
		cout<<v1[i]<<" ";
	}
	cout<<endl;
	cout<<v2.size()<<endl;
	for (int i = 0; i < v2.size(); ++i)
	{
		cout<<v2[i]<<" ";
	}
	cout<<endl;

}
int dfs(int i,int color){
	visit[i]=color;
	if(color==1)
		color=2;
	else
		color=1;
	vi::iterator it;
	for(it=vec[i].begin();it!=vec[i].end();it++){
		if(visit[*it]==0)
			dfs(*it,color);
		else{
			if(visit[*it]!=color){
				cout<<-1<<endl;
				exit(0);
			}
			
		}
	}
	return 0;
}