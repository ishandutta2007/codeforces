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
    int h,m,s,t1,t2;
    cin>>h>>m>>s>>t1>>t2;
    int flag1=0,flag2=0;
    t1%=12;
    t2%=12;
    h%=12;
    t1*=5;
    t2*=5;
    h*=5;
    if(t1>t2){
    	swap(t1,t2);
    }
    if(t1>h ||(t2<=h) ){
    	flag1++;
    }
    else{
    	flag2++;
    }
    if(t1>m ||(t2<=m) ){
    	flag1++;
    }
    else{
    	flag2++;
    }
    if(t1>s|| (t2<=s) ){
    	flag1++;
    }
    else {
    	flag2++;
    }
    //cout<<flag2<<" "<<flag1<<endl;
    if(flag1==3 || flag2==3){
    	cout<<"YES"<<endl;
    }
    else{
    	cout<<"NO"<<endl;
    }
    


    return 0;  
    
}