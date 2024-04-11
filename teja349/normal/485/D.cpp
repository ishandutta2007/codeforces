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
int pre[3*1000*1000+200]={0},arr[3*1000*1000+200]={0};
int checkans(int low,int high,int val){
	int mid=(low+high)/2;
	while(low<=high){
		if(pre[high]-pre[mid]>0){
			low=mid+1;
		}
		else if(arr[mid]==1){
			return mid%val;
		}
		else if(pre[mid]-pre[low-1]>0){
			high=mid-1;
		}
		else{
			return 0;
		}
		mid=(low+high)/2;


	}
	return 0;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int i,haha=0,val,j;
	rep(i,n){
		cin>>val;
		arr[val]=1;
	}
	f(i,1,1000*1000*3+4){
		pre[i]=pre[i-1]+arr[i];
	}
	f(i,2,1000*1000+2){
		if(arr[i]==0)
			continue;
		for(j=i;j<1000*1000+4;j+=i){
			haha=max(haha,checkans(j+1+haha,j+i-1,i));

		}
		
	}
	cout<<haha<<endl;
}