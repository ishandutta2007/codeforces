
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
ll a[10][10];
ll b[10][10]={0};
int mult(ll aar[10][10],ll ber[10][10]){
	int i,j,k;
	ll c[4][4]={0};
	rep(i,4){
		rep(j,4){
			rep(k,4){
				c[i][j]+=aar[i][k]*ber[k][j];
				c[i][j]%=mod;
			}
		}
	}
	rep(i,4){
		rep(j,4){
			aar[i][j]=c[i][j];
		}
	}
	return 0;

}
ll power(int n){
	if(n%2==1){
		mult(b,a);
	}
	while(n/2>0){
		n=n/2;
		mult(a,a);
		if(n%2==1){
			mult(b,a);
		}

	}
	return 0 ;

} 
int main(){
	int n;
	cin>>n;
	int i,j;
	rep(i,4){
		rep(j,4){
			a[i][j]=1;
		}
		a[i][i]=0;
		b[i][i]=1;
	}
	 power(n);
	cout<<b[0][0]<<endl;
}