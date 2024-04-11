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

int main(){
    std::ios::sync_with_stdio(false);
    double R,x1,x2,y1,y2;
    double x,y,lee,dist;
    cin>>R>>x1>>y1>>x2>>y2;
    lee=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(lee>R*R){

    	cout<<x1<<" "<<y1<<" "<<R<<endl;
    	return 0;
    }
    
    if(x1==x2){
    	//cout<<"dasds";
    	x=x1;
    	if(y1<y2){
    		y=y1-R;
    	}
    	else{
    		y=y1+R;
    	}
    }
    else if(y1==y2){
    	y=y1;
    	if(x1<x2){
    		x=x1-R;
    	}
    	else{
    		x=x1+R;
    	}
    }
    else{
    	lee=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    	//cout<<lee<<"das"<<endl;
    	x=x1*(lee+R);
    	x-=x2*R;
    	x/=lee;
    	//cout<<x<<endl;
    	y=y1*(lee+R);
    	y-=y2*R;
    	y/=lee;

    }
    x+=x2;
    x/=2;
    y+=y2;
    y/=2;
    x1=x;
    y1=y;
    dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    cout<<setprecision(30)<<endl;
    cout<<x<<" "<<y<<" "<<dist<<endl;
    return 0;  
    
}