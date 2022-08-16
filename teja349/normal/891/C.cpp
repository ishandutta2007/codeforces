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
stack<pii> st;
int ans=0,waste=0;
vector<vi> hahar(512345);
vector<vii> boo(512345);
int u[512345],v[512345],w[512345];
int dsu[512345],haha[512345];
int par(int val){
	if(dsu[val]<0)
		return val;
	return par(dsu[val]);
}
int addedge(int i){
	int x,y;
	x=u[i];
	y=v[i];
	x=par(x);
	y=par(y);
	if(x==y || waste==1){
		waste=1;
		ans=1;
		st.push(mp(-1,-1));
		return 0;
	}
	if(dsu[x]<dsu[y]){
		st.push(mp(y,dsu[y]));
		dsu[x]+=dsu[y];
		dsu[y]=x;
	}
	else{
		st.push(mp(x,dsu[x]));
		dsu[y]+=dsu[x];
		dsu[x]=y;
	}
	return 0;
}
int removeedge(){
	ans=0;
	waste=0;
	pii papa=st.top();
	st.pop();
	if(papa.ff==-1)
		return 0;
	int y=par(papa.ff);
	dsu[y]-=papa.ss;
	dsu[papa.ff]=papa.ss;
	return 0;
}
int permaedge(int i){
	int x,y;
	x=u[i];
	y=v[i];
	x=par(x);
	y=par(y);
	if(x==y)
		return 0;
	if(dsu[x]<dsu[y]){
		dsu[x]+=dsu[y];
		dsu[y]=x;
	}
	else{
		dsu[y]+=dsu[x];
		dsu[x]=y;
	}
	return 0;
}
int main(){
    //std::ios::sync_with_stdio(false);
    int n,m;
   // cin>>n>>m;
    scanf("%d",&n);
    scanf("%d",&m);
    int i;
    rep(i,m){
    //	cin>>u[i]>>v[i]>>w[i];
    	scanf("%d",&u[i]);
    	scanf("%d",&v[i]);
    	scanf("%d",&w[i]);
    	u[i]--;
    	v[i]--;
    	hahar[w[i]].pb(i);
    }
    rep(i,n+10){
    	dsu[i]=-1;
    }
    int q;
    //cin>>q;
    scanf("%d",&q);
    int j,k,lol,val;
    rep(i,q){
    	//cin>>val;
    	scanf("%d",&val);
    	rep(j,val){
    		//cin>>lol;
    		scanf("%d",&lol);
    		lol--;
    		boo[w[lol]].pb(mp(i,lol));
    	}
    }
    rep(i,5*100000+13)
    	sort(boo[i].begin(),boo[i].end());
    int previ,ii;
    rep(i,5*100000+13){
    	previ=-1;
    	rep(j,boo[i].size()){
    		if(previ==-1){
    			addedge(boo[i][j].ss);
    			previ=boo[i][j].ff;
    			k=0;
    		}
    		else if(previ==boo[i][j].ff){
    			addedge(boo[i][j].ss);
    		}
    		else{
    			haha[boo[i][j-1].ff]|=ans;
    			f(ii,k,j){
    				removeedge();
    			}
    			previ=boo[i][j].ff;
    			addedge(boo[i][j].ss);
    			k=j;
    		}

    	}
    	if(!boo[i].empty()){
    		haha[boo[i][boo[i].size()-1].ff]|=ans;
    	}
    	f(ii,k,boo[i].size()){
    		removeedge();
    	}
    	rep(j,hahar[i].size()){
    		permaedge(hahar[i][j]);
    	}
    }	
    rep(i,q){
    	if(haha[i]==1){
    		printf("NO\n");
    	}
    	else{
    		printf("YES\n");
    	}
    }
    return 0;  
    
}