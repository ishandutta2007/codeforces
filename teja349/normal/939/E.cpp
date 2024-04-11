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
ll a[1234567];
int main(){
    std::ios::sync_with_stdio(false);
    ll q;
    cin>>q;
    ll typ;
    ll st=0;
    ll cnt=0;
    ll flag=1,last;
    ll sofar=0,ans=0,val;
    while(q--){
    	cin>>typ;
    	if(typ==1){
    		cin>>val;
    		if(flag){
    			last=val;
    			flag=0;
    		}
    		else{
    			a[cnt++]=last;
    			last=val;
    		}
    	}
    	else{
    		ans=sofar+last;
    		while(st<cnt){
    			if((st+1)*a[st]<ans){
    				ans+=a[st];
    				sofar+=a[st];
    				st++;
    			}
    			else{
    				break;
    			}
    		}
    		cout<<setprecision(26)<<last-ans*1.00/(st+1)<<endl;
    	}
    }
    return 0;  
    
}