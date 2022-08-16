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

decreasing slopes (lower convex HULL of points)
/////////////  for lower convex hull of points just change in operator  ////////////////


*/


struct line{
	double a , b;
	double xleft;
	bool type;
	line(double _a , double _b){
		a = _a;
		b = _b;
		type = 0;
	}
	bool operator < (const line &other) const{
		if(other.type){
			return xleft < other.xleft;
		}
		return a > other.a;
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
	void addline(double a , double b){
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
	double getbest(double x){
		if(hull.empty()){
			return -1e18;
		}
		line query(0 , 0);
		query.xleft = x;
		query.type = 1;
		auto it = hull.lower_bound(query);
		it = prev(it);
		return it -> a * x + it -> b;
	}
};
double x[123456],v[123456],t[123456];
double bow[1234566],lol[1234567];
vector< pair<double,double > > vecl,vecr;
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    double s;
    cin>>n>>s;
    int i,j;
    cht hulll,hullr;
     double ans1=inf,ans2=inf;
     double wow=1000*1000;
    rep(i,n){
    	cin>>x[i]>>v[i]>>t[i];
    	if(t[i]==1){
    		vecl.pb(mp(x[i],v[i]));
    		//cout<<x[i]<<" "<<v[i]<<endl;
    		ans1=min(ans1,x[i]/v[i]);
    	}
    	else{
    		vecr.pb(mp(x[i],v[i]));
    		ans2=min(ans2,(wow-x[i])/v[i]);
    	}
    }
    sort(vecl.begin(),vecl.end());
    j=0;
    double d,inter,slop;
    f(i,1,1000000){
    	while(j<vecl.size() && vecl[j].ff<=i){
    		d=vecl[j].ss;
    		slop=(s)/(s*s-d*d);
    		inter=-1*vecl[j].ff*(d)/(s*s-d*d);
    		hulll.addline(slop,inter);
    		j++;
    	}
    	if(j==0){
    		lol[i]=ans1;
    		continue;
    	}
    	lol[i]=min(ans1,hulll.getbest(i));

    }
    rep(i,vecr.size()){
    	vecr[i].ff=wow-vecr[i].ff;
    }
    sort(vecr.begin(),vecr.end());
    j=0;
  
    //cout<<ans1<<" "<<ans2<<endl;
    int wow1=1000*1000;
    j=0;
    f(i,1,1000000){
    	while(j<vecr.size() && vecr[j].ff<=i){
    		d=vecr[j].ss;
    		slop=(s)/(s*s-d*d);
    		inter=-1*vecr[j].ff*(d)/(s*s-d*d);
    		//cout<<slop<<"ds  "<<inter<<endl;
    		hullr.addline(slop,inter);
    		j++;
    	}
    	if(j==0){
    		bow[wow1-i]=ans2;
    		continue;
    	}
   
    	bow[wow1-i]=min(ans2,hullr.getbest(i));


    }
   // cout<<lol[400000]<<endl;
    double mini=max(ans1,ans2);
    int remem=-1;
    f(i,1,1000000){
    	if(mini>max(lol[i],bow[i])){
    		remem=i;
    		mini=max(lol[i],bow[i]);
    	}
    }
   // cout<<remem<<endl;
    //cout<<lol[400000]<<" "<<bow[400000]<<endl;
    cout<<setprecision(20)<<mini<<endl;


    return 0;      

}