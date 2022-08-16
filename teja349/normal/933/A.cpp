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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
int one[123456],two[123456],a[123456];

int calcforw(int pos,int n){
	if(pos==n)
		return 0;

	int i;
	f(i,pos,n){
		if(i==pos){
			if(a[i]==1)
				one[i]=1;
			else
				one[i]=0;
		}
		else{
			one[i]=one[i-1];
			if(a[i]==1)
				one[i]++;
		}
		
	}
	int maxi=one[n-1];
	fd(i,n-1,pos){
		if(i==n-1){
			if(a[i]==2)
				two[i]=1;
			else
				two[i]=0;
		}
		else{
			two[i]=two[i+1];
			if(a[i]==2)
				two[i]++;
		}
		if(i!=pos)
			maxi=max(one[i-1]+two[i],maxi);
		else
			maxi=max(maxi,two[i]);
	}
	return maxi;

}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,val1,maxi=0;
    rep(i,n){
    	cin>>a[i];
    }

    rep(i,n){
    	val1=calcforw(i,n);
    	val1+=calcforw(0,i);
    	
    	maxi=max(maxi,val1);
    }
    cout<<maxi<<endl;
    return 0;  
    
}