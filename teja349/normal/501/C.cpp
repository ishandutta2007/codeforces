
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
//std::ios::sync_with_stdio(false);   


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

int main(){
	std::ios::sync_with_stdio(false);
	vii vec(200000);
	int n,u,v,sum=0,i;
	cin>>n;
	stack< int > st;
	rep(i,n){
		cin>>u>>v;
		vec[i]=mp(u,v);
		if(u==1)
			st.push(i);
		sum+=u;
	}
	cout<<sum/2<<endl;
	while(!st.empty()){
		int val=st.top();
		st.pop();
		if(vec[val].ff==0)
			continue;
		int next=vec[val].ss;
		cout<<val<<" "<<vec[val].ss<<endl;
		vec[next].ff--;
		vec[next].ss=vec[next].ss ^ val;
		if(vec[next].ff==1)
			st.push(next);
	}

}