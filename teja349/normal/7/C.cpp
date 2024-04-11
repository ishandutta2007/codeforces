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

ll extend_gcd(ll a,ll b,ll &x,ll &y){
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll x1,y1;
	ll val=extend_gcd(b,a%b,x1,y1);
	x=y1;
	y=x1-(a/b)*y1;
	return val;
} 

int main(){
	std::ios::sync_with_stdio(false);
	ll a,b,c;
	cin>>a>>b>>c;
	if(b==0 ){
		if(c%a==0){

			cout<<(-1*c)/a<<" "<<0<<endl;
		}
		else
			cout<<-1<<endl;
		return 0;

	}
	else if(a==0){
		if(c%b==0){
			cout<<0<<" ";
			cout<<(-1*c)/b<<endl;
		}
		else
			cout<<-1<<endl;
		return 0;
	}
	ll a1=abs(a);
	ll b1=abs(b);
	ll x,y;
	if(a1>b1){
		ll gc=extend_gcd(a1,b1,x,y);
		if(c%gc!=0){
			cout<<-1<<endl;
			return 0;
		}
		{
			x*=(c/gc);
			y*=(c/gc);
			x*=-1;
			y*=-1;
			cout<<x*(a1/a)<<" ";
			cout<<y*(b1/b)<<endl;
		}

	}
	else {
		//cout<<"daasd";
		swap(a1,b1);
		ll gc=extend_gcd(a1,b1,x,y);
		//cout<<gc<<"  "<<x<<"  "<<y<<endl;
		if(c%gc!=0){
			cout<<-1<<endl;
			return 0;
		}
		{
			x*=(c/gc);
			y*=(c/gc);
			x*=-1;
			y*=-1;
			cout<<y*(b1/a)<<" ";
			cout<<x*(a1/b)<<endl;

		}

	}

	//ll gc=extend_gcd(a,b,x,y);
}