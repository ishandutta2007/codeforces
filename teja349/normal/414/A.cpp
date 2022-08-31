
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
int main(){
	int n,k,i;int counti=1;
	cin>>n>>k;
	int n1=n/2;
	if(k<n1){
		cout<<-1<<endl;
		return 0;
	}
	if(k==0){
		cout<<1<<endl;
		return 0;
	}
	if(n1==0){
		cout<<-1;
		return 0;
	}

	if(n1==1){

		cout<<k<<" "<<2*k<<" ";
		if(n==3)
			cout<<mod-9;
	}
	else{
		cout<<k-n1+1<<" "<<2*(k-n1+1)<<" ";
		rep(i,n1-1){
			while(counti==k-n1+1||counti+1==k-n1+1||counti+1==2*(k-n1+1)||counti==2*(k-n1+1))counti++;
			cout<<counti<<" "<<counti+1<<" ";
			counti+=2;
		}
		if(n&1==1)
			cout<<mod-9;
	}
}