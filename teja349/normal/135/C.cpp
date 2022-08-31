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
set<string> seti;
set<string> ::iterator it;
int main(){
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int i,j,on=0,q=0,ze=0,reqo,reqz;
    int n=s.length();
    rep(i,s.length()){
    	if(s[i]=='1'){
    		on++;
    	}
    	else if(s[i]=='0'){
    		ze++;
    	}
    	else{
    		q++;
    	}
    }
    reqo=n/2;
    reqz=n/2;
    
    if(n%2==1){
    	reqo++;
    }
    //cout<<ze<<" "<<q<<" "<<reqz<<endl;
    if(ze+q>reqz){
    	//cout<<"das";
    	seti.insert("00");
    }
    if(ze==reqz){
    	if(s[n-1]=='0'){
    		seti.insert("10");
    	}
    	else {
    		//cout<<"asd";
    		seti.insert("01");
    	}
    }
    if(on==reqo){
    	if(s[n-1]=='1'){
    		//cout<<"SAAS";
    		seti.insert("01");
    	}
    	else {
    		seti.insert("10");
    	}

    }
    
    if(on+q>reqo){
    	seti.insert("11");
    }
    if(on+q>=reqo && ze+q>=reqz && on<reqo && ze<reqz){
    	if(s[n-1]=='?'){
    		seti.insert("01");
			seti.insert("10");
    	}
    	else if(s[n-1]=='0'){

    		seti.insert("10");
    	}
    	else{
    		//cout<<"sa";
    		seti.insert("01");
    	}
    }
    for(it=seti.begin();it!=seti.end();it++){
    	cout<<*it<<endl;
    }


}