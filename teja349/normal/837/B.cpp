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
string s[200];
int n,m;
int checkrow(){
	set<int> seti;
	int i,j,k=n/3;
	rep(i,n){
		rep(j,m){
			if(s[i][j]!=s[(i/k)*k][0]){
				//cout<<i<<" "<<j<<endl; 
				return 0;

			}
		}
	}
	seti.insert(s[0][0]);
	seti.insert(s[k][0]);
	seti.insert(s[2*k][0]);
	if(seti.size()==3){
		return 1;
	}
	//cout<<k<<endl;
	return 0;

}

int checkcol(){
	set<int>seti;
	int i,j,k=m/3;
	rep(i,m){
		rep(j,n){
			if(s[j][i]!=s[0][(i/k)*k]){
				return 0;
			}
		}
	}
	seti.insert(s[0][0]);
	seti.insert(s[0][k]);
	seti.insert(s[0][2*k]);
	if(seti.size()==3){
		return 1;
	}
	return 0;

}

int main(){
    std::ios::sync_with_stdio(false);
    //int n,m;
    cin>>n>>m;
    int i,j;
    rep(i,n){
    	cin>>s[i];
    }
    if(n%3==0 && checkrow()){
    	cout<<"YES"<<endl;
    	return 0;
    }
    if(m%3==0 && checkcol()){
    	cout<<"YES"<<endl;
    	return 0;
    }
    cout<<"NO"<<endl;

    return 0;      

}