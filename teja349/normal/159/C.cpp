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
int bit[26][200045];
//bool occu[26][200045];
int haha[21234];char lol[21234];int reali[21234],ptr[21234],ct[123];
vector<vi> adj(123); 
int bitquery(int val,int ch){
	int sumi=0;
	while(val>0){
		sumi+=bit[ch][val];
		val-=val&(-val);
	}
	return sumi;
}
int update(int val,int ch){
	while(val<200004){
		bit[ch][val]++;
		val+=val&(-val);
	}
	return 0;
}
int query(int req,int ch){
	int low=req;
	int high=200002;
	int mid,ans=-1,val;
	//return 0;
	while(low<=high){
		mid=(low+high)/2;
		val=bitquery(mid,ch);
		if(mid-val>=req){
			high=mid-1;
			ans=mid;
		}
		else{
			low=mid+1;
		}
	}
	if(ans==-1){
		assert(0);
	}
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    int k;
    cin>>k;
    string s,ans="";
    cin>>s;
    int i,j,val;
    int n;
    cin>>n;
    rep(i,n){
    	cin>>haha[i]>>lol[i];
    	reali[i]=query(haha[i],lol[i]-'a');
    	//return 0;
    	//cout<<reali[i]<<" "<<lol[i]<<endl;
    	update(reali[i],lol[i]-'a');
    }   
    rep(i,n){
    	adj[lol[i]-'a'].pb(reali[i]);
    }
    rep(i,26){
    	sort(adj[i].begin(),adj[i].end());
    }
    rep(i,26){
    	adj[i].pb(-1);
    	ptr[i]=0;
    	ct[i]=0;
    }

    rep(j,k){
    	rep(i,s.length()){
    		val=s[i]-'a';
    		ct[val]++;
    		if(adj[val][ptr[val]]==ct[val]){
    			ptr[val]++;
    		}
    		else{
    			ans+=s[i];
    		}
    	}
    }
    cout<<ans<<endl;



}