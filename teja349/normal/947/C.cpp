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

//std::ios::sync_with_stdio(false);   
int trie[9000008][2],cnt[9000008];
int a[312345],p[312345];
int counter=2;
int inserttrie(int val){
	int node=1,bit;
	int i=29;
	while(i>=0){
		cnt[node]++;
		if(val&(1<<i)){
			bit=1;
		}
		else
			bit=0;
		if(!trie[node][bit])
			trie[node][bit]=counter++;
		node=trie[node][bit];
		//trie[node][]
		i--;
	}
	cnt[node]++;
	return 0;
}
int removeelem(int val){
	int node=1,bit;
	int i=29;
	while(i>=0){
		cnt[node]--;
		if(val&(1<<i)){
			bit=1;
		}
		else
			bit=0;
		if(!trie[node][bit])
			trie[node][bit]=counter++;
		node=trie[node][bit];
		//trie[node][]
		i--;
	}
	cnt[node]--;
	return 0;
}
int getmin(int val){
	int i=29,ans=0,bit,node=1,haha=0;
	while(i>=0){
		if(val&(1<<i)){
			bit=1;
		}
		else
			bit=0;
		if(cnt[trie[node][bit]]){
			if(bit==1)
				haha+=(1<<i);
			node=trie[node][bit];
		}
		else{
			if(bit==0)
				haha+=(1<<i);
			ans+=(1<<i);
			node=trie[node][bit^1];
		}
		i--;
	}
	//cout<<haha<<endl;
	removeelem(haha);
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j;
    rep(i,n){
    	cin>>a[i];
    }
    rep(i,n){
    	cin>>p[i];
    	inserttrie(p[i]);
    }
    rep(i,n){
    	cout<<getmin(a[i])<<" ";
    	//removeelem(p[i]);
    }
    return 0;  
    
}