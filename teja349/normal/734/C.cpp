
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



ll n,m,k,x,s,i,a[300000],b[300000],a2[300000],b2[300000],sum,a1,b1;
ll calc(ll q ){
	int low=0,high=k-1,mid;
	mid=(high+low)/2;
	while(low<=high){
		if(b[mid]<=q){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
		mid=(high+low)/2;
	}
	//cout<<b[mid]<<"   "<<q<<endl;
	if(b[mid]<=q && (mid==k-1||b[mid+1]>q))
		return mid;
	else if(b[mid]>q)
		return mid-1;
	else
		return mid+1;

	
}


int main(){
	cin>>n>>m>>k>>x>>s;
	sum=n*x;
	rep(i,m){
		cin>>a2[i];
		
	}
	rep(i,m){
		cin>>b2[i];
		
	}
	rep(i,k){
		cin>>a[i];
		
	}
	rep(i,k){
		cin>>b[i];
		
	}
	int val=calc(s);
	if(val!=-1){
		sum=x*(n-a[val]);
	}
	//cout<<val;
	rep(i,m){
		if(b2[i]<=s){
			//cout<<"hiii";
			int val=calc(s-b2[i]);
			if(val!=-1)
			{
				//cout<<"hii";
				sum=min(sum,a2[i]*(n-a[val]));
				//cout<<sum<<"  "<<val<<"mee"<<endl;
			}
			else{
				sum=min(sum,a2[i]*n);
			}
		}
		
	}
	cout<<sum<<endl;

}