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
    int k,n;
    cin>>n>>k;
    int i,od=0,ev=0,left,chan,val;
    rep(i,n){
    	cin>>val;
    	if(val%2){
    		od++;
    	}
    	else{
    		ev++;
    	}
    }
    if(n==k){
    	if(od%2){
    		cout<<"Stannis"<<endl;
    	}
    	else{
    		cout<<"Daenerys"<<endl;
    	}
    	return 0;
    }
    left=(n-k);
    chan=1;
    if(left%2){
    	if(k%2){
    		while(left>1){
	    		if(chan==1){
	    			if(ev>0)
	    				ev--;
	    			else
	    				od--;
	    		}
	    		else{
	    			if(od>0)
	    				od--;
	    			else
	    				ev--;
	    		}
	    		left--;
	    		chan^=1;
	    	}
	    	if(od>0){
	    		cout<<"Stannis"<<endl;
	    	}
	    	else{
	    		cout<<"Daenerys"<<endl;
	    	}
    	}
    	else{
    		left/=2;
    		if(od<=left || ev<=left){
    			cout<<"Daenerys"<<endl;
    		}
    		else{
    			if(od==left+1 && ev==left+1){
    				cout<<"Daenerys"<<endl;
    			}
    			else{
    				cout<<"Stannis"<<endl;
    			}
    		}
    	}

    }
    else{
    	while(left>1){
    		if(chan==1){
    			if(ev>0)
    				ev--;
    			else
    				od--;
    		}
    		else{
    			if(od>0)
    				od--;
    			else
    				ev--;
    		}
    		//cout<<"ads";
    		left--;
    		chan^=1;
    	}
    	//cout<<left<<endl;
    	if(ev>0){
    		cout<<"Daenerys"<<endl;
    		return 0;
    	}
    	od--;

    	if(od%2){
    		cout<<"Stannis"<<endl;
    	}
    	else{
    		cout<<"Daenerys"<<endl;
    	}



    }

}