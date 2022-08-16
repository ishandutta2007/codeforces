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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 #define int ll
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

int bit[2][512345];
int update(int typ,int pos,int val){
	while(pos<412345){
		bit[typ][pos]+=val;
		pos+=pos&(-pos);
	}
	return 0;
}
int query(int typ,int pos){
	int ans=0;
	while(pos>0){
		ans+=bit[typ][pos];
		pos-=pos&(-pos);
	}
	return ans;
}
// int getans(int l,int r){
// 	return query(r)-query(l-1);
// }
struct total{
	ll x,r,q,low,high,mid;
};
map<ll,int> mapi;
total wow[123456];
bool comp(total a,total b){
	return a.q<b.q;
}
bool comp1(total a,total b){
	return a.x<b.x;
}
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int i;
    total haha;
    int remem;
    ll xx,rr,qq;
    rep(i,n){
    	cin>>xx>>rr>>qq;
    	haha.x=xx;
    	haha.r=rr;
    	haha.q=qq;
    	mapi[xx-rr]++;    	
    	wow[i]=haha;
    	mapi[xx]++;
    	mapi[xx+rr]++;
    }
    int counter=2;
    map<ll,int>::iterator it;
    for(it=mapi.begin();it!=mapi.end();it++){
    	it->ss=counter++;
    }
    rep(i,n){
    	wow[i].low=mapi[wow[i].x-wow[i].r];
    	wow[i].high=mapi[wow[i].x+wow[i].r];
    	wow[i].mid=mapi[wow[i].x];
    }
    set<pll> setr;
    sort(wow,wow+n,comp);
    pll papa;
    int ind;
    ll bigg=0;
    int j=0;
    i=0;
    vector<total> vec;
    while(i<n){
    	while(wow[j].q<wow[i].q-k){
    		j++;
    	}
    	int gg=j;
    	remem=j;
    	vec.clear();
    	while(gg<n && wow[gg].q<=wow[i].q){
    		vec.pb(wow[gg]);
    		gg++;
    	}
    	sort(all(vec),comp1);
    	rep(j,vec.size()){
    		while(!setr.empty()){
    			papa=*(setr.begin());
    			if(papa.ff<vec[j].x){
    				setr.erase(papa);
    				update((vec[papa.ss].q==wow[i].q)?1:0,vec[papa.ss].mid,-1);
    			}
    			else{
    				break;
    			}
    		}
    		bigg+=query(1,vec[j].mid)-query(1,vec[j].low-1);
    		if(vec[j].q==wow[i].q){
    			bigg+=query(0,vec[j].mid)-query(0,vec[j].low-1);
    		}

    		update((vec[j].q==wow[i].q)?1:0,vec[j].mid,1);
    		setr.insert(mp(vec[j].x+vec[j].r,j));
    	}
    	j=remem;
    	while(!setr.empty()){
    		papa=*(setr.begin());
    		setr.erase(papa);
    		update(vec[papa.ss].q==wow[i].q,vec[papa.ss].mid,-1);
    	}
    	i=gg;
    }
    cout<<bigg<<endl;

    return 0;   
}