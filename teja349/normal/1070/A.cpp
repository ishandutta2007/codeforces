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
int dist[505][5015];
int d,s;
vector<vii> rev(5123456);
//int dist2[505][5015];
int bfs2(pii st,pii target){
	int i,j;
	pii papa;
	int u,v;
	rep(i,d+2){
    	rep(j,s+12){
    		dist[i][j]=inf;
    	}
    }
    dist[st.ff][st.ss]=0;
    queue<pii> que;
    que.push(st);
    while(!que.empty()){
    	papa=que.front();
    	if(papa==target)
    		break;
    	que.pop();
    	int elem=papa.ff*(s+2)+papa.ss;
    	rep(j,rev[elem].size()){
    		u=rev[elem][j].ff;
    		v=rev[elem][j].ss;
    		if(dist[u][v]==inf){
    			dist[u][v]=dist[papa.ff][papa.ss]+1;
    			que.push(mp(u,v));
    			
    		}
    	}
    	
    }
    return 0;
}

int bfs1(pii st,pii target){
	int i,j;
	pii papa;
	int u,v;
	rep(i,d+2){
    	rep(j,s+12){
    		dist[i][j]=inf;
    	}
    }
    dist[st.ff][st.ss]=0;
    queue<pii> que;
    que.push(st);
    while(!que.empty()){
    	papa=que.front();
    	if(papa==target)
    		break;
    	que.pop();
    	rep(i,10){
    		u=papa.ff;
    		v=papa.ss;
    		u*=10;
    		u+=i;
    		u%=d;
    		v+=i;
    		if(v>s)
    			continue;
    		
    		if(dist[u][v]==inf){
    			dist[u][v]=dist[papa.ff][papa.ss]+1;
    			que.push(mp(u,v));
    		}
    		if(dist[u][v]==dist[papa.ff][papa.ss]+1){
    			rev[u*(s+2)+v].pb(papa);
    		}
    		
    	}
    }
    return 0;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>d>>s;
    bfs1(mp(0,0),mp(0,s));
    int len=dist[0][s];
    //cout<<len<<endl;
    if(len==inf){
    	cout<<-1<<endl;
    	return 0;
    }
    bfs2(mp(0,s),mp(0,0));
    
    int haha=0;
    int u,v,wow=0;
    int i,j;
    rep(i,len){
    	//cout<<i<<" ";
    	rep(j,10){
    		u=haha*10+j;
    		u%=d;
    		v=wow+j;
    		if(v>s)
    			continue;
    		if(i+1+dist[u][v]==len){
    			cout<<j;
    			haha=u;
    			wow=v;
    			break;
    		}
    	}
    }


       
}