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
int p[412345],bit[412345],haha[412345];

int query(int val){
	int ans=0;
	while(val>0){
		ans+=bit[val];
		val-=val&(-val);
	}
	return ans;
}
int update(int last){
	while(last>0 && haha[last-1]==1){
		last--;
	}
	return last;
}
int getcur(int val){
	int haha=val;
	val=query(val);

	
	haha-=val;
	cout<<haha<<endl;
	return haha;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,val,reqd;
    rep(i,n){
    	cin>>p[i];
    }
    cout<<1<<" ";
    int last=n+1;
    rep(i,n){
    	haha[p[i]]=1;
    	if(last==p[i]+1){
    		
    		last=update(last);
    		cout<<last-n+i+1<<endl;
    	}
    	else{
    		cout<<last-n+i+1<<endl;
    	}
    }
    return 0;  
    
}