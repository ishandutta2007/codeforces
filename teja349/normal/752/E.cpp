
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
//int arr[1000*10000+6];
int a[12345678]={0};
int main(){
	std::ios::sync_with_stdio(false);   
	ll n,k,i,j,counti=0,val;
	cin>>n>>k;
	ll sumi=0;
	ll maxi=-1;
	rep(i,n){
		cin>>val;
		//arr[a[i]]++;
		a[val]++;
		sumi+=val;
		maxi=max(maxi,val);
		counti++;

	}
	
	if(sumi<k){
		cout<<-1<<endl;
		return 0;
	}
	if(sumi==k){
		cout<<1<<endl;
		return 0;
	}
	int low=0,high=maxi+3;
	while(counti>k){
		while(a[low]==0){
			low++;
		}
		
		
		if(counti-a[low]<=k){
			a[low]-=counti-k;
			counti=k;
			//low++;
		}
		else{
			
			
			counti-=a[low];
			a[low]=0;
			//low++;
			//cout<<"assassa";
		}
	}
	while(counti<k){
		while(a[high]==0){
			high--;
		}

		if(counti+a[high]<k){
			
			a[high/2]+=a[high];
			a[(high+1)/2]+=a[high];
			counti+=a[high];
			a[high]=0;

		}
		else{
			a[high]-=k-counti;
			a[high/2]+=k-counti;
			a[(high+1)/2]+=k-counti;
			counti=k;
		}
		
	}
	//cout<<low<<endl;

	while(1){
		while(a[high]==0){
			high--;
		}
		while(a[low]==0){
			low++;
		}
		//cout<<low<<endl;
		if(high/2<=low){
			cout<<low<<endl;
			return 0;
		}
		
		
		a[high/2]+=a[high];
		a[(high+1)/2]+=a[high];
		counti+=a[high];
		a[high]=0;
		while(counti>k){
			while(a[low]==0){
				low++;
			}
			
			if(counti-a[low]<=k){
				a[low]-=counti-k;
				counti=k;
				//low++;
			}
			else{
				
				
				counti-=a[low];
				a[low]=0;
				//low++;
				//cout<<"assassa";
			}
		}

	}




}