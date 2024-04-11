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
ll m;   
ll power(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2)
			ans*=a;
		ans%=m;
		a*=a;
		a%=m;
		b=b/2;		
	}
	return ans;

}
int mult(ll a[2][2],ll b[2][2]){
	ll c[2][2]={0};
	int i,j,k;
	rep(i,2){
		rep(j,2){
			rep(k,2){
				c[i][j]+=a[i][k]*b[k][j];
				c[i][j]%=m;
			}
		}
	}
	rep(i,2){
		rep(j,2){
			a[i][j]=c[i][j];
		}
	}
	return 0;
}
ll compute(ll n){
	if(n==2)
		return 3;
	n-=2;
	ll ans[2][2]={0};
	ll arr[2][2]={0};
	arr[0][0]=1;
	arr[0][1]=1;
	arr[1][0]=1;
	ans[0][0]=1;
	ans[1][1]=1;
	while(n>0){
		if(n%2)
			mult(ans,arr);
		//ans%=m;
		mult(arr,arr);
		//a%=mod;
		n=n/2;		
	}
	ll value=3*ans[0][0]+2*ans[1][0];
	value%=m;
	return value;

}
int main(){
	std::ios::sync_with_stdio(false);
	ll n,k,l;
	cin>>n>>k>>l>>m;
	ll biggie=1,ans;
	while(l--){
		if(k%2){
			ans=power(2,n);
			ans-=compute(n);
			ans%=m;
			ans+=m;
			ans%=m;
			biggie*=ans;
			biggie%=m;
		}
		else{
			ans=compute(n);
			ans%=m;
			ans+=m;
			ans%=m;
			biggie*=ans;
			biggie%=m;
		}
		k=k/2;
	}
	biggie%=m;
	if(k>0){
		cout<<0<<endl;
	}
	else{
		cout<<biggie<<endl;
	}
}