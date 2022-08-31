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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<=c && b<=d){
    	cout<<"Polycarp"<<endl;
    	return 0;
    }
    if(c<=a && d<=b){
    	cout<<"Vasiliy"<<endl;
    	return 0;
    }
    int chance=1;
    while(1){
    	if(chance==1){
    		if(b>0){
    			b--;
    		}
    		else{
    			a--;
    		}
    	}
    	else{
    		if(c>0 && d>0){
    			c--;
    			d--;
    		}
    		else if(c>0){
    			c--;
    		}
    		else{
    			d--;
    		}
    	}
    	if(a+b==0){
    		cout<<"Polycarp"<<endl;
    		return 0;
    	}
    	if(c+d==0){
    		cout<<"Vasiliy"<<endl;
    		return 0;
    	}
    	chance^=1;
    }
}