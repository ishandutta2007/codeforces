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
int a[123456]={0},h[123456]={0},g[123456]={0},ginv[123456]={0},hinv[123456]={0},val[123456]={0};  
int k=1;
int main(){
	std::ios::sync_with_stdio(false);
	int n,i;
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
		val[a[i]]++;
	}
	rep(i,123456){
		if(val[i]!=0)
		{
			if(a[i]!=i)
			{
				cout<<-1<<endl;
				return 0;

			}
			else{
				h[k]=i;
				hinv[i]=k;
				g[i]=k;
				ginv[k]=i;
				k++;
			}
		}


	}
	cout<<k-1<<endl;
	f(i,1,n+1){
		if(g[i]==0)
		{
			int value=hinv[a[i]];
			g[i]=value;
		}
	}
	//cout<<k<<endl;
	f(i,1,n+1){
		cout<<g[i]<<" ";
	}
	cout<<endl;
	f(i,1,k){
		cout<<h[i]<<" "; 
	}
	cout<<endl;

}