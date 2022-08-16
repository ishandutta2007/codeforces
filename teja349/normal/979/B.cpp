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
int arr[12345];
string s;
int haha[12345];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    int j;
    int maxi;
    rep(i,3){
    	cin>>s;
    	rep(j,s.length()){
    		haha[s[j]]++;
    	}
    	maxi=0;
    	rep(j,300){
    		maxi=max(maxi,haha[j]);
    		haha[j]=0;
    	}
    	if(maxi==s.length() && n==1){
    		//if(n==1)
    			arr[i]=max((int)s.length()-1,1);
            //else
              //  arr[i]=s.length();
    	}
    	else
    		arr[i]=maxi+min((int)s.length()-maxi,n);
    }
    maxi=0;
    rep(i,3){
    	maxi=max(maxi,arr[i]);
       // cout<<arr[i]<<endl;
    }
    int cnt=0;
    rep(i,3){
    	if(arr[i]==maxi){
    		cnt++;
    	}
    }
    //cout<<maxi<<" "<<cnt<<endl;
    if(cnt!=1){
    	cout<<"Draw"<<endl;
    	return 0;
    }
    rep(i,3){
    	if(arr[i]==maxi){
    		if(i==0)
    			cout<<"Kuro"<<endl;
    		else if(i==1)
    			cout<<"Shiro"<<endl;
    		else 
    			cout<<"Katie"<<endl;
    	}
    }
    return 0;  
    
}