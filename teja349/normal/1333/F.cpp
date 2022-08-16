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
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
 

int pr[1234567],taken[1234567],gg[1234567];
int main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	int i,j;
	vi ans;
	taken[1]=1;
	ans.pb(1);
	for(i=2;i<=n;i++){
		if(pr[i])
			continue;
		gg[i]=i;
		taken[i]=1;
		ans.pb(1);
		for(j=2*i;j<1234567;j+=i){
			pr[j]=1;
			if(gg[j]==0)
				gg[j]=i;
		}
			
	}
	//f(i,1,n+1){
	//	
	//}
	//vi ans;
	int cnt=0,sofar=1;
	for(i=2;i<=n;i++){
		for(j=i;j<=n;j+=i){
			if(pr[j/i]==0 && !taken[j] && j/i<=gg[i]){
				ans.pb(i);
				taken[j]=1;
			}
				//cnt++;
		}	
	}
	f(i,1,n){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}