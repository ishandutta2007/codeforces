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
#define int ll
// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int seg[5][412345],lazy[5][412345];

int getsum(int l,int r){
	int val=r*(r+1)/2-l*(l-1)/2;
	val-=(r-l+1);
	val%=mod;
	return val;
}
int build(int node,int s,int e){
	int i;
	rep(i,5){
		seg[i][node]=0;
		lazy[i][node]=-10;
	}
	if(s==e)
		return 0;
	int mid=(s+e)/2;
	build(2*node,s,mid);
	build(2*node+1,mid+1,e);
	return 0;
}
int updatelef(int node,int s,int e,int l,int r,int val){
	if(lazy[0][node]!=-10){
		seg[0][node]=lazy[0][node]*(e-s+1);
		seg[0][node]%=mod;
		if(s!=e){
			lazy[0][2*node+1]=lazy[0][node];
			lazy[0][2*node]=lazy[0][node];
		}
		lazy[0][node]=-10;
	}
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		seg[0][node]=val*(e-s+1);
		seg[0][node]%=mod;
		lazy[0][node]=val;
		if(s!=e){
			lazy[0][2*node+1]=lazy[0][node];
			lazy[0][2*node]=lazy[0][node];
		}
		lazy[0][node]=-10;
		return 0;
	}
	int mid=(s+e)/2;
	updatelef(2*node,s,mid,l,r,val);
	updatelef(2*node+1,mid+1,e,l,r,val);
	seg[0][node]=seg[0][2*node]+seg[0][2*node+1];
	seg[0][node]%=mod;
	return 0;
}

int querylef(int node,int s,int e,int l,int r){
	if(lazy[0][node]!=-10){
		seg[0][node]=lazy[0][node]*(e-s+1);
		seg[0][node]%=mod;
		if(s!=e){
			lazy[0][2*node+1]=lazy[0][node];
			lazy[0][2*node]=lazy[0][node];
		}
		lazy[0][node]=-10;
	}
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		return seg[0][node];
	}
	int mid=(s+e)/2;
	int ans=querylef(2*node,s,mid,l,r);
	ans+=querylef(2*node+1,mid+1,e,l,r);
	ans%=mod;
	return ans;
}
int updaterig(int node,int s,int e,int l,int r,int val){
	if(lazy[1][node]!=-10){
		seg[1][node]=getsum(s,e)*lazy[1][node];
		seg[1][node]%=mod;
		if(s!=e){
			lazy[1][2*node+1]=lazy[1][node];
			lazy[1][2*node]=lazy[1][node];
		}
		lazy[1][node]=-10;
	}
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		lazy[1][node]=val;
		seg[1][node]=getsum(s,e)*lazy[1][node];
		seg[1][node]%=mod;
		if(s!=e){
			lazy[1][2*node+1]=lazy[1][node];
			lazy[1][2*node]=lazy[1][node];
		}
		lazy[1][node]=-10;
		return 0;
	}
	int mid=(s+e)/2;
	updaterig(2*node,s,mid,l,r,val);
	updaterig(2*node+1,mid+1,e,l,r,val);
	seg[1][node]=seg[1][2*node]+seg[1][2*node+1];
	seg[1][node]%=mod;
	return 0;
}
int queryrig(int node,int s,int e,int l,int r){
	if(lazy[1][node]!=-10){
		seg[1][node]=getsum(s,e)*lazy[1][node];
		seg[1][node]%=mod;
		if(s!=e){
			lazy[1][2*node+1]=lazy[1][node];
			lazy[1][2*node]=lazy[1][node];
		}
		lazy[1][node]=-10;
	}
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		return seg[1][node];
	}
	int mid=(s+e)/2;
	int ans=queryrig(2*node,s,mid,l,r);
	ans+=queryrig(2*node+1,mid+1,e,l,r);
	ans%=mod;
	return ans;
}
int updatelefrig(int node,int s,int e,int l,int r,int val){
	if(lazy[2][node]!=-10){
		seg[2][node]=(e-s+1)*lazy[2][node];
		seg[2][node]%=mod;
		seg[4][node]=seg[3][node]*lazy[2][node];
		seg[4][node]%=mod;
		if(s!=e){
			lazy[2][2*node+1]=lazy[2][node];
			lazy[2][2*node]=lazy[2][node];
		}
		lazy[2][node]=-10;
	}
	if(lazy[3][node]!=-10){
		seg[3][node]=(e-s+1)*lazy[3][node];
		seg[3][node]%=mod;
		seg[4][node]=seg[2][node]*lazy[3][node];
		seg[4][node]%=mod;
		if(s!=e){
			lazy[3][2*node+1]=lazy[3][node];
			lazy[3][2*node]=lazy[3][node];
		}
		lazy[3][node]=-10;
	}
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		lazy[2][node]=val;
		seg[2][node]=(e-s+1)*lazy[2][node];
		seg[2][node]%=mod;
		seg[4][node]=seg[3][node]*lazy[2][node];
		seg[4][node]%=mod;
		if(s!=e){
			lazy[2][2*node+1]=lazy[2][node];
			lazy[2][2*node]=lazy[2][node];
		}
		lazy[2][node]=-10;
		return 0;
	}
	int mid=(s+e)/2;
	updatelefrig(2*node,s,mid,l,r,val);
	updatelefrig(2*node+1,mid+1,e,l,r,val);
	int i;
	f(i,2,5){
		seg[i][node]=seg[i][2*node]+seg[i][2*node+1];
		seg[i][node]%=mod;
	}
	return 0;
}
int updateriglef(int node,int s,int e,int l,int r,int val){
	if(lazy[2][node]!=-10){
		seg[2][node]=(e-s+1)*lazy[2][node];
		seg[2][node]%=mod;
		seg[4][node]=seg[3][node]*lazy[2][node];
		seg[4][node]%=mod;
		if(s!=e){
			lazy[2][2*node+1]=lazy[2][node];
			lazy[2][2*node]=lazy[2][node];
		}
		lazy[2][node]=-10;
	}
	if(lazy[3][node]!=-10){
		seg[3][node]=(e-s+1)*lazy[3][node];
		seg[3][node]%=mod;
		seg[4][node]=seg[2][node]*lazy[3][node];
		seg[4][node]%=mod;
		if(s!=e){
			lazy[3][2*node+1]=lazy[3][node];
			lazy[3][2*node]=lazy[3][node];
		}
		lazy[3][node]=-10;
	}
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		lazy[3][node]=val;
		seg[3][node]=(e-s+1)*lazy[3][node];
		seg[3][node]%=mod;
		seg[4][node]=seg[2][node]*lazy[3][node];
		seg[4][node]%=mod;
		if(s!=e){
			lazy[3][2*node+1]=lazy[3][node];
			lazy[3][2*node]=lazy[3][node];
		}
		lazy[3][node]=-10;
		return 0;
	}
	int mid=(s+e)/2;
	updateriglef(2*node,s,mid,l,r,val);
	updateriglef(2*node+1,mid+1,e,l,r,val);
	int i;
	f(i,2,5){
		seg[i][node]=seg[i][2*node]+seg[i][2*node+1];
		seg[i][node]%=mod;
	}
	return 0;
}

int querylefrig(int node,int s,int e,int l,int r){
	if(lazy[2][node]!=-10){
		seg[2][node]=(e-s+1)*lazy[2][node];
		seg[2][node]%=mod;
		seg[4][node]=seg[3][node]*lazy[2][node];
		seg[4][node]%=mod;
		if(s!=e){
			lazy[2][2*node+1]=lazy[2][node];
			lazy[2][2*node]=lazy[2][node];
		}
		lazy[2][node]=-10;
	}
	if(lazy[3][node]!=-10){
		seg[3][node]=(e-s+1)*lazy[3][node];
		seg[3][node]%=mod;
		seg[4][node]=seg[2][node]*lazy[3][node];
		seg[4][node]%=mod;
		if(s!=e){
			lazy[3][2*node+1]=lazy[3][node];
			lazy[3][2*node]=lazy[3][node];
		}
		lazy[3][node]=-10;
	}
	if(e<l || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		return seg[4][node];
	}
	int mid=(s+e)/2;
	int ans=querylefrig(2*node,s,mid,l,r);
	ans+=querylefrig(2*node+1,mid+1,e,l,r);
	ans%=mod;
	return ans;
}

int a[123456],last[123456],nexti[123456],previ[123456];
map<int,int> mapi;
int dpn[123456][20],dpl[123456][20];
int getnext(int l,int r){
	int val=log2(r-l+1);
	return min(dpn[l][val],dpn[r-(1<<val)+1][val]);
}
int getprev(int l,int r){
	int val=log2(r-l+1);
	return max(dpl[l][val],dpl[r-(1<<val)+1][val]);
}


signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n;
  	cin>>n;
  	int i;
  	map<int,int>::iterator it;
  	int counter=0;
  	rep(i,n){
  		cin>>a[i];
  		mapi[a[i]]=1;
  	}
  	for(it=mapi.begin();it!=mapi.end();it++){
  		it->ss=counter++;
  	}
  	rep(i,n){
  		a[i]=mapi[a[i]];
  	}
  	rep(i,counter){
  		last[i]=-1;
  	}
  	rep(i,n){
  		previ[i]=last[a[i]];
  		last[a[i]]=i;
  	}
  	rep(i,counter){
  		last[i]=n;
  	}
  	fd(i,n-1,0){
  		nexti[i]=last[a[i]];
  		last[a[i]]=i;
  		//cout<<nexti[i]<<endl;
  	}
  	rep(i,n){
  		dpn[i][0]=nexti[i];
  		dpl[i][0]=previ[i];
  	}
  	int j;
  	f(j,1,20){
  		rep(i,n){
  			if(i+(1<<(j-1))<n){
  				dpn[i][j]=min(dpn[i][j-1],dpn[i+(1<<(j-1))][j-1]);
  				dpl[i][j]=max(dpl[i][j-1],dpl[i+(1<<(j-1))][j-1]);
  			}
  		}
  	}
  	int ans=0;
  	j=0;
  	stack<int> st1,st2;
  	nexti[n]=-1;
  	previ[n]=n;
  	st1.push(n);
  	st2.push(n);
  	int val;
  	build(1,0,n-1);
  	//cout<<getnext()
  	rep(i,n){
  		//cout<<i<<" ds  "<<j<<endl;
  		while(j<n){
  			
  			val=getnext(i,j);
  			// if(i==2){
  			// 	cout<<val<<endl;
  			// }
  			if(val<=j)
  				break;
  			val=getprev(i,j);
  			if(val>=i)
  				break;
  			
  			while(!st1.empty() && previ[st1.top()]<=previ[j]){
  				st1.pop();
  			}
  			val=st1.top();
  			if(val==n)
  				val=-1;
  			st1.push(j);
  			updatelef(1,0,n-1,val+1,j,previ[j]);
  			updatelefrig(1,0,n-1,val+1,j,previ[j]);
  			while(!st2.empty() && nexti[st2.top()]>=nexti[j]){
  				st2.pop();
  			}
  			val=st2.top();
  			if(val==n)
  				val=-1;
  			updaterig(1,0,n-1,val+1,j,nexti[j]);
  			updateriglef(1,0,n-1,val+1,j,nexti[j]);
  			st2.push(j);
  			val=querylef(1,0,n-1,i,j);
  			val%=mod;
  			val*=(j+1);
  			val%=mod;
  			ans+=val;
  			val=queryrig(1,0,n-1,i,j);
  			ans+=val;
  			ans%=mod;
  			val=querylefrig(1,0,n-1,i,j);
  			ans-=val;
  			ans%=mod;
  			ans-=getsum(i,j)*(j+1);
  			ans%=mod;
  			//cout<<i<<" "<<j<<" "<<ans<<endl;
  			j++;

  		}
  	}
  	ans+=mod;
  	ans%=mod;
  	cout<<ans<<endl;

}