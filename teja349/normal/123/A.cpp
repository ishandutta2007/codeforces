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
int pr[12345],let[1234],haha[1234],alph[1234];
string s;
int main(){
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    
    int i,j;
    for(i=2;i*i<1234;i++){
    	if(!pr[i])
    		continue;
    	for(j=i*i;j<1234;j+=i){
    		pr[j]=1;
    	}
    }
    int cnt=0;
    f(i,2,1234){
    	if(!pr[i] && i*2<=s.length()){
    		for(j=i;j<=s.length();j+=i){
    			if(!haha[j-1])
    				cnt++;
    			haha[j-1]=1;

    		}
    	}
    }
    rep(i,s.length()){
    	alph[s[i]]++;
    }
    int wow=-1;
    rep(i,1000){
    	if(alph[i]>=cnt){
    		wow=i;
    		break;
    	}
    }
    //wow=i;
    if(wow==-1){
    	cout<<"NO"<<endl;
    	return 0;
    }
    cout<<"YES"<<endl;
    rep(i,s.length()){
    	if(haha[i]){
    		let[i]=wow;
    		alph[wow]--;
    	}
    }
    j=0;
    rep(i,s.length()){
    	if(!haha[i]){
    		while(!alph[j])
    			j++;
    		let[i]=j;
    		alph[j]--;
    	}
    	cout<<(char)let[i];
    }
    cout<<endl;


    return 0;  
    
}