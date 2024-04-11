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
vector<vi> bord(312345);
vi ans;
int main(){
	std::ios::sync_with_stdio(false);
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	string s;
	cin>>s;
	int i,sumi=0,counter=0;
	rep(i,n){
		if(s[i]=='1'){
			counter++;
		}
		else{
			bord[counter].pb(i+1);
		}

	}
	rep(i,counter+1){
		sumi+=bord[i].size()/b;
	}
	sumi-=a;
	sumi++;
	cout<<sumi<<endl;
	rep(i,counter+1){
		int val=bord[i].size();
		int j=b-1;
		while(sumi){
			if(j<val){
				ans.pb(bord[i][j]);
				j+=b;
				sumi--;
			}
			else{
				break;
			}
		}

	}
	rep(i,ans.size()){
		cout<<ans[i]<<" ";
	}


}