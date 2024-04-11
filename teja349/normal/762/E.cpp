
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
//map< map <int ,int> ,int > mapi
struct radio{
	ll pos;
	ll rad;
	ll freq;
};
bool compare(radio x,radio y){
	return (x.pos < y.pos);
}
vector< radio > vec;
vector < vector < int > > segadj(10047); 
vector < vi > adj(10047);
vii orderrad;
map<int,int> mapi;

int update(int val1,int node,int s,int e,int p){
	if(s==e){
		segadj[val1][node]=1;
		return 0;
	}
	int mid=(s+e)/2;
	if(p<=mid){
		update(val1,2*node,s,mid,p);
	}
	else{
		update(val1,2*node+1,mid+1,e,p);
	}
	segadj[val1][node]=segadj[val1][2*node]+segadj[val1][2*node+1];
	return 0; 
}

int query(int val1,int node,int s,int e,int l,int r){
	
	if(r<s||e<l){
		return 0;
	}
	if(l<=s && e<=r){
		return segadj[val1][node];
	}
	int mid=(s+e)/2;
	int asd=query(val1,2*node,s,mid,l,r);
	int asb=query(val1,2*node+1,mid+1,e,l,r);
	return asd+asb;
}	

int main(){
	std::ios::sync_with_stdio(false);
	int u,v,w,n,k,i,j;
	cin>>n>>k;

	rep(i,n){
		cin>>u>>v>>w;

		vec.pb({u,v,w});
		mapi[u]=w;
		
	}
	sort(vec.begin(),vec.end(),compare);
	rep(i,n){
		adj[vec[i].freq].pb(vec[i].pos);
		orderrad.pb( mp( vec[i].pos - vec[i].rad,vec[i].pos));
	}
	sort(orderrad.begin(),orderrad.end());
	rep(i,10035){
		segadj[i].resize(4*adj[i].size()+2,0);
	}
	i=0;
	j=0;
	int val1,val2,value1,value2;
	ll sumi=0;
	vi::iterator it,it1,it2; 
	while(i<n || j<n){
		//cout<<"hii"<<endl;
		int ker;
		if(i==n || (orderrad[i].ff > vec[j].pos) ){
			//cout<<"you   "<<i<<"  "<<j<<endl;
			val1=vec[j].freq;
			val2=val1+k;
			val1-=k;
			val1=max(val1,1);
			f(ker,val1,val2+1){
				it1=upper_bound(adj[ker].begin(),adj[ker].end(),vec[j].pos);
				value1=it1-adj[ker].begin();
				it2=upper_bound(adj[ker].begin(),adj[ker].end(),vec[j].pos+vec[j].rad);
				it2--;
				value2=it2-adj[ker].begin();
				if(ker==8){
					//cout<<value1<<" dsf  "<<value2<<endl;
				}
				if(value2>=value1){
					sumi+=query(ker,1,0,adj[ker].size()-1,value1,value2);
				}

			}

			j++;
		}
		else {
			//cout<<"meee   "<<i<<"  "<<j;
			val1=mapi[orderrad[i].ss];
			it=lower_bound(adj[val1].begin(),adj[val1].end(),orderrad[i].ss);
			val2=it-adj[val1].begin();
			//cout<<"   "<<query(val1,1,0,adj[val1].size()-1,val2,val2)<<endl;
			update(val1,1,0,adj[val1].size()-1,val2);

			
			i++;
		}
		
	}
	cout<<sumi<<endl;




}