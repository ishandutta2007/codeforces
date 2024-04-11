
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
int a[40];
int visit[320][320][30][4][4]={0};
int dp[320][320]={0};
int filltheg(int x,int y,int val,int p,int q);
int n;
int main(){
	
	cin>>n;
	int i,j;
	rep(i,n){
		cin>>a[i];
	}
	ll sumi=0;
	filltheg(160,160,0,1,0);
	rep(i,320){
		rep(j,320){
			sumi+=dp[i][j];
		}
	}
	cout<<sumi<<endl;
}
int filltheg(int x,int y,int val,int p,int q){
	if(val==n)
		return 0;
	if(visit[x][y][val][p][q]==1)
		return 0;
	visit[x][y][val][p][q]=1;
	int i;
	f(i,1,a[val]+1){
		dp[x+i*p][y+i*q]=1;
	}
	i--;
		int x1,y1,y2,x2;	
		y1=q-p;
		y2=q+p;
		x1=p+q;
		x2=p-q;
		if(x1!=0){
			x1/=abs(x1);
		}
		if(y1!=0){
			y1/=abs(y1);
		}
		if(y2!=0){
			y2/=abs(y2);
		}
		if(x2!=0){
			x2/=abs(x2);
		}
	
	
	
	filltheg(x+i*p,y+i*q,val+1,x1,y1);
	filltheg(x+i*p,y+i*q,val+1,x2,y2);
	return 0;

}