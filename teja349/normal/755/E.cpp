
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
	int n,k;
	int i,j;
	cin>>n>>k;
	if(n<k+1){
		cout<<-1<<endl;
		return 0;
	}
	if(k==1){
		cout<<-1<<endl;
		return 0;
	}
	if(k>3){
		cout<<-1<<endl;
		return 0;
	}
	if(k==2){
		if(n==3||n==4){
			cout<<-1<<endl;
			return 0;
		}
		else{
			cout<<n-1<<endl;
			f(i,1,n){
				cout<<i<<" "<<i+1<<endl;
			}
			return 0;
		}
	}
	else if(k==3){
		cout<<(n-2)*(n-3)/2 + 2<<endl;
		f(i,1,n-1){
			f(j,i+1,n-1){
				cout<<i<<" "<<j<<endl;
			}
		}
		cout<<1<<" "<<n-1<<endl;
		cout<<2<<" "<<n<<endl;
		return 0;
	}

}