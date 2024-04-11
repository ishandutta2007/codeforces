
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
int even=2;
int odd=1;
int filler(int val,int n);
int a[50][50];
int main(){
	int n,i,j;
	cin>>n;
	filler(0,n-1);
	
		
	
	rep(i,n){
		rep(j,n){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	//cout<<a[2][1]<<endl;
	

}
int filler(int val,int n){
	int i;
	if(val==n){
		a[val][n]=odd;
		return 0;
	}
	f(i,val,n){
		a[val][i]=odd;
		odd+=2;
		a[n][i+1]=odd;
		
		odd+=2;
		a[i+1][val]=even;
		even+=2;
		a[i][n]=even;
		even+=2;

	}
	swap(a[val][val],a[(val+n)/2][val]);
		swap(a[n][n],a[(val+n)/2][n]);
	filler(val+1,n-1);
	return 0;



}