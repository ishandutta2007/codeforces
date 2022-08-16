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
vector< set<pii> > vec(223456);
int haha[223456];
map<pii,int> mapi;
int ans[223456];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,u,v,c;
    rep(i,m){
    	cin>>u>>v>>c;
    	haha[u]+=c;
    	haha[v]+=c;
    	vec[u].insert(mp(v,c));
    	vec[v].insert(mp(u,c));
    	mapi[mp(u,v)]=i;
    	
    }
    haha[n]*=2;
    rep(i,n+1){
    	haha[i]/=2;
    }
    
    stack<int> st;
    set<pii>::iterator it;
    st.push(1);
    int cnt=0;
    while(!st.empty()){
    	int cur=st.top();
    	//cout<<cur<<"dsd "<<endl;
    	st.pop();
    	//cout<<cur<<" "<<vec[cur].size()<<endl;
    	for(it=vec[cur].begin();it!=vec[cur].end();it++){
    		haha[it->ff]-=it->ss;
    		cnt++;
    		if(haha[it->ff]==0){
    			st.push(it->ff);
    		}
    		//cout<<cur<<" "<<it->ff<<endl;
    		if(mapi.find(mp(cur,it->ff))!=mapi.end()){
    			ans[mapi[mp(cur,it->ff)]]=0;
    		}
    		else{
    			ans[mapi[mp(it->ff,cur)]]=1;
    		}

    		vec[it->ff].erase(mp(cur,it->ss));
    	}

    }
    rep(i,m){
    	cout<<ans[i]<<endl;
    }
    return 0;  
    
}