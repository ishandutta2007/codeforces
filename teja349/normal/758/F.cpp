
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
ll power(ll aw,ll b){
	if(b==0)
		return 1;
	ll ans=1;
	if(b%2==1){
		ans*=aw;
	}
	while(b/2>0){
		b=b/2;
		aw=aw*aw;
		
		if(b%2==1)
			ans*=aw;
		

	}
	return ans;
} 
int main(){
	ll n,l,r;
	cin>>n>>l>>r;
	int i,j;
	if(n==1){
		cout<<r-l+1<<endl;
		return 0;
	}
	else if (n==2){
		n=r-l+1;
		n=n*(n-1);
		cout<<n<<endl;
		return 0;
	}
	if(n>30){
		//cout<<"Hii";
		cout<<0<<endl;
		return 0;
	}
	double lv=l*1.000;
	double rv=r*1.000;
	double val1=1.00;
	val1=val1/(n-1);
	ll value=pow(rv,val1);
	//cout<<value<<endl;

	value+=5;
	ll sum=0;
	f(i,1,value){
		f(j,i+1,value){
			if(__gcd(i,j)!=1)
				continue;
			sum+=max((floor(rv/power(j,n-1))-ceil(lv/power(i,n-1))+1),(double)0);
			//cout<<i<<" "<<j<<" "<<sum<<endl;
		}
	}
	cout<<sum*2<<endl;
}