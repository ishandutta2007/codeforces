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
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


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
int a[1234567],lessi[6123456],more[6123456];

int main(){
   // std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	ll i;
	rep(i,n){
		scanf("%d",&a[i]);
		a[i]--;
	}     
	ll sumi=0,cnt1=0,cnt2=0;
	rep(i,n){
		if(a[i]<=i){
			lessi[i-a[i]+2*n]--;
			sumi+=(i-a[i]);
			cnt1++;
		}
		else{
			more[a[i]-i]++;
			sumi+=(a[i]-i);
			cnt2++;
		}
	}
	ll mini=sumi;
	ll res=0;
	ll last=n-1;
	ll inles=2*n;
	//cout<<sumi<<endl;
	f(i,1,n){
		sumi-=(n-1-a[last]);
		sumi+=(a[last]);
		//cout<<i<<" "<<sumi<<endl;
		if(a[last]<=n-1){
			cnt1--;
			lessi[n-1-a[last]+2*n]--;
		}
		else{
			cnt2--;
			more[a[last]-n-1]--;
			//cout<<i<<" "<<more[1]<<endl;
		}
		//cout<<i<<" "<<more[1]<<endl;
		sumi+=cnt1;
		sumi-=cnt2;

		
		//lessi[i]=0;
		inles--;
		cnt1+=more[i];
		cnt2-=more[i];
		lessi[inles]=more[i];
		more[i]=0;
		if(a[last]<=0){
			cnt1++;
			lessi[inles-a[last]]++;
		}
		else{
			cnt2++;
			more[i+a[last]]++;
		}
		if(sumi<mini){
			mini=sumi;
			res=i;
		}
		//cout<<sumi<<endl;
		last--;
	}
	cout<<mini<<" "<<res<<endl;

    
}