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
int siz=500;
vector<vi> adj(10000);
int haha[212345],arr[212345];
ll inv=0;
vector<int>::iterator it1;
int compute(int l,int r){
	int i,j;
	ll value1=0;
	ll value2=0;
	if(haha[l]==haha[r]){
		f(i,l+1,r){
			if(arr[i]<arr[l])
				value1++;
			if(arr[i]<arr[r])
				value2++;
		}
		inv+=2*(value2-value1);
		//cout<<arr[l]<<" "<<arr[r];

		if(arr[l]<arr[r])
			inv++;
		else
			inv--;
		return 0;

	}
	for(i=l+1;haha[i]==haha[l];i++){
		if(arr[i]<arr[l])
			value1++;
		if(arr[i]<arr[r])
			value2++;
	}
	for(i=r-1;haha[i]==haha[r];i--){
		if(arr[i]<arr[l])
			value1++;
		if(arr[i]<arr[r])
			value2++;
	}
	for(i=haha[l]+1;i<haha[r];i++){
		it1=lower_bound(adj[i].begin(),adj[i].end(),arr[l]);
		value1+=(it1-adj[i].begin());
		it1=lower_bound(adj[i].begin(),adj[i].end(),arr[r]);
		value2+=(it1-adj[i].begin());

	}
	inv+=2*(value2-value1);
	if(arr[l]<arr[r])
		inv++;
	else
		inv--;
	return 0;


}
int updateblock(int bl,int rem,int ad){
	int i,j;
	if(rem<ad){
		rep(i,adj[bl].size()){
			if(adj[bl][i]==rem)
				break;
		}
		f(j,i+1,adj[bl].size()){
			if(adj[bl][j]<ad){
				adj[bl][j-1]=adj[bl][j];
			}
			else{
				break;
			}
		}
		adj[bl][j-1]=ad;
		return 0;
	}
	if(rem>ad){
		fd(i,adj[bl].size()-1,0){
			if(adj[bl][i]==rem)
				break;
		}
		fd(j,i-1,0){
			if(adj[bl][j]>ad){
				adj[bl][j+1]=adj[bl][j];
			}
			else{
				break;
			}
		}
		adj[bl][j+1]=ad;
		return 0;
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,q,i,l,r;
	cin>>n>>q;
	siz=3*sqrt(n);
	int block=0;
	int j=0;
	f(i,1,n+1){
		arr[i]=i;
		if(i%siz==0){
			block++;
			j=0;
		}
		haha[i]=block;
		
		j++;
		adj[block].pb(i);
	}
	while(q--){
		cin>>l>>r;
		if(l==r){
			cout<<inv<<endl;
			continue;
		}
		if(r<l){
			swap(r,l);
		}
		compute(l,r);
		cout<<inv<<endl;
		updateblock(haha[r],arr[r],arr[l]);
		updateblock(haha[l],arr[l],arr[r]);
		swap(arr[r],arr[l]);
	}

}