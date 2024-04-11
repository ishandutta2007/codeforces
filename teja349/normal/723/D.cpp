
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
#define inf 1000*1000*1000+5
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000*1000*1000+7

int n,m,k;
int arr[51][51]={0},visit[51][51]={0};
viii v;

int dfs(int a,int b,int count);
void make_land(int i,int j);
int main(){
	
	int i,j,sum=0;
	char ch;
	cin>>n>>m>>k;
	rep(i,n){
		rep(j,m)
		{
			cin>>ch;
			if(ch=='*')
				arr[i][j]++;
		}
	}
	rep(i,n){
		rep(j,m){
			if(!visit[i][j] && !arr[i][j]){
				int value=dfs(i,j,0);
				if(value!=-1)
					v.pb(mp(value,mp(i,j)));
			}

		}
	}
	sort(v.begin(),v.end());
	int check=v.size();
	viii :: iterator it=v.begin();
	rep(i,v.size()-k){
		sum+=it->ff;
		int a=(it->ss).ff;
		int b=(it->ss).ss;
		make_land(a,b);
		it++;
	}
	cout<<sum<<endl;
	rep(i,n){
		rep(j,m){
			if(arr[i][j]==1)
				cout<<'*';
			else
				cout<<'.';
		}
		cout<<endl;
	}
}

int dfs(int i,int j,int count){
	visit[i][j]=1;
	if(count!=-1)
		count++;
	if(i==n-1||j==m-1||i==0||j==0)
		count=-1;
	if(i<=n-1&&j-1>=0 &&!visit[i][j-1] && !arr[i][j-1])
		count=dfs(i,j-1,count);
	if(i-1>=0&&j<=m-1 &&!visit[i-1][j] && !arr[i-1][j])
		count=dfs(i-1,j,count);
	if(i<=n-1&&j+1<=m-1 &&!visit[i][j+1] && !arr[i][j+1])
		count=dfs(i,j+1,count);
	if(i+1<=n-1&&j<=m-1 &&!visit[i+1][j] && !arr[i+1][j])
		count=dfs(i+1,j,count);
	return count;

}
void make_land(int i,int j){
	//cout<<i<<"  "<<j<<endl;
	arr[i][j]=1;
	if(i<=n-1&&j-1>=0 && !arr[i][j-1]){

		
		make_land(i,j-1);
	}
	if(i-1>=0&&j<=m-1 && !arr[i-1][j]){
		
		make_land(i-1,j);
	}
	if(i<=n-1&&j+1<=m-1  && !arr[i][j+1]){
		
		make_land(i,j+1);
	}
	if(i+1<=n-1&&j<=m-1  && !arr[i+1][j]){
		
		make_land(i+1,j);
	}
}