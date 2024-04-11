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

int main(){
	std::ios::sync_with_stdio(false);
	int n,k,x,i,val,j;
	cin>>n>>k>>x;
	int prev=0;
	int arr[3000]={0};
	int arr1[3000]={0};
	rep(i,n){
		cin>>val;
		arr[val]++;

	}
	rep(j,k){
		prev=0;
		rep(i,3000){
			if(arr[i]==0)
				continue;
			if(prev==0){
				int val=arr[i];
				arr1[i]+=val/2;
				arr1[i^x]+=val - val/2;
				if(val%2==1)
					prev=1;
			}
			else if(prev==1){
				int val=arr[i]-1;
				arr1[i]+=val/2+1;
				arr1[i^x]+=val-val/2;
				if(val%2==0)
					prev=0;
			}
		}
		rep(i,3000){
			arr[i]=arr1[i];
			arr1[i]=0;
		}
	}
	int mark,flag=1,mixi;
	rep(i,3000){
		if(flag && arr[i]){
			mixi=i;
			flag=0;
		}
		if(arr[i]){
			mark=i;
		}
	}
	cout<<mark<<" "<<mixi<<endl;
}