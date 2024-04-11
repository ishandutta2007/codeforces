
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
int main(){
	double s,x1,x2;
	cin>>s>>x1>>x2;
	double t1,t2,p,d;
	cin>>t1>>t2;
	cin>>p>>d;
	if(t1>=t2){
		cout<<t2*fabs(x1-x2)<<endl;
		return 0;
	}
	if(x1<x2){
		if(d==1){
			if(p>x1){
				double t=(2*s-p+x1)*t1*t2;
				t=t/(t2-t1);
				double d=t/t2;
				if(d>=x2-x1){
					cout<<t2*(x2-x1);
				}
				else{
					cout<<t+(x2-x1-d)*t1<<endl;
				}
			}
			else{
				double t=(-p+x1)*t1*t2;
				t=t/(t2-t1);
				double d=t/t2;
				if(d>=x2-x1){
					cout<<t2*(x2-x1);
				}
				else{
					cout<<t+(x2-x1-d)*t1<<endl;
				}
			}
		}
		else{
			if(p<x1){
				double t=(p+x1)*t1*t2;
				t=t/(t2-t1);
				double d=t/t2;
				if(d>=x2-x1){
					cout<<t2*(x2-x1);
				}
				else{
					cout<<t+(x2-x1-d)*t1<<endl;
				}
			}
			else{
				double t=(p+x1)*t1*t2;
				t=t/(t2-t1);
				double d=t/t2;
				if(d>=x2-x1){
					cout<<t2*(x2-x1);
				}
				else{
					cout<<t+(x2-x1-d)*t1<<endl;
				}
			}
		}
		return 0;
	}

	if(x1>x2){
		if(d==1){

			if(p>x1){
				double t=(2*s-p-x1)*t1*t2;
				t=t/(t2-t1);
				double d=t/t2;
				if(d>=x1-x2){
					cout<<t2*(x1-x2);
				}
				else{
					cout<<t+(x1-x2-d)*t1<<endl;
				}
			}
			else{
				double t=(2*s-p-x1)*t1*t2;
				t=t/(t2-t1);
				double d=t/t2;
				if(d>=x1-x2){
					cout<<t2*(x1-x2);
				}
				else{
					cout<<t+(x1-x2-d)*t1<<endl;
				}
			}
		}
		else{
			if(p>=x1){
				double t=(p-x1)*t1*t2;
				t=t/(t2-t1);
				double d=t/t2;
				if(d>=x1-x2){
					cout<<t2*(x1-x2);
				}
				else{
					cout<<t+(x1-x2-d)*t1<<endl;
				}
			}
			else{
				double t=(2*s+p-x1)*t1*t2;
				t=t/(t2-t1);
				double d=t/t2;
				if(d>=x1-x2){
					cout<<t2*(x1-x2);
				}
				else{
					cout<<t+(x1-x2-d)*t1<<endl;
				}
			}
		}
		return 0;
	}
	
}