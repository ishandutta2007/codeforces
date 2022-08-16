
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
struct total{
	int num;
	int alp;
	int cher;
};
int n,m;
total arr[100];
int dp[100][3][3][3];
string str[100];
int compute(int ind){
	int i=0;
	int j=200;
	int counti=0;
	arr[ind].alp=inf;
	arr[ind].num=inf;
	arr[ind].cher=inf;
	while(j--){
		i+=m;
		i%=m;
		//cout<<endl<<str[ind][i]<<"   "<<i<<endl;
		if('a'<=str[ind][i] && str[ind][i]<='z'){
			//cout<<"hii";
			arr[ind].alp=min(arr[ind].alp,counti);
		}
		else if('0'<=str[ind][i] && str[ind][i]<='9'){
			arr[ind].num=min(arr[ind].num,counti);
		}
		else{
			arr[ind].cher=min(arr[ind].cher,counti);
		}
		counti++;
		i--;
	}
	j=200;
	i=0;
	counti=0;
	while(j--){
		i+=m;
		i%=m;
		//cout<<endl<<str[ind][i]<<"   "<<i<<endl;
		if('a'<=str[ind][i] && str[ind][i]<='z'){
			//cout<<"hii";
			arr[ind].alp=min(arr[ind].alp,counti);
		}
		else if('0'<=str[ind][i] && str[ind][i]<='9'){
			arr[ind].num=min(arr[ind].num,counti);
		}
		else{
			arr[ind].cher=min(arr[ind].cher,counti);
		}
		counti++;
		i++;
	}
	return 0;
}
int mindp(int ind,int x,int y,int z){
	if(x*y*z==1)
		return 0;
	if(ind==n)
		return inf;
	if(dp[ind][x][y][z]!=-1)
		return dp[ind][x][y][z];
	int ans=mindp(ind+1,x,y,z);
	ans=min(ans,mindp(ind+1,1,y,z)+arr[ind].alp);
	ans=min(ans,mindp(ind+1,x,y,1)+arr[ind].cher);
	ans=min(ans,mindp(ind+1,x,1,z)+arr[ind].num);
	dp[ind][x][y][z]=ans;
	return ans;
}
int main(){
	std::ios::sync_with_stdio(false);
	int i,j,k,h;
	rep(i,70){
		rep(j,2){
			rep(k,2){
				rep(h,2){
					dp[i][j][k][h]=-1;
				}
			}
		}
	}
	cin>>n>>m;
	rep(i,n){
			string stre;
			cin>>str[i];
			//str[i]
			//cout<<str[i]<<endl;
			compute(i);	
			//cout<<arr[i].alp<<endl;
	}
	cout<<mindp(0,0,0,0)<<endl;

}