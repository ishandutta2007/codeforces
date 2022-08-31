
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


int prime(int n);

int main(){
	int n;
	cin>>n;
	if(n==2){
		cout<<1<<endl;
		return 0;
	}
	if(n%2==0){
		cout<<2<<endl;
		return 0;
	}
	if(prime(n)){
		cout<<1<<endl;
		return 0;
	}
	if(prime(n-2)){
		cout<<2<<endl;
		return 0;
	}
	cout<<3<<endl;
	return 0;

}
int prime(int n){
	int i,flag=0;
	int val=sqrt(n);
	f(i,2,val+2){
		if(n%i==0){
			flag=1;
			break;
		}
	}
	if(i!=n && flag==1)
		return 0;
	return 1;
}