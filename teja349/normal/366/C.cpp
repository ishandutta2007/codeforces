
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
vector < bitset<10105> > vec(10105);
int a[200],b[200];
int main(){
	std::ios::sync_with_stdio(false);
	int n,k,i,j;
	cin>>n>>k;
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n){
		cin>>b[i];
	}
	vec[0][0]=1;
	int ans=0;
	rep(i,n){
		fd(j,10000,a[i]){
			//cout<<(vec[j]<<k)<<endl;
			vec[j]|=(vec[j-a[i]]<<b[i]);
		
		}
	//	cout<<endl<<endl<<endl;

	}
	//cout<<vec[18][9]<<"Dsaasd   "<<endl;
	for(j=k;j<10001;j+=k){
		int val=j/k;
		if(vec[j][val]==1)
			ans=j;
	}
	//cout<vec[10001]
	if(ans==0)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;

}