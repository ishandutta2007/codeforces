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
#define pddqueue priority_queue< pii,vii ,greater< pii > >
//std::ios::sync_with_stdio(false); 
ll s,m,n;
int c[123456],a[123456],b[123456],res[123456];
vii vec;
struct total{
	int fe,se,ind;
};
vector< total > vecst;
total boo;
int comp(total a,total b){
	return a.fe<b.fe;
}
int check(int val){
	int pres=val;
	pdqueue pq;
	int i,j=n-1;
	ll cost=0;
	fd(i,m-1,0){
		while(j>=0 && vecst[j].fe>=vec[i].ff){
			pq.push(vecst[j].se);
			j--;
		}
		if(pres==val){
			pres=0;
			if(pq.empty()){
				return 0;
			}
			cost+=pq.top();
			pq.pop();
		}
		pres++;

	}
	if(cost<=s){
		return 1;
	}
	else{
		return 0;
	}

}
int rcover(int val){
	int pres=val;
	pddqueue pq;
	int i,j=n-1;
	ll cost=0;
	int cur;
	
	fd(i,m-1,0){
		while(j>=0 && vecst[j].fe>=vec[i].ff){
			pq.push(mp(vecst[j].se,vecst[j].ind));
			j--;
		}
		if(pres==val ){
			pres=0;
			if(pq.empty()){
				return 0;
			}
			cur=pq.top().ss;
			cost+=pq.top().ff;
			pq.pop();
		}
		pres++;
		res[vec[i].ss]=cur;

	}
	if(cost<=s){
		return 1;
	}
	else{
		return 0;
	}

}
int main(){
    std::ios::sync_with_stdio(false);
    int i;
    cin>>n>>m>>s;
    rep(i,m){
    	cin>>a[i];
    	vec.pb(mp(a[i],i));
    }
    rep(i,n){
    	cin>>b[i];
    }
    rep(i,n){
    	cin>>c[i];
    	boo.fe=b[i];
    	boo.se=c[i];
    	boo.ind=i;
    	vecst.pb(boo);
    }
    sort(vec.begin(),vec.end());
    sort(vecst.begin(),vecst.end(),comp);
    int high=m;
    int low=1;
    int mid;
    int ans=-1;
    while(low<=high){
    	mid=(high+low)/2;
    	//cout<<mid<<" "<<check(mid)<<endl;
    	if(check(mid)){
    		ans=mid;
    		high=mid-1;
    	}
    	else{
    		low=mid+1;
    	}
    }
    if(ans==-1){
    	cout<<"NO"<<endl;
    	return 0;
    }
    cout<<"YES"<<endl;
    rcover(ans);
    rep(i,m){
    	cout<<res[i]+1<<" ";
    }
    return 0;      

}