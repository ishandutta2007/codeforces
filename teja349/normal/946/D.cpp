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
#define inf (1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
int dp[512][512],visit[512][512],n,wow[512][512];
string str[523];
int computewow(int day)
{
	int i,j;
	rep(i,501){
		wow[day][i]=inf;
	}
	int ans=0;
	rep(i,str[day].length()){
		ans=0;
		f(j,i,str[day].length()){
			if(str[day][j]=='1')
				ans++;
			wow[day][ans]=min(wow[day][ans],j-i+1);
		}
	}
	return 0;
}
int compute(int day,int left){
	if(left<0)
		return inf;
	if(day==n)
		return 0;
	if(visit[day][left])
		return dp[day][left];
	visit[day][left]=1;
	int i,st=inf,classes=0,attend,bunk;
	rep(i,str[day].length()){
		if(str[day][i]=='1')
			st=min(st,i);
		classes+=str[day][i]-'0';
	}
	if(classes==0){
		dp[day][left]=compute(day+1,left);
		return dp[day][left];
	}
	else{
		dp[day][left]=compute(day+1,left-classes);
	}
	//attend=classes;
	//bunk=0;
	//dp[day][left]=inf;
	rep(i,classes){
		
		dp[day][left]=min(dp[day][left],compute(day+1,left-i)+wow[day][classes-i]);
		
		
	}
	return dp[day][left];
}
int main(){
    std::ios::sync_with_stdio(false);
    int m,k;
    cin>>n>>m>>k;
    int i,j;
    
    rep(i,n){
    	cin>>str[i];
    	computewow(i);
    }
    cout<<compute(0,k)<<endl;
    return 0;  
    
}