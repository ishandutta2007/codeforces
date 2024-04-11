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
int a[212345];
int main(){
	std::ios::sync_with_stdio(false);
	int n,s;
	cin>>n>>s;
	s--;
	int i,j,haha=0,filler=0;
	rep(i,n){
		cin>>a[i];

	}
	if(a[s]!=0){
		haha++;
		a[s]=0;
	}
	rep(i,n){
		if(a[i]==0){
			filler++;
			haha++;
		}
	}
	haha--;
	filler--;
	sort(a,a+n);
	rep(i,n){
		if(a[i]!=0)
			break;
	}
	//cout<<a[1]<<endl;
	j=n-1;
	//cout<<haha<<endl;
	int prev=0;
	while(i<=j){
		if(a[i]!=prev+1 && a[i]!=prev){
			if(filler){
				filler--;
				prev++;

				
			}
			else{
				j--;
				//cout<<prev<<endl;
				//cout<<i<<"lol"<<endl;
				prev++;
				haha++;

			}
		}
		else{
			prev=a[i];
			i++;
		}
	}
	cout<<haha<<endl;
}