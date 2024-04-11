
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
int level[1000];
int visit[1000]={0};
int crush[1000];

int dfs(int i,int leveli){
	level[i]=leveli;
	visit[i]=1;
	int val=crush[i];
	if(visit[val]==0){
		return dfs(val,leveli+1);
	}
	else{
		if(level[val]==0){
			return level[i]-level[val]+1;
		}
		else return -1;
	}


}


ll gcd(ll a,ll b){
	if(b!=0)
		return gcd(b,a%b);
	return a;
}

int main(){
	ll ans=1;
	std::ios::sync_with_stdio(false);  

	int n,i;
	cin>>n;
	rep(i,n){

		cin>>crush[i];
		crush[i]--;
	}

	rep(i,n){
		if(visit[i]!=0)
			continue;

		int val=dfs(i,0);
		//cout<<i<<" "<<val<<endl;
		level[i]=1;
		if(val==-1){
			cout<<-1<<endl;
			return 0;
		}
		else if(val!=0){
			if(val%2==0)
				val=val/2;
			if(ans>val)
				ans=(ans*val)/gcd(ans,val);
			else
				ans=(ans*val)/gcd(val,ans);
		}
	}
	cout<<ans<<endl;
}