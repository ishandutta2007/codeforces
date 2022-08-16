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
 int n,m,c;
 int a[2000],fri[2000];
 int mid;
 int appen(int num){
 	int i;
 	if(num>mid){
 		fd(i,n-1,0){
 			if(!fri[i]||a[i]<num){
 				a[i]=num;
 				fri[i]=1;
 				return i+1;
 			}

 		}
 	}
 	else{
 		rep(i,n){
 			if(!fri[i]||a[i]>num){
 				a[i]=num;
 				fri[i]=1;
 				return i+1;
 			}

 		}
 	}
 	return 0;
 }
 int checked(){
 	int i;
 	rep(i,n){
 		if(!fri[i]){
 			return 0;
 		}
 	}
 	f(i,1,n){
 		if(a[i-1]>a[i])
 			return 0;
 	}
 	return 1;
 }
int main(){
    std::ios::sync_with_stdio(false);
   
    cin>>n>>m>>c;
    int num,i;
    mid=c/2;
    rep(i,m){
    	cin>>num;
    	cout<<appen(num)<<endl;
    	if(checked()){
    		return 0;
    	}
    }
    return 0;  
    
}