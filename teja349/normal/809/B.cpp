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
int a;

int check(int p,int q){
	string s;
	if(q<p){
		return 0;
	}
	if(p==q){
		//flag=1;
		a=p;
		return 0;
	}
	int mid=(p+q)/2;
	cout<<1<<" "<<mid<<" "<<mid+1<<endl;
	cin>>s;
	if(s=="TAK"){
		if(q-p==1){
			a=p;
			//flag=1;
			return 0;
		}
		check(p,mid);
	}
	else{
		if(q-p==1){
			a=q;
			//flag=1;
			return 0;
		}
		check(mid+1,q);
	}
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    int n,k;
    string s;
    cin>>n>>k;
    check(1,n);
   	int ans1=a;
   
    	a=-1;
    	check(1,ans1-1);
    	if(a!=-1){
    		if(a!=ans1-1){
    			cout<<2<<" "<<a<<" "<<ans1<<endl;
    			return 0;
    		}
    		else{
    			cout<<1<<" "<<a<<" "<<a+1<<endl;
    			cin>>s;
    			if(s=="TAK"){
    				cout<<2<<" "<<a<<" "<<ans1<<endl;
    				return 0;
    			}
    		}
    	}
    	a=-1;
    	check(ans1+2,n);
    	if(a!=-1){
    		if(a!=ans1+2){
    			cout<<2<<" "<<a<<" "<<ans1<<endl;
    			return 0;
    		}
    		else{
    			cout<<1<<" "<<ans1+1<<" "<<ans1<<endl;
    			cin>>s;
    			if(s=="TAK"){
    				cout<<2<<" "<<ans1+1<<" "<<ans1<<endl;
    				return 0;
    			}
    			else{
    				cout<<2<<" "<<ans1+2<<" "<<ans1<<endl;
    				return 0;
    			}
    		}

    	}
    	else{
    		cout<<2<<" "<<ans1<<" "<<ans1+1<<endl;
    		return 0;
    	}


}