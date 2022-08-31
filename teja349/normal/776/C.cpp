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
#define inf (1000*1000*100+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
ll a[123456],pre[123456];
map<ll ,ll > mapi;
int main(){
	std::ios::sync_with_stdio(false);
	ll n,k,i,j;
	cin>>n>>k;
	f(i,1,n+1){
		cin>>a[i];
	}
	pre[0]=0;
	f(j,1,n+1){
		pre[j]=pre[j-1]+a[j];
		//cout<<pre[j]<<endl;
		mapi[pre[j]]++;
	}
	ll val=1;
	ll inff=inf;
	inff*=inf;
	ll flag=0;
	ll counti=0;
	//cout<<mapi[0]<<"   fsdf "<<endl;
	while(abs(val)<inff){
	i=0;
	

		while(i<n){
			ll ans=pre[i]+val;
			if(mapi.find(ans)!=mapi.end()){
				counti+=mapi[ans];
				//cout<<pre[i]<<endl;
				//cout<<i<<" "<<ans<<"  "<<mapi[ans]<<endl;
				//cout<<"hii"<<counti<<endl;


			}
			//cout<<endl;

			i++;
			
			mapi[pre[i]]--;

		}
		//cout<<endl;
		if(k==1){
			cout<<counti<<endl;
			return 0;
		}
		if(k==-1 && flag){
			cout<<counti<<endl;
			return 0;
		}
		flag=1;
		f(i,1,n+1){
			mapi[pre[i]]++;
		}
		val*=k;

	}
	cout<<counti<<endl;
	return 0;

}