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
vector<vi> vec1(312345),vec2(312346);
int g[123456],p[123456],t[123456];
int cons;
int h,w;
int computeup(int i){
	int val1,val;
	vi::iterator it;
	val1=t[i]-p[i]+cons;
	//int siz=vec[val1][1].size();
	it=upper_bound(vec1[val1].begin(),vec1[val1].end(),p[i]);
	val=vec2[val1].size();
	int siz=vec1[val1].end()-it;
	it--;
	if(val<=siz){
		it+=val;
		cout<<*it<<" "<<h<<endl;
	}
	else{
		cout<<w<<" "<<vec2[val1][siz]<<endl;
	}
	return 0;
}

int computehor(int i){
	
	int val1,val;
	vi::iterator it;
	val1=t[i]-p[i]+cons;
	//int siz=vec[val1][1].size();
	it=upper_bound(vec2[val1].begin(),vec2[val1].end(),p[i]);
	val=vec1[val1].size();
	int siz=vec2[val1].end()-it;
	
	it--;
	if(val<=siz){
		it+=val;
		cout<<w<<" "<<*it<<endl;
	}
	else{
		cout<<vec1[val1][siz]<<" "<<h<<endl;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n>>w>>h;
    cons=100010;
    int i;
    rep(i,n){
    	cin>>g[i]>>p[i]>>t[i];
    	if(g[i]==1)
    		vec1[t[i]-p[i]+cons].pb(p[i]);
    	else
    		vec2[t[i]-p[i]+cons].pb(p[i]);
    }
    //return 0;
    rep(i,212345){
    	sort(vec1[i].begin(),vec1[i].end());
    	sort(vec2[i].begin(),vec2[i].end());
    }
    //return 0;
    rep(i,n){
    	
    	if(g[i]==1)
    		computeup(i);
    	else
    		computehor(i);
    	//flag=0;
    }
    return 0;  
    
}