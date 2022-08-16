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

    int n,m,my=0,last,chance,n1,m1,maxi;
    cin>>n>>m;
    last=1;
    n1=n;
    m1=m;
    n1--;
    chance=2;
    //return 0;
    while(n1>0 || m1>0){
    	//cout<<n1<" "<<m1<<endl;
    	if(last==1 && chance==2){
    		if(m1>0){
    			m1--;
    			
    			last=2;
    		}
    		else{
    			n1--;
    			last=1;
    			my++;
    		}

    	}
    	else if(last==2 && chance==2){
    		if(n1>0){
    			n1--;
    			
    			last=1;
    		}
    		else{
    			m1--;
    			last=2;
    			my++;
    		}
    	}
    	else if(last==1 && chance==1){
    		if(n1>0){
    			n1--;
    			my++;
    			last=1;
    		}
    		else{
    			m1--;
    			last=2;
    			//my++;
    		}
    	}
    	else{
    		if(m1>0){
    			m1--;
    			my++;
    			last=2;
    		}
    		else{
    			n1--;
    			last=1;
    			//my++;
    		}
    	}
    	if(chance==1)
    		chance=2;
    	else
    		chance=1;
    }
    maxi=my;
    last=2;
    n1=n;
    m1=m;
    m1--;
    my=0;
    chance=2;
    while(n1>0 || m1>0){
    	if(last==1 && chance==2){
    		if(m1>0){
    			m1--;
    			
    			last=2;
    		}
    		else{
    			n1--;
    			last=1;
    			my++;
    		}

    	}
    	else if(last==2 && chance==2){
    		if(n1>0){
    			n1--;
    			
    			last=1;
    		}
    		else{
    			m1--;
    			last=2;
    			my++;
    		}
    	}
    	else if(last==1 && chance==1){
    		if(n1>0){
    			n1--;
    			my++;
    			last=1;
    		}
    		else{
    			m1--;
    			last=2;
    			//my++;
    		}
    	}
    	else{
    		if(m1>0){
    			m1--;
    			my++;
    			last=2;
    		}
    		else{
    			n1--;
    			last=1;
    			//my++;
    		}
    	}
    	if(chance==1)
    		chance=2;
    	else
    		chance=1;
    }
    maxi=max(maxi,my);
    cout<<maxi<<" "<<n+m-1-maxi<<endl;

}