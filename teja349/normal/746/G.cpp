
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
	int n,t,k,summax=0,summin=0,arr[300000],i,j,prevcount1,prevcount2;
	cin>>n>>t>>k;
	int counti=2;
	cin>>arr[1];
	summax+=arr[1]-1;
	f(i,2,t+1){
		cin>>arr[i];
		summin+=max(arr[i-1]-arr[i],0);
		summax+=arr[i]-1;
	}
	summin+=arr[t];
	summax+=1;
	//cout<<summax<<" fsdd "<<summin<<endl;
	if(k<summin||k>summax){
		cout<<-1<<endl;
		return 0;
	}
	cout<<n<<endl;
	
	
	rep(i,arr[1]){
		cout<<1<<" "<<counti<<endl;
		counti++;
	}
	prevcount1=2;
	prevcount2=counti-1;
	for(i=2;i<=t;i++){

		cout<<prevcount1<<" "<<counti<<endl;
		counti++;
		prevcount1++;
		
		f(j,1,arr[i]){
			if(k<summax){
				if(prevcount1<=prevcount2){
					cout<<prevcount1<<" "<<counti<<endl;
					counti++;
					prevcount1++;
					summax--;

				}
				else{
					cout<<prevcount1-1<<" "<<counti<<endl;
					counti++;

				}
			}
			else{
				cout<<prevcount1-1<<" "<<counti<<endl;
				counti++;
			}
		}
		prevcount1=prevcount2+1;
		prevcount2=counti-1;
	}
	cout<<endl;

}