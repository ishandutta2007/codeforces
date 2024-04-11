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
    ll a,b,f,k;
    cin>>a>>b>>f>>k;
    ll dir=0;
    ll dist1=2*(a-f);
    ll dist2=2*f;
    
	ll total=k*a-f;
	ll fuel=b-f;
	dir=0;
	ll haha=0;
	ll dist;
	while(total>0){
		dist=dir*dist2+(1-dir)*dist1;
		dist=min(dist,total);
		if(fuel<0){
			cout<<-1<<endl;
			return 0;
		}
		if(dist>fuel){
			fuel=b;
			haha++;
		}
		if(dist>fuel){
			cout<<-1<<endl;
			return 0;
		}
		dir^=1;
		fuel-=dist;
		total-=dist;
	}
	cout<<haha<<endl;

    return 0;  
    
}

// if(f>b){
//     	cout<<-1<<endl;
//     	return 0;
//     }
//     if(k==1){
//     	if(a-f>b){
//     		cout<<-1<<endl;
//     		return 0;
//     	}
//     	else{
//     		if(b<a){
//     			cout<<1<<endl;
//     		}
//     		else{
//     			cout<<0<<endl;
//     		}

//     	}
//     	return 0;

//     }
//     if(k==2){
//     	if(2*(a-f)>b){
//     		cout<<-1<<endl;
//     		return 0;
//     	}

//     }
//     if(k>2){
//     	if(2*(a-f)>b || 2*f>b){
//     		cout<<-1<<endl;
//     		return 0;
//     	}
//     }