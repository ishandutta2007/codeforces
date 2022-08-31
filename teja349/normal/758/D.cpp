
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
ll power(ll a,ll b){
	ll ans=1;
	if(b%2==1){
		ans*=a;
	}
	while(b/2>0){
		b=b/2;
		a=a*a;
		if(b%2==1)
			ans*=a;
	}
	return ans;
}
int main(){
	ll n;
	cin>>n;
	string s;
	cin>>s;
	//if(s=='0')
	{
		//cout<<0<<endl;
		//return 0;
	}
	ll ans=0;
	ll i=s.length();
	i--;
	s+='1';
	ll prev=0;
	ll num=1;
	ll sofar=0;
	ll prevpos=s.length()-1;
	int letter=0;
	while(i>=0){
			//cout<<"gffd";
			fflush(stdout);
			prev+=num*(s[i]-'0');

		if(prev>=n||letter>12){
			//cout<<prev<<endl;
			prev-=num*(s[i]-'0');
			ans+=prev*power(n,sofar);
			//cout<<ans<<endl;
			
			i++;
			while(s[i]=='0'){
				i++;

			}
			//cout<<1<<endl;

			if(prevpos<=i){
				i=prevpos-1;
			}
			prevpos=i;
			i--;
			sofar++;
			num=1;
			prev=0;
			letter=0;
		//	cout<<i<<endl;

		}
		else{
			i--;
			letter++;
			num*=10;
		}
	}
	//cout<<prev<<endl;
	ans+=prev*(power(n,sofar));
	cout<<ans<<endl;

}