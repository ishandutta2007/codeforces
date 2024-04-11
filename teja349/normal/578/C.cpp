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
#define inf (1000*10+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define EPS 0.0000004
//std::ios::sync_with_stdio(false); 
double a[212345],b[212345]; 
int n; 
double findmin(double val){
	int i;
	rep(i,n){
		b[i]=a[i]-val;
	}
	double sum=0;
	i=0;
	double mini=b[0];
	while(i<n){
		if(sum>0){
			sum=0;
		}
		sum+=b[i];
		i++;
		mini=min(mini,sum);
	}
	return mini;

}
double findmax(double val){
	int i;
	rep(i,n){
		b[i]=a[i]-val;
	}
	double sum=0;
	i=0;
	double mini=b[0];
	while(i<n){
		if(sum<0){
			sum=0;
		}
		sum+=b[i];
		i++;
		mini=max(mini,sum);
	}
	return mini;

}

int main(){
    std::ios::sync_with_stdio(false);
    int i;
    cin>>n;
    rep(i,n){
    	cin>>a[i];
    }
    double low=-inf;
    double high=inf,mid;
    i=0;
    double mini=100,mini1=100,maxi=0;
    while(fabs(maxi+mini1)>EPS){
    	
    	mid=(high+low)/2;
    	mini1=findmin(mid);
    	maxi=findmax(mid);
    	mini=fabs(mini1);
    	//cout<<high<<" "<<low<<endl;
    	//cout<<maxi<<"  fddf "<<mini<<endl;
    	if(maxi>0 && maxi>=mini){
    		low=mid;
    	}
    	else{
    		high=mid;
    	}
    	i++;
    }
    //cout<<low<<endl;
    cout<<setprecision(20)<<mini<<endl;
    return 0;      

}