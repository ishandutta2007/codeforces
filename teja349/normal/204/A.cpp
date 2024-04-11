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
#define setbasz(a) a.size()
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
int a[100];
int sz(ll val){
	int ans=0;
	while(val>0){
		//ans++;
		
		a[ans++]=val%10;
		val/=10;
	}
	return ans;
}
ll dert(int val,int dig){
	if(val==1){
		//cout<<dig<<endl;
		return dig-1;

	}
	else{
		ll ans=(dig-1)*pow(10,val-2);
		//cout<<ans<<endl;
		return ans;
	}

	
}
ll compute(ll val){
	ll num=sz(val);
	ll sumi=0;
	//cout<<num<<endl;
	if(num==0)
		return 0;
	int ans=num;
	int i;
	//cout<<num<<endl;
	f(i,1,num){
		sumi+=dert(i,10);
	}
	//cout<<num<<"aas"<<endl;
	//cout<<a[ans-1]<<endl;
	sumi+=dert(num,a[ans-1]);
	//cout<<sumi<<"sd"<<endl;
	fd(i,num-2,1){
		sumi+=(a[i])*pow(10,i-1);
	}
	//cout<<sumi<<endl;
	if(a[0]>=a[num-1]){
		sumi+=1;
	}
	return sumi;


}
int main(){
	std::ios::sync_with_stdio(false);
	ll l,r;
	cin>>l>>r;
	ll num1=compute(l-1);
	//cout<<num1<<endl;
	ll num2=compute(r);
	//cout<<num2<<endl;
	cout<<num2-num1<<endl;
}