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
double dp[1005][1005];   
double compute(int w,int b){
	if(w==0){
		return 0;
	}
	if(dp[w][b]!=-1){
		return dp[w][b];
	}
	dp[w][b]=(1.00*w)/(1.00*w+b);

	if(b>=2){
		dp[w][b]+=1.00*b*(b-1)/(w+b)/(w+b-1)*(1.00*w/(w+b-2)*compute(w-1,b-2));

		if(b>=3){
			dp[w][b]+=1.00*b*(b-1)/(w+b)/(w+b-1)*(1.00*(b-2)/(w+b-2)*compute(w,b-3));
		}
		
	}
	return dp[w][b];


}
int main(){
    std::ios::sync_with_stdio(false);
    int w,b;
    cin>>w>>b;
    int i,j;
    rep(i,w+2){
    	rep(j,b+2){
    		dp[i][j]=-1;
    	}
    }
    cout << setprecision (14) << compute(w,b) << endl;
}