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
int trie[300056][26],dumb[300056][26];
int level[323456],subtree[323456],subsss[323456],bigchild[323456],haha[323456];   
int dfs1(int u){
	//cout<<u<<endl;
	subtree[u]=1;
	int i;
	int maxi=0;
	bigchild[u]=-1;
	rep(i,26){
		//cout<<trie[u][i];
		if(trie[u][i]){
			level[trie[u][i]]=level[u]+1;
			dfs1(trie[u][i]);
			subtree[u]+=subtree[trie[u][i]];
			
			if(subtree[trie[u][i]]>maxi){
				maxi=subtree[trie[u][i]];
				bigchild[u]=trie[u][i];
			}
		}
	}
	return 0;
}
int counti=2;
int combine(int node,int node1){
	//int node=1;
	int i;
	rep(i,26){
		if(trie[node1][i]){
			if(dumb[node][i]==0){
				dumb[node][i]=counti++;
				
			}
			combine(dumb[node][i],trie[node1][i]);
		}

	}
	return 0;


}
int dfs3(int cur){
	subsss[cur]=1;
	int i;
	rep(i,26){
		if(dumb[cur][i]){
			dfs3(dumb[cur][i]);
			subsss[cur]+=subsss[dumb[cur][i]];
		}
	}
	return 0;
}
int flag=0;
int calculate(int node,int node1){
	//int node=1;

	int i,sumi=0;
	rep(i,26){
		if(dumb[node][i]){
			
			if(trie[node1][i]){
				sumi+=calculate(dumb[node][i],trie[node1][i]);
				
			}
			else{
				
				sumi+=subsss[dumb[node][i]];
			}
		}
	}
	
	//cout<<sumi<<endl;
	return sumi;
}
int treeclear(){
	int i,j;

	f(i,1,counti){
		rep(j,26){
			dumb[i][j]=0;

		}
		subsss[i]=0;
	}
	
	counti=2;
	return 0;

}
int dfs2(int node){
	int i,u=node;
	if(subtree[node]==1){
		haha[node]=1;
		return 0;
	}
	rep(i,26){
		if(trie[node][i]){
			dfs2(trie[node][i]);
		}
	}

	rep(i,26){
		if(trie[u][i] && bigchild[u]!=trie[u][i])
			combine(1,trie[u][i]);
	}
	dfs3(1);
	
	haha[u]=calculate(1,bigchild[u]);
	//if(u==4)
		//cout<<haha[u]<<endl;
	haha[u]+=subtree[bigchild[u]];
	//cout<<
	//flag=0;
	treeclear();
	return 0;
}
int ans[323456];
int main(){
    std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int i,u,v,val;
	char ch;
	rep(i,n-1){
		cin>>u>>v>>ch;
		val=ch-'a';
		trie[u][val]=v;
	}    
	//return 0;
	level[1]=0;
	dfs1(1);
	//return 0;
	dfs2(1);
	int maxi=0,baba=-1,remem;
    f(i,1,n+1){
    	ans[level[i]]+=subtree[i]-haha[i];
    	maxi=max(maxi,level[i]);
    	//cout<<haha[i]<<" "<<i<<endl;
    }
    rep(i,maxi+1){
    	//cout<<i<<" "<<ans[i]<<endl;
    	if(ans[i]>baba){
    		baba=ans[i];
    		remem=i;
    	}
    }
   // cout<<subtree[4]<<" "<<haha[4]<<endl;
    cout<<subtree[1]-baba<<" "<<remem+1<<endl;

}