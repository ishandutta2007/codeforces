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
int trie[312345*41][2];
int lazy[312345*41],lol[312345*41];
int counter=2; 
int add(int x){
	int node=1;
	int i=19,val;
	node=1;
	while(i>=0){
		if(x&(1<<i)){
			val=1;
		}
		else
			val=0;
		//cout<<i<<" "<<val<<endl;
		if(trie[node][val]==0){
			trie[node][val]=counter++;
		}
		node=trie[node][val];
		lol[node]++;
		i--;
	}
	return 0;
}
int update(int x){
	lazy[1]^=x;

}

int updatelazy(int node,int ind){
	if(lazy[node]&(1<<ind)){
		
		if(trie[node][0]==0 ){
			trie[node][0]=counter++;
		}
		if(trie[node][1]==0){
			trie[node][1]=counter++;
		}
		//cout<<ind<<" "<<lol[trie[node][0]]<<endl;
		//swap(lol[trie[node][0]],lol[trie[node][1]]);
		swap(trie[node][0],trie[node][1]);
		lazy[trie[node][0]]^=lazy[node];
		lazy[trie[node][1]]^=lazy[node];
		//swap(lazy[trie[node][0]],lazy[trie[node][1]]);
		//cout<<ind<<" "<<lol[trie[node][0]]<<endl;
	}
	else{
		if(trie[node][0]){
			lazy[trie[node][0]]^=lazy[node];
		}
		if(trie[node][1]){
			lazy[trie[node][1]]^=lazy[node];
		}

	}
	lazy[node]=0;

}
int query(){
	int node=1;
	int i=19;
	int expe=1<<19;
	int ans=0;
	//cout<<trie[1][0]<<endl;
	while(i>=0){
		
		if(lazy[node]){
			updatelazy(node,i);
		}
		
		if(trie[node][0]==0){
			
			return ans;
		}
		else if(lol[trie[node][0]]==expe){
			ans+=(1<<i);
			if(!trie[node][1]){
				return ans;
			}
			else{
				node=trie[node][1];
			}
		}
		else{
			//cout<<i<<" "<<lol[trie[node][0]]<<" "<<expe<<endl;
			node=trie[node][0];
		}
		expe/=2;
		i--;

	}
	return ans;//<<endl;
	return 0;
}
int a[312345];
int main(){
    //::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,val,x;
    rep(i,n){
    	scanf("%d",&a[i]);
    	
    }
    sort(a,a+n);
    int prev=-1;
    rep(i,n){
    	if(prev!=a[i]){
    		prev=a[i];
    		add(a[i]);
    	}

    }

    rep(i,m){
    	cin>>x;
    	update(x);
    	printf("%d\n",query());
    }
    return 0;  
    
}