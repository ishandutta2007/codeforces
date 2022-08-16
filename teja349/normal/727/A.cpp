
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


int main(){
	int a,b,c[10000],i=1;
	
	cin>>a>>b;
	c[0]=b;
	while(a<b){
		if(b%10==1)
		{
			c[i++]=b/10;
			b=b/10;
		}
		else if(b%2==0)
		{
			c[i++]=b/2;
			b=b/2;
		}
		else{
			break;
		}
	}
	if(a==b){
		cout<<"YES"<<endl<<i<<endl;
		int j;
		fd(j,i-1,0){
			cout<<c[j]<<" ";
	}}
	else{
			cout<<"NO"<<endl;
	}

	
}