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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
ll bit[123456],seg[5][412345],a[123456];
ll iinf;
ll updatebit(ll pos,ll val){
	while(pos<123456){
		bit[pos]+=val;
		pos+=pos&(-pos);
	}
	return 0;
}   
ll querybit(ll pos){
	ll ans=0;
	while(pos>0){
		ans+=bit[pos];
		pos-=pos&(-pos);
	}
	return ans;
}
ll getval(ll pos){
	return querybit(pos)+a[pos];
}
ll buildseg(ll node,ll s,ll e){
	ll i;
	if(s==e){
		seg[0][node]=(a[s-1]-a[s])+(a[s]-a[s+1]);
		seg[1][node]=(a[s-1]-a[s])-1*(a[s]-a[s+1]);
		seg[2][node]=-1*(a[s-1]-a[s])+(a[s]-a[s+1]);
		seg[3][node]=-1*(a[s-1]-a[s])-1*(a[s]-a[s+1]);
		seg[4][node]=seg[0][node];

		rep(i,4){
			seg[4][node]=max(seg[4][node],seg[i][node]);
		}
		rep(i,4){
			seg[i][node]-=seg[4][node];
		}
		return 0;
	}
	ll mid=(s+e)/2;
	buildseg(2*node,s,mid);
	buildseg(2*node+1,mid+1,e);
	rep(i,4){
		seg[i][node]=max(seg[i][2*node],seg[i][2*node+1]);
	}
	return 0;

}
ll update(ll node,ll s,ll e,ll p){
	ll i;
	if(s==e){
		ll val1=getval(s-1);
		ll val2=getval(s);
		ll val3=getval(s+1);
		seg[0][node]=(val1-val2)+(val2-val3);
		seg[1][node]=(val1-val2)-1*(val2-val3);
		seg[2][node]=-1*(val1-val2)+(val2-val3);
		seg[3][node]=-1*(val1-val2)-1*(val2-val3);
		seg[4][node]=seg[0][node];
		//ll i;
		rep(i,4){
			seg[4][node]=max(seg[4][node],seg[i][node]);
		}
		rep(i,4){
			seg[i][node]-=seg[4][node];
		}
		return 0;
	}
	ll mid=(s+e)/2;
	if(p<=mid){
		update(2*node,s,mid,p);
	}
	else{
		update(2*node+1,mid+1,e,p);
	}
	rep(i,4){
		seg[i][node]=max(seg[i][2*node],seg[i][2*node+1]);
	}
	return 0;
}
ll query(ll node,ll s,ll e,ll l,ll r,ll x){
	if(e<l || r<s)
		return iinf;
	if(l<=s && e<=r){
		ll maxi=seg[0][node];
		maxi=max(seg[1][node]-2*x,seg[2][node]+2*x);
		maxi=max(maxi,seg[0][node]);
		maxi=max(maxi,seg[3][node]);
		return maxi;
	}
	ll mid=(s+e)/2;
	ll a=query(2*node,s,mid,l,r,x);
	ll b=query(2*node+1,mid+1,e,l,r,x);
	return max(a,b);
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    iinf=inf;
    iinf*=3;
    iinf*=-1;
    cin>>n;
    ll i;
    f(i,1,n+1){
    	cin>>a[i];

    }
    ll ans=0;
    f(i,1,n){
    	ans+=abs(a[i]-a[i+1]);
    }
    ll q;
    cin>>q;
    ll typ,l,r,x,maxi,val1,val2;
    buildseg(1,2,n-1);
    rep(i,q){
    	cin>>typ>>l>>r>>x;
    	if(typ==1){
    		maxi=iinf;
    		if(r>1 && l<n)
    			maxi=query(1,2,n-1,max(l,2LL),min(r,n-1),x);
    		if(l==1){
    			val1=getval(1);
    			val2=getval(2);
    			maxi=max(maxi,abs(val1+x-val2)-abs(val1-val2));
    		}
    		if(r==n){
    			val1=getval(n-1);
    			val2=getval(n);
    			maxi=max(maxi,abs(val1+x-val2)-abs(val1-val2));
    		}
    		cout<<ans+maxi<<endl;
    	}
    	else{
    		if(l!=1){
    			ans-=abs(getval(l-1)-getval(l));
    		}
    		if(r!=n){
    			ans-=abs(getval(r)-getval(r+1));
    		}
    		updatebit(l,x);
    		updatebit(r+1,-1*x);
    		if(r!=n){
    			ans+=abs(getval(r)-getval(r+1));
    			if(r!=1)
    				update(1,2,n-1,r);
    			update(1,2,n-1,r+1);
    		}
    		if(l!=1){
    			if(l!=n)
    				update(1,2,n-1,l);
    			update(1,2,n-1,l-1);
    			
    			ans+=abs(getval(l-1)-getval(l));
    		}
    		
    	}

    }


    return 0;  
    
}