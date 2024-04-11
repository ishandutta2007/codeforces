
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
ll prim[5000009]={0},ans[5000009],pre[5000009];
int main(){
	//std::ios::sync_with_stdio(false);
	int i,j;
	for(i=2;i*i<=5000007;i++){
		if(prim[i]!=0)
			continue;
		for(j=i*i;j<=5000007;j+=i){
			if(prim[j]==0){
				prim[j]=i;
			}
		}
	}
	f(i,2,5000003){
		if(prim[i]==0)
			ans[i]=1;
		else{
			ans[i]=1+ans[i/prim[i]];
		}
	}
	pre[1]=0;
	f(i,2,5000003){
		pre[i]=pre[i-1]+ans[i];
	}

	int t;
	cin>>t;
	while(t--){
		int a,b;
		scanf("%d%d",&b,&a);

		printf("%lld\n",pre[b]-pre[a]);
	}


}