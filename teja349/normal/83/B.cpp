
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
#define inf (1000*1000*10+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
ll inff;
ll a[123456];
ll pre[123456];
vl b;
ll n,k;
int check(ll value){
	vl::iterator it;
	it=lower_bound(b.begin(),b.end(),value);
	ll val=it-b.begin();
	ll sumi=0;
	val--;
	if(val>=0){
		sumi+=pre[val];
	}
	//cout<<val<<"  "<<pre[val]<<endl;
	sumi+=value*(n-1-val);
	//cout<<sumi<<"  sds  "<<value<<endl;
	if(sumi<=k)
		return 1;
	else
		return 0;
}

int main(){
	std::ios::sync_with_stdio(false);
	ll i;
	inff=inf;
	inff*=inf;
	cin>>n>>k;
	ll sumi=0;
	rep(i,n){
		cin>>a[i];
		b.pb(a[i]);
		sumi+=a[i];
	}
	sort(b.begin(),b.end());
	pre[0]=b[0];
	f(i,1,n){
		pre[i]=pre[i-1]+b[i];
	}
	
	if(sumi<k){
		cout<<-1<<endl;
		return 0;
	}
	ll low=0;
	ll high=inff;
	ll mid=(high+low)/2;
	ll ans=0;
	while( low<=high){
		if(check(mid)==1){
			ans=mid;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
		mid=(high+low)/2;
	}
	//cout<<check(10)<<endl;
	rep(i,n){
		k-=min(a[i],ans);
		a[i]-=min(a[i],ans);
	}
	rep(i,n){
		if(k==0)
			break;
		if(a[i]){
			a[i]--;
			k--;
		}

	}

	//cout<<check(9)<<endl;
	ll j;
	f(j,i,n){
		if(a[j])
			cout<<j+1<<" ";
	}
	f(j,0,i){
		if(a[j])
			cout<<j+1<<" ";
	}
	cout<<endl;

}