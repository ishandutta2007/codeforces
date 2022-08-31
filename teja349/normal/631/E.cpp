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

/*

Copied from rajat1603 (nice usage of comparator).

Dynamic convex Hull 

decreasing slopes (Upper convex HULL of points)
/////////////  for lower convex hull of points just change in operator  ////////////////


*/


struct line{
	long long a , b;
	double xleft;
	bool type;
	line(long long _a , long long _b){
		a = _a;
		b = _b;
		type = 0;
	}
	bool operator < (const line &other) const{
		if(other.type){
			return xleft < other.xleft;
		}
		return a < other.a;
	}
};
double meet(line x , line y){
	return 1.0 * (y.b - x.b) / (x.a - y.a);
}
struct cht{
	set < line > hull;
	cht(){
		hull.clear();
	}
	typedef set < line > :: iterator ite;
	bool hasleft(ite node){
		return node != hull.begin();
	}
	bool hasright(ite node){
		return node != prev(hull.end());
	}
	void updateborder(ite node){
		if(hasright(node)){
			line temp = *next(node);
			hull.erase(temp);
			temp.xleft = meet(*node , temp);
			hull.insert(temp);
		}
		if(hasleft(node)){
			line temp = *node;
			temp.xleft = meet(*prev(node) , temp);
			hull.erase(node);
			hull.insert(temp);
		}
		else{
			line temp = *node;
			hull.erase(node);
			temp.xleft = -1e18;
			hull.insert(temp);
		}
	}
	bool useless(line left , line middle , line right){
		return meet(left , middle) > meet(middle , right);
	}
	bool useless(ite node){
		if(hasleft(node) && hasright(node)){
			return useless(*prev(node) , *node , *next(node));
		}
		return 0;
	}
	void addline(long long a , long long b){
		line temp = line(a , b);
		auto it = hull.lower_bound(temp);
		if(it != hull.end() && it -> a == a){
			if(it -> b > b){
				hull.erase(it);
			}
			else{
				return;
			}
		}
		hull.insert(temp);
		it = hull.find(temp);
		if(useless(it)){
			hull.erase(it);
			return;
		}
		while(hasleft(it) && useless(prev(it))){
			hull.erase(prev(it));
		}
		while(hasright(it) && useless(next(it))){
			hull.erase(next(it));
		}
		updateborder(it);
	}
	long long getbest(long long x){
		if(hull.empty()){
			return -1e18;
		}
		line query(0 , 0);
		query.xleft = x;
		query.type = 1;
		auto it = hull.lower_bound(query);
		it = prev(it);
		//cout<<it->a<<" "<<it->b
		return it -> a * x + it -> b;
	}
};


ll p[212345],lol[212345],haha[212345],a[212345];
int main(){
    std::ios::sync_with_stdio(false);
    ll n,i;
    cin>>n;
    f(i,1,n+1){
    	cin>>a[i];
    }
   f(i,1,n+1){
   		p[i]=p[i-1]+i*a[i];
   }
   f(i,1,n){
   		haha[i]=haha[i-1]+i*a[i+1];
   }
   ll maxi=p[n],val;
   cht hul;
  	//val=0;
   f(i,1,n+1){
   		hul.addline(a[i],p[i-1]-haha[i-1]);
   		val=0;
   		
   		val=hul.getbest(i);
   		//cout<<i<<" "<<val<<" ";
   		val+=p[n]-p[i];
   		val+=haha[i-1];
   		//cout<<val<<endl;
   		maxi=max(maxi,val);
   }
   cht huli;
   f(i,1,n){
   	lol[i]=lol[i-1]+(i+1)*a[i];
   }
   f(i,1,n+1){
   		val=0;
   		huli.addline(i,p[i-1]-lol[i-1]);
   		val=huli.getbest(a[i]);
   		val+=p[n]-p[i];
   		val+=lol[i-1];
   		//cout<<val<<endl;
   		maxi=max(maxi,val);
   }
   cout<<maxi<<endl;

    
}