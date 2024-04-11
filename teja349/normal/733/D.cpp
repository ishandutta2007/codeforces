
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
#define inf 1000*1000*1000+5
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000*1000*1000+7
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

int main(){
	map<pii,pii> map1;
	int n,i,max2,maxi=0,a[3],l=-1,r=-1,max1;
	pii pair1;
	cin>>n;

	rep(i,n){
		int j;
		rep(j,3){
			cin>>a[j];
		}

		sort(a,a+3);

		 max1=min(a[0],a[1]);
		if(map1.find(mp(a[0],a[1]))!=map1.end()){
			pair1=map1[mp(a[0],a[1])];
			max2=min(max1,pair1.ff+a[2]);
			
			if(max2>maxi){
				maxi=max2;
				l=i;
				r=pair1.ss;
			}
			if(pair1.ff<a[2]){
				pair1.ff=a[2];
				pair1.ss=i;
				map1[mp(a[0],a[1])]=pair1;
			}
		}
		else if(a[0]>maxi){
			maxi=a[0];
			l=i;
			r=-1;
			map1[mp(a[0],a[1])]=mp(a[2],i);
		}
		else{
			map1[mp(a[0],a[1])]=mp(a[2],i);
		}


		
		 max1=min(a[2],a[1]);
		if(map1.find(mp(a[1],a[2]))!=map1.end()){
			pair1=map1[mp(a[1],a[2])];
			max2=min(max1,pair1.ff+a[0]);
			
			if(max2>maxi){
				maxi=max2;
				l=i;
				r=pair1.ss;
			}
			if(pair1.ff<a[0]){
				pair1.ff=a[0];
				pair1.ss=i;
				map1[mp(a[1],a[2])]=pair1;
			}
		}
		else if(a[0]>maxi){
			maxi=a[0];
			l=i;
			r=-1;
			map1[mp(a[1],a[2])]=mp(a[0],i);
		}
		else{
			map1[mp(a[1],a[2])]=mp(a[0],i);
		}
		
		 max1=min(a[0],a[2]);
		if(map1.find(mp(a[0],a[2]))!=map1.end()){
			pair1=map1[mp(a[0],a[2])];
			max2=min(max1,pair1.ff+a[1]);
			
			if(max2>maxi){
				maxi=max2;
				l=i;
				r=pair1.ss;
			}
			if(pair1.ff<a[1]){
				pair1.ff=a[1];
				pair1.ss=i;
				map1[mp(a[0],a[2])]=pair1;
			}
		}
		else if(a[0]>maxi){
			maxi=max1;
			l=i;
			r=-1;
			map1[mp(a[0],a[2])]=mp(a[1],i);
		}
		else{
			map1[mp(a[0],a[2])]=mp(a[1],i);
		}
		
		

	}

	if(l!=-1 && r!=-1){
		cout<<2<<endl;
		cout<<r+1<<" "<<l+1<<endl;
		//exit(0);

	}
	else if(l!=-1){
		cout<<1<<endl;
		cout<<l+1<<endl;
		//exit(0);
	}
	else if(r!=-1){
		cout<<1<<endl;
		cout<<r+1<<endl;
		//exit(0);

	}
	
}