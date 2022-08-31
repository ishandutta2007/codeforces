//raja1999
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
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
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
int a[21234];
int main(){
	//std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int i;
	double val;
	int mini=inf;
	int sumi=0;
	int counti=0;
	rep(i,2*n){
		cin>>val;
		val*=1000;
		a[i]=(int)(val+0.5);
		
		a[i]=a[i]%1000;
	//	cout<<a[i]<<" ";
		if(a[i]==0)
			counti++;
		sumi+=a[i];
		//cout<<a[i]<<" "<<sumi<<endl;
	}
	int lol=inf,maxi;
	mini=max(counti-n,0);
	maxi=min(counti,n);
	f(i,mini,maxi+1){
		lol=min(abs((n-i)*1000-sumi),lol);
		//cout<<i<<endl;
	}
	//cout<<sumi<<endl;
	val=lol*1.000;
	val/=1000.00;
	//cout<<val<<endl;
	printf("%.3f\n",val);
	
}