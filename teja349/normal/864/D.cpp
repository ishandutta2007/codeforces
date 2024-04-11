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
int a[212345],haha[212345],pres[212345];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    set<int> seti;
    f(i,1,n+1){
    	seti.insert(i);
    }
    rep(i,n){
    	cin>>a[i];
    	haha[a[i]]++;
    	seti.erase(a[i]);
    }
    int lol=0;
    rep(i,n){
    	if(pres[a[i]]==1){
    		//cout<<i<<"da"<<endl;
    		int val=*seti.begin();
    		
    			a[i]=val;
    			seti.erase(val);
    			//haha[a[i]]--;
    			lol++;

    		


    	}
    	else if(haha[a[i]]>1){
    		//cout<<i<<"da"<<endl;
    		int val=*seti.begin();
    		if(a[i]>val){
    			
    			haha[a[i]]--;
    			a[i]=val;
    			seti.erase(val);
    			lol++;

    		}	
    		else{
    			pres[a[i]]=1;
    		}

    			

    	}
    }
    cout<<lol<<endl;
    rep(i,n){
    	cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;  
    
}