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
//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
int ans[10],a[10];
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	// t=1;
	while(t--){
		int k,k1,c=0,i,res=inf,val,cur;
		cin>>k;
		rep(i,7){
			cin>>a[i];
		}
		c=0;
		rep(i,7){
			if(a[i]==1){
				c++;
				ans[c]=i+1;
			}
		}
		rep(i,7){
			cur=i;
			k1=k;
			while(cur<7){
				if(a[cur]==1){
					k1--;
					if(k1==0){
						res=min(res,cur-i+1);
						break;
					}
				}
				cur++;
			}
			if(k1==0){
				continue;
			}
			if(k1%c==0){
				val=7-i;
				val+=(k1/c-1)*7+ans[c];
				res=min(res,val);
			}
			else{
				val=7-i;
				val+=(k1/c)*7+ans[k1%c];
				res=min(res,val);
			}
		}
		cout<<res<<endl;
	}
}