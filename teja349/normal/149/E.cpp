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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define int ll
/** Z Algorithm **/
const int MAXN =5e5+5;

int z[MAXN];
int z_algo_construct(string s){
	int l=0,r=0;
	int i,n=s.length();
	f(i,1,s.length()){
		if(i>r){
			l=r=i;
			while (r < n && s[r-l] == s[r]) r++;
   			z[i] = r-l; r--;   			
		}
		else{
			int k=i-l;
			if(z[k]<r-i+1) z[i] = z[k];	
			else{
				l=i;
				while(r < n && s[r-l]==s[r])r++;
				z[i] = r-l; r--;
			}		
		}

	}
	return 0;
	
}

int seg[412345],lazy[412345];
int build(int node,int s,int e){
	seg[node]=0;
	lazy[node]=0;
	if(s==e)
		return 0;
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	return 0;
}

int update(int node,int s,int e,int pos){
	if(lazy[node]){
		seg[node]+=lazy[node]*(e-s+1);
		if(s!=e){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(e<=pos){
		seg[node]+=(e-s+1);
		if(s!=e){
			lazy[2*node]++;
			lazy[2*node+1]++;
		}
		return 0;
	}
	if(pos<s){
		return 0; 
	}
	int mid=(s+e)/2;
	update(2*node,s,mid,pos);
	update(2*node+1,mid+1,e,pos);
	seg[node]=seg[2*node+1]+seg[2*node];
	return 0;
}

int query(int node,int s,int e,int pos){
	if(lazy[node]){
		seg[node]+=lazy[node]*(e-s+1);
		if(s!=e){
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(pos<=s){
		return seg[node];
	}
	if(e<pos)
		return 0;
	int mid=(s+e)/2;
	int ans=query(2*node,s,mid,pos);
	ans+=query(2*node+1,mid+1,e,pos);
	return ans;
}
string t[123],revt[123];
int haha[123456],wow[123456];

signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	string s;
  	cin>>s;
  	string revs=s;
  	reverse(all(revs));
  	int m;
  	cin>>m;
  	int ans=0;
  	int i;
  	int j;
  	string gg,lol;
  	//cout<<m<<endl;
  	rep(i,m){
  		cin>>t[i];
  		//cout<<t[i]<<endl;
  		revt[i]= t[i];
  		reverse(all(revt[i]));
  	}
  	int biggie=0;
  	rep(i,m){
  		//cout<<t[i]<<endl;
  		gg=t[i]+"#"+s;
  		z_algo_construct(gg);
  		int val=t[i].length();
  		int len=s.length();
  		f(j,t[i].length()+1,gg.length()){
  			haha[j-val-1]=z[j];
  		}
  		//cout<<endl;
  		//cout<<t[i]<<endl;
  		lol=revt[i]+"#"+revs;
  		z_algo_construct(lol);
  		f(j,t[i].length()+1,lol.length()){
  			wow[len-1-(j-val-1)]=z[j];
  		}
  		// rep(j,len){
  		// 	cout<<haha[j]<<" ";
  		// }
  		// cout<<endl;
  		// rep(j,len){
  		// 	cout<<wow[j]<<" ";
  		// }
  		// cout<<endl;
  		build(1,0,val+5);
  		int zozo=0;
  		rep(j,len){
  			if(j>=val-1){
  				//update(1,0,val+5,min(haha[j-(val-1)],val-1));
  				zozo=max(zozo,min(haha[j-(val-1)],val-1));
  				//cout<<haha[j-(val-1)]<<" ";
  			}
  			//cout<<endl;
  			if(zozo>=max(1LL,val-wow[j]))
  				ans=1;
  			//ans+=query(1,0,val+5,max(1LL,val-wow[j]));
  			if(ans==1)
  				break;
  		}
  		if(ans)
  			biggie++;
  		ans=0;
  	}
  	cout<<biggie<<endl;
    return 0;   
}