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
int countr=0;
int pres=1,n;
vi vec,vecto;
int inv[123456],a[12345],visit[12345];
int dfs(int val){
	visit[val]=countr;
	//cout<<":boo"<<endl;
	//cycle[countr].pb(val);
	if(!visit[a[val]])
		dfs(a[val]);
	return 0;

}
int dfs1(int cur){
	vecto.pb(cur);
	visit[cur]=1;
	if(!visit[a[cur]]){
		dfs1(a[cur]);
	}
}
int breakcycle(int swaps){
	if(swaps==0){
		return 0;
	}
	int i,mini=123456;
	//cout<<pres<<"dsads ";
	if(a[pres]==pres){
		pres++;
		//visit[pres]
		
		breakcycle(swaps);
		return 0;
	}
	dfs1(a[pres]);
	//cout<<vecto.size()<<endl;
	//cout<<pres<<"asas";
	rep(i,vecto.size()){
		if(vecto[i]!=a[pres]){
			mini=min(mini,inv[vecto[i]]);
		}
		visit[vecto[i]]=0;
	}
	vecto.clear();
	swap(a[pres],a[mini]);
	swap(inv[a[pres]],inv[a[mini]]);
	vec.pb(pres);
	vec.pb(mini);
	pres=1;

	breakcycle(swaps-1);
	return 0;


}
int addcycle(int swaps){
	if(swaps==0){
		return 0;
	}
	int i;
	dfs1(a[1]);
	//cout<<visit[a[1]]<<"dad"<<endl;
	
	f(i,1,n+1){
		if(visit[a[i]]==0){
			break;
		}
	}
	//cout<<i<<endl;
	

	vecto.clear();
	swap(a[1],a[i]);
	swap(inv[a[1]],inv[a[i]]);
	//pres=1;
	vec.pb(1);
	vec.pb(i);
	rep(i,vecto.size()){
		visit[vecto[i]]=0;
	}
	addcycle(swaps-1);
	return 0;


}



int main(){
    std::ios::sync_with_stdio(false);
    //int n;
    cin>>n;
    int i,k;
    f(i,1,n+1){
    	cin>>a[i];
    	inv[a[i]]=i;
    }
    cin>>k;
   	f(i,1,n+1){
   		if(!visit[a[i]]){
   			countr++;
   			//<<i<<endl;
   			dfs(a[i]);
   			
   		}
   	}
   	rep(i,n+1){
   		visit[i]=0;
   	}
   	int swaps=n-countr;
   	swaps-=k;
   	//cout<<swaps<<endl;
   	if(swaps>=0){
   		breakcycle(swaps);
   	}
   	else{
   		addcycle(-1*swaps);
   	}
   	cout<<vec.size()/2<<endl;
   	rep(i,vec.size()){
   		cout<<vec[i]<<" ";
   	}
    return 0;      

}