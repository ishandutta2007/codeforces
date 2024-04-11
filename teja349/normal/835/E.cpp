// teja349
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


//helper functions
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

int n,x,y;
vi vec;
int getans(){
	int i,val;
	if(vec.empty())
		return 0;
	cout<<"? "<<vec.size()<<" ";
	rep(i,vec.size()){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	cin>>val;
	int len=vec.size();
	if(len%2){
		if(val==x){
			return 0;
		}
		else{
			return 1;
		}
	}
	else{
		if(val==0){
			return 0;
		}
		else{
			return 1;
		}
	}

}

int checkbit(int cur){
	vec.clear();
	int i;
	f(i,1,n+1){
		if(i&(1<<cur)){
			vec.pb(i);
		}
	}
	return getans();

}

int check2bit(int cur1,int cur2){
	vec.clear();
	int i;
	f(i,1,n+1){
		if(i&(1<<cur1) &&  i&(1<<cur2)){
			vec.pb(i);
		}
	}
	return getans();

}
int diff[100];
int main(){
	//int n,x,y;
	cin>>n>>x>>y;
	int maxbit=9;
	while(maxbit>=0){
		diff[maxbit]=checkbit(maxbit);
		maxbit--;
	}
	int i;
	rep(i,10){
		if(diff[i]==1){
			break;
		}
	}
	int fixx=i;
	int a=0,b=0;
	b+=(1<<fixx);
	int val;
	rep(i,10){
		if(fixx!=i){
			val=check2bit(i,fixx);
			if(val==0){
				if(diff[i]){
					a+=(1<<i);
				}

			}
			else if(val==1){
				b+=(1<<i);
				if(!diff[i]){
					a+=(1<<i);
				}
			}
		}
	}
	if(a>b)
		swap(a,b);
	cout<<"! "<<a<<" "<<b<<endl;
	return 0;

}