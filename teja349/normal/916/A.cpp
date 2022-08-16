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
int check(int val){
	if(val%10==7)
		return 1;
	if(val/10==7)
		return 1;
	return 0;
}

int main(){
    std::ios::sync_with_stdio(false);
    int x;
    string s1,s2;
    cin>>x>>s1>>s2;
    int h,m;
    h=(s1[0]-'0')*10+s1[1]-'0';
    m=(s2[0]-'0')*10+s2[1]-'0';
    int ans=0;
    while(1){
    	if(check(m) || check(h)){
    		cout<<ans<<endl;
    		return 0;
    	}
    	ans++;
    	m-=x;
    	if(m<0){
    		m+=60;
    		h--;
    		if(h<0)
    			h=23;
    	}
    }

    return 0;  
    
}