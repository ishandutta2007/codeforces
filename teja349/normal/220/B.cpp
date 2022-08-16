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
int haha=500;  
struct total{
	int l;
	int r;
	int ind;
};
total query[123456];
int arr[123456],ans[123456];
unordered_map < int , int > mapi;
int answ=0;
int comp(total a,total b){
	if(a.l/haha==b.l/haha)
		return (a.r<b.r);
	return (a.l<b.l);
}

int add(int i){
	mapi[arr[i]]++;
	if(mapi[arr[i]]==arr[i])
		answ++;
	else if(mapi[arr[i]]==arr[i]+1)
		answ--;
	return 0;
}

int remov(int i){
	mapi[arr[i]]--;
	if(mapi[arr[i]]==arr[i])
		answ++;
	else if(mapi[arr[i]]==arr[i]-1)
		answ--;
	return 0;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n,m,i,le,re;
	cin>>n>>m;
	rep(i,n){
		cin>>arr[i];
	}
	rep(i,m){
		cin>>query[i].l>>query[i].r;
		query[i].l--;
		query[i].r--;
		query[i].ind=i;
	}
	sort(query,query+m,comp);
	le=0;
	re=0;
	add(0);
	rep(i,m){
		while(query[i].l<le){
			add(le-1);
			le--;
		}
		while(query[i].r>re){
			add(re+1);
			re++;
		}
		while(query[i].l>le){
			remov(le);
			le++;
		}
		while(query[i].r<re){
			remov(re);
			re--;
		}
		ans[query[i].ind]=answ;

	}
	rep(i,m){
		cout<<ans[i]<<endl;
	}
}