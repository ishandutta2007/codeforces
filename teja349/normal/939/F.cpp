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
#define mod (1000*1000*10+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);  
int seg[2][812345][2]; 
int dp[212345],revdp[212345],haha[212345],lol[212345];
int query(int typ,int node,int s,int e,int l,int r,int gg){
	if(e<l || r<s)
		return inf;
	if(l<=s && e<=r)
		return seg[typ][node][gg];
	int mid=(s+e)/2;
	int val1=query(typ,2*node,s,mid,l,r,gg);
	int val2=query(typ,2*node+1,mid+1,e,l,r,gg);
	return min(val1,val2);
}
int buildseg(int typ,int node,int s,int e){
	if(s==e){
		int val;
		if(typ==1)
			val=revdp[s];
		else
			val=dp[s];
		seg[typ][node][s%2]=val;
		seg[typ][node][(s+1)%2]=inf;
		return 0;
	}
	int mid=(s+e)/2;
	buildseg(typ,2*node,s,mid);
	buildseg(typ,2*node+1,mid+1,e);
	seg[typ][node][0]=min(seg[typ][2*node][0],seg[typ][2*node+1][0]);
	seg[typ][node][1]=min(seg[typ][2*node][1],seg[typ][2*node+1][1]);
	return 0;
}
int l[1234],r[1234];
int dogeneral(int pos,int n){
	int len,i;
	if(pos==0){
		len=l[pos];
	}
	else{
		len=l[pos]-r[pos-1];
	}
	rep(i,2*n+1){
		haha[i]=inf;
		lol[i]=inf;
	}
	rep(i,2*n+1){
		if(i+len<=2*n)
			haha[i+len]=min(haha[i+len],dp[i]);
	}
	rep(i,2*n+1){
		if(i-len>=0)
			lol[i-len]=revdp[i];
	}
	rep(i,2*n+1){
		dp[i]=haha[i];
		revdp[i]=lol[i];
	}
	
}

int main(){
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int i,j;
    rep(i,k){
    	cin>>l[i]>>r[i];
    }
    rep(i,2*n+1){
    	dp[i]=inf;
    	revdp[i]=inf;
    }
    dp[n]=0;
    int len,val;
    rep(j,k){
    	dogeneral(j,n);
    	//cout<<revdp[n+3-8]<<"boo"<<endl;
    	buildseg(0,1,0,2*n);
    	buildseg(1,1,0,2*n);
    	len=r[j]-l[j];
    	rep(i,2*n+1){
			haha[i]=inf;
			lol[i]=inf;
		}
		rep(i,2*n+1){
			if(i+len<=2*n)
				haha[i+len]=min(haha[i+len],dp[i]);
		}
		rep(i,2*n+1){
			if(i-len>=0)
				lol[i-len]=revdp[i];
		}
		rep(i,2*n+1){
			dp[i]=haha[i];
			revdp[i]=lol[i];
		}
    	rep(i,2*n+1){
    		if(len%2==0){
    			val=(query(0,1,0,2*n,max(0,i-len),min(i+len,2*n),i%2));
    			dp[i]=min(val+2,dp[i]);
    			revdp[i]=min(revdp[i],val+1);
    			val=(query(1,1,0,2*n,max(0,i-len),min(i+len,2*n),i%2));
    			dp[i]=min(val+1,dp[i]);
    			revdp[i]=min(revdp[i],val+2);
    		}
    		else{
    			val=(query(0,1,0,2*n,max(0,i-len),min(i+len,2*n),(i+1)%2));
    			dp[i]=min(val+2,dp[i]);
    			revdp[i]=min(revdp[i],val+1);
    			val=(query(1,1,0,2*n,max(0,i-len),min(i+len,2*n),(i+1)%2));
    			dp[i]=min(val+1,dp[i]);
    			revdp[i]=min(revdp[i],val+2);
    		}
    		
    	}
    	
    }
    l[k]=2*n;
    dogeneral(k,n);
    //cout<<revdp[n]<<endl;
   	int mini=min(dp[n],revdp[n]);
   	if(mini<inf){
   		cout<<"Full"<<endl;
   		cout<<mini<<endl;
   	}
   	else{
   		cout<<"Hungry"<<endl;
   	}
    return 0;  
    
}