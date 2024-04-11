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
int dp[201][201][201]={0};
int compute(int b,int g,int r,int rofl){

	if(r<0 || b<0 || g<0)
	return 0;
	if(rofl==1){
		b++;
	}
	else if(rofl==2)
		g++;
	else if(rofl==3)
		r++;
	//cout<<"hii";
	if(r+g+b==1)
	{
		if(r)
			return 4;
		if(g)
			return 2;
		if(b)
			return 1;
	}
	//cout<<"yoo";
	if(dp[b][g][r])
		return dp[b][g][r];
	dp[b][g][r]=compute(b-2,g,r,1);
	dp[b][g][r]|=compute(b,g-2,r,2);
	dp[b][g][r]|=compute(b,g,r-2,3);
	dp[b][g][r]|=compute(b-1,g+1,r-1,0);
	dp[b][g][r]|=compute(b-1,g-1,r+1,0);
	dp[b][g][r]|=compute(b+1,g-1,r-1,0);
	return dp[b][g][r];
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,i,r=0,b=0,g=0;
    string s;
    cin>>n;
    cin>>s;
    rep(i,n){
    	if(s[i]=='R')
    		r++;
    	else if(s[i]=='B')
    		b++;
    	else
    		g++;
    }
    int val=compute(b,g,r,0);
    if(val%2){
    	cout<<"B";
    }
    val/=2;
    if(val%2)
    	cout<<"G";
    val/=2;
    if(val%2)
    	cout<<"R";
    return 0;

}