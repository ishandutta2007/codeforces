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
vector<vii> vec(212545);
vector<vi> lolo(212545);
int x,d[223456],l[212345],r[212345],c[212345],n;
int geti(int ind){
	int i=ind;
	if(x-d[ind]<0)
		return -1;
	if(vec[x-d[ind]].empty())
		return -1;
	int val=lower_bound(vec[x-d[i]].begin(),vec[x-d[i]].end(),mp(r[i],inf))-vec[x-d[i]].begin();
	if(val==vec[x-d[i]].size()){
		return -1;
	}
	else{
		return lolo[x-d[i]][val];
	}
	return -1;
}
int main(){
    std::ios::sync_with_stdio(false);
	//int n,x;
	cin>>n>>x;
	int i;
	rep(i,n){
		cin>>l[i]>>r[i]>>c[i];
		d[i]=r[i]-l[i]+1;
		vec[r[i]-l[i]+1].pb(mp(l[i],c[i]));
	}     
	rep(i,212345){
		sort(vec[i].begin(),vec[i].end());
	}
	int flag,j;
	rep(i,212345){
		flag=1;
		lolo[i].resize(vec[i].size()+4);
		fd(j,(int)vec[i].size() -1,0){
			if(flag){
				lolo[i][j]=vec[i][j].ss;
				flag=0;
				continue;
			}

			lolo[i][j]=min(lolo[i][j+1],vec[i][j].ss);

		}

	}
	int maxi=inf;
	maxi*=2;
	rep(i,n){
		int val=geti(i);
		//cout<<val<<endl;
		if(val==-1)
			continue;
		maxi=min(c[i]+val,maxi);
	}
	if(maxi==inf*2){
		cout<<-1<<endl;
	}
	else{
		cout<<maxi<<endl;
	}
    
}