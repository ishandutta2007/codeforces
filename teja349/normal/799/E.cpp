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
vector<vi> adj(10);
ll haha[5][200009];
int c[212345];
ll iinf;
int n,m,k;
int compute(int mid,int a,int com){
	int sumi=0;
	int val;
	sumi+=upper_bound(adj[0].begin(),adj[0].end(),mid)-adj[0].begin();
	val=upper_bound(adj[1].begin(),adj[1].end(),mid)-adj[1].begin();
	sumi+=max(val-a,0);
	val=upper_bound(adj[2].begin(),adj[2].end(),mid)-adj[2].begin();
	sumi+=max(val-a,0);
	val=upper_bound(adj[3].begin(),adj[3].end(),mid)-adj[3].begin();
	sumi+=max(val-com,0);
	return sumi;
} 
ll worked(int mid,int a,int com){
	ll sumi=0;
	int val;
	val=upper_bound(adj[0].begin(),adj[0].end(),mid)-adj[0].begin();
	if(val!=0)
		sumi+=haha[0][val-1];

	val=upper_bound(adj[1].begin(),adj[1].end(),mid)-adj[1].begin();
	if(max(val,a)!=0)
		sumi+=haha[1][max(val,a)-1];
	val=upper_bound(adj[2].begin(),adj[2].end(),mid)-adj[2].begin();
	if(max(val,a)!=0)
		sumi+=haha[2][max(val,a)-1];
	val=upper_bound(adj[3].begin(),adj[3].end(),mid)-adj[3].begin();
	if(max(val,a)!=0)
		sumi+=haha[3][max(val,com)-1];
	return sumi;
} 

ll solver(int com){
	int a=k-com;
	ll ans=0;
	if(a>adj[1].size()){
		return iinf;
	}
	if(a>adj[2].size()){
		return iinf;
	}
	if(2*a+com >m)
		return iinf;

	int left=m-2*a-com;
	if(left==0){
		if(a!=0){
			ans+=haha[1][a-1];
			ans+=haha[2][a-1];
		}
		//cout
		if(com!=0){
			ans+=haha[3][com-1];
		}

		return ans;
	}
	//cout<<left<<endl;
	int low=0;
	int high=inf;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		//cout<<mid<<endl;
		int val1=compute(mid,a,com);
		int val2=compute(mid-1,a,com);
		//cout<<val1<<" "<<val2<<endl;
		if(val2<left && val1>=left){
			//cout<<(val2<left && val1>=left)<<endl;
			ans=worked(mid,a,com)-(val1-left)*mid;
			return ans;
		}
		else if(val2>=left){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}

}
int hahaa[212345];
int main(){
    std::ios::sync_with_stdio(false); 
    int i,a,val,j;
    iinf=inf;
    iinf*=iinf;
    ll mini=iinf;
    cin>>n>>m>>k;
    rep(i,n){
    	cin>>c[i];
    }
    cin>>a;
    rep(i,a){
    	cin>>val;
    	val--;
    	hahaa[val]++;
    }
    cin>>a;
    rep(i,a){
    	cin>>val;
    	val--;
    	hahaa[val]+=2;
    }
    //cout<<hahaa[0]<<endl;
    rep(i,n){
    	adj[hahaa[i]].pb(c[i]);
    }
    rep(i,5){
    	sort(adj[i].begin(),adj[i].end());
    }
    rep(i,4){
    	if(!adj[i].empty()){
    		haha[i][0]=adj[i][0];
    		f(j,1,adj[i].size()){
    			haha[i][j]=haha[i][j-1]+adj[i][j];
    		}
    	}
    }
    int lolu=adj[3].size();
    rep(i,min(k+1,lolu+1)){
    	ll mama=solver(i);
    	mini=min(mama,mini);

    	//cout<<i<<" "<<mama<<endl;
    }
   // return 0;
    //cout<<mini<<endl;
    if(mini==iinf)
    	cout<<-1<<endl;
    else
    	cout<<mini<<endl;

}