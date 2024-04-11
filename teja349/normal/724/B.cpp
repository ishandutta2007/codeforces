
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

int a[30][30],b[30][30],c[30],m,n;
int check(){
	int i,j;
	rep(i,n){
		int s=0;
		rep(j,m){
			if(c[j]+1!=b[i][j])
				s++;
		}
		if(s>2)
			return 0;
	}
	return 1;
}

int main(){
	//int m,n;
	cin>>n>>m;
	int i,j;
	rep(i,n){

		rep(j,m){
			cin>>a[i][j];
			b[i][j]=a[i][j];		
		}
		
	}
	rep(i,m){
		c[i]=i;
	}
	rep(i,m){
		f(j,i,m){
			swap(c[i],c[j]);
			if(check())
			{
				cout<<"YES";
				return 0;
			}
			swap(c[i],c[j]);
		}

	}
	cout<<"NO";
}