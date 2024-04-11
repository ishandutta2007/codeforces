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
string ans,lol;
int haha[100];
int main(){
    std::ios::sync_with_stdio(false); 
    string s;
    cin>>s;
    int i,n;
    n=s.length();
    rep(i,70){
    	haha[i]=-1;
    }
    rep(i,n){
    	haha[s[i]-'a']=i;
    }
    i=0;
   int j=0;
   ans="";
   lol="";
    while(1){
    	if(i==n)
    		break;
    	while(i<=haha[j]){
    		if(s[i]-'a'==j){
    			ans+=s[i];

    		}
    		else{
    			lol+=s[i];
    		}
    		i++;
    	}
    	j++;
    	int mew=lol.length();
    	mew--;
    	while(mew>=0){
    		if(lol[mew]-'a'<=j){
    			ans+=lol[mew];

    		}
    		else{
    			break;
    		}
    		mew--;
    	}
    	lol=lol.substr(0,mew+1);

    }
    cout<<ans;
    int mew=lol.length();
    mew--;
    while(mew>=0){
    	cout<<lol[mew];
    	mew--;
    }
}