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
int arr[223456],lol[100];
int main(){
    std::ios::sync_with_stdio(false);
   int i,j,k,p;
   // cin>>a>>b>>c;
    rep(i,3){
    	cin>>lol[i];
    	//arr[i]=i;
    }
    int val,flag;
   	rep(i,3){
   		rep(j,3){
   			rep(k,3){
   				flag=0;
   				val=i;
				while(val<123456){
					arr[val]++;
					val+=lol[0];
				}
				val=j;
				while(val<123456){
					arr[val]++;
					val+=lol[1];
				}
				val=k;
				while(val<123456){
					arr[val]++;
					val+=lol[2];
				}
				f(p,3,123456){
					if(!arr[p])
						flag=1;
					arr[p]=0;
				}
				if(!flag){
					cout<<"YES"<<endl;
					return 0;
				}
   			}
   		}
   	}
   	cout<<"NO"<<endl;

    	
    return 0;  
    
}