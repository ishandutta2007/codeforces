
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


int main(){
	int n,s=0,ans,b[10000],arr[10000];
	cin>>n;
	int i;
	int check=n%2;
	if(check==1){
		f(i,1,n){
			cout<<"?"<<" "<<i<<" "<<i+1<<endl;
			fflush(stdout);
			cin>>b[i];
			s=b[i]-s;
		}
		cout<<"?"<<" "<<n<<" "<<1<<endl;
		fflush(stdout);
		cin>>ans;
		arr[n]=(ans+s)/2;
		arr[1]=ans-arr[n];
		f(i,1,n){
			arr[i+1]=b[i]-arr[i];
		}
		cout<<"! ";
		f(i,1,n+1){
			cout<<arr[i]<<" ";
		}
	}
	else{
		f(i,1,n-1){
			cout<<"? "<<i<<" "<<i+1<<endl;
			fflush(stdout);
			cin>>b[i];
			s=b[i]-s;
		}
		cout<<"? "<<n-1<<" "<<n<<endl;
			fflush(stdout);
			cin>>b[n-1];
		cout<<"? "<<n-1<<" "<<1<<endl;

		fflush(stdout);
		cin>>ans;
		arr[n-1]=(ans+s)/2;
		arr[1]=ans-arr[n-1];

	}
	f(i,1,n){
			arr[i+1]=b[i]-arr[i];
		}
		cout<<"! ";
		f(i,1,n+1){
			cout<<arr[i]<<" ";
		}

}