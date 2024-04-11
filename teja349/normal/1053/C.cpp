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
#define int ll
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}
int bit[212345],bit1[212345];
int update0(int pos,int val){
	while(pos<212345){
		bit[pos]+=val;
		pos+=pos&(-pos);
	}
	return 0;
}
int update1(int pos,int val){
	val%=mod;
	while(pos<212345){
		bit1[pos]+=val;
		bit1[pos]%=mod;
		pos+=pos&(-pos);
	}
	return 0;
}
int query(int pos){
	int ans=0;
	while(pos>0){
		ans+=bit[pos];
		pos-=pos&(-pos);
	}
	return ans;
}
int getquery(int x,int y){
	if(y<x)
		return 0;
	return query(y)-query(x-1);
}
int query1(int pos){
	int ans=0;
	while(pos>0){
		ans+=bit1[pos];
		pos-=pos&(-pos);
	}
	ans%=mod;
	return ans;
}
int getquery2(int x,int y){
	if(y<x)
		return 0;
	return (query1(y)-query1(x-1))%mod;
}
int a[212345],w[212345];
int evaluate(int x,int y,int ans){
	int haha,gg;
	haha=getquery(x,ans);
	haha%=mod;
	gg=haha*a[ans]-getquery2(x,ans);
	gg%=mod;
	haha=getquery(ans+1,y);
	haha%=mod;
	gg+=getquery2(ans+1,y)-haha*a[ans];
	gg%=mod;
	gg+=mod;
	gg%=mod;
	return gg;
}

signed main(){
    std::ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int i;
    f(i,1,n+1){
    	cin>>a[i];
    	a[i]-=i;
    }
    f(i,1,n+1){
    	cin>>w[i];
    	update0(i,w[i]);
    	update1(i,a[i]*w[i]);
    }
    int x,y;
    while(q--){
    	cin>>x>>y;
    	if(x<0){
    		x*=-1;
    		i=x;
    		update1(i,-1*a[i]*w[i]);
    		update0(i,-1*w[i]);
    		w[x]=y;
    		update0(i,w[i]);
    		update1(i,a[i]*w[i]);

    	}
    	else{
    		if(x==y){
    			cout<<0<<endl;
    			continue;
    		}
    		//cout<<x<<" "<<y<<endl;
    		//return 0;
    		int bigsum=getquery(x,y);
    		int high=y;
    		int low=x;
    		int ans=y;
    		int mid;
    		while(low<=high){
    			mid=(low+high)/2;
    			if(getquery(x,mid)*2>=bigsum){
    				ans=mid;
    				high=mid-1;
    			}
    			else{
    				low=mid+1;
    			}
    		}
    		//cout<<bigsum<<"  ";
    		cout<<evaluate(x,y,ans)<<endl;
    		//return 0;
    	}
    }



    return 0;   
}