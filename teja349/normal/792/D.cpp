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

int main(){
	std::ios::sync_with_stdio(false);
	ll n;
	int q,i;
	cin>>n>>q;
	ll m=n+1;
	//cout<<m<<endl;
	m/=2;
	//cout<<m<<endl;
	ll value;
	string s;
	int jj;
	rep(jj,q){
		cin>>value;
		cin>>s;
		rep(i,s.length()){
			if(s[i]=='L'){
				if(value%2){
					continue;
				}
				else{
					ll haha=value&(-value);
					haha/=2;
					value-=haha;
				}

			}
			else if(s[i]=='R'){
				if(value%2){
					continue;
				}
				else{
					ll haha=value&(-value);
					haha/=2;
					value+=haha;
				}

			}
			else if(s[i]=='U'){
				if(value==m){
					continue;
					//cout<<"yoo";
				}
				else{
					ll haha=value&(-value);
					value-=haha;
					//cout<<value<<"  ";
					haha*=2;
					if((value/haha)%2==0){
						value+=haha;
					}
					//cout<<value<<endl;
				}
			}

		}
		cout<<value<<endl;
	}
}