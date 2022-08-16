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
string s[100];
int checkrow(int i,int j){
	int sumi=0,j1=j-1;
	while(j1>=0){
		if(s[i][j1]=='X')
			sumi++;
		else
			break;
		j1--;
	}
	j1=j+1;
	while(j1<10){
		if(s[i][j1]=='X')
			sumi++;
		else
			break;
		j1++;
	}
	if(sumi>=4){
		//cout<<i<<" "<<j<<endl; 
		return 1;
	}
	return 0;

}
int checkcol(int i,int j){
	int i1=i-1,sumi=0;
	while(i1>=0){
		if(s[i1][j]=='X')
			sumi++;
		else
			break;
		i1--;
	}
	i1=i+1;
	while(i1<10){
		if(s[i1][j]=='X')
			sumi++;
		else
			break;
		i1++;
	}
	if(sumi>=4){
		return 1;
	}
	return 0;
}
int checkdiag(int i,int j){
	int sumi=0,i1=i-1,j1=j-1;
	while(i1>=0 && j1>=0){
		if(s[i1][j1]=='X')
			sumi++;
		else
			break;
		i1--;
		j1--;
	}
	i1=i+1;
	j1=j+1;
	while(i1<10 && j1<10){
		if(s[i1][j1]=='X')
			sumi++;
		else
			break;
		i1++;
		j1++;
	}
	if(sumi>=4){
		return 1;
	}
	sumi=0;i1=i-1;j1=j+1;
	while(i1>=0 && j1<10){
		if(s[i1][j1]=='X')
			sumi++;
		else
			break;
		i1--;
		j1++;
	}
	i1=i+1;
	j1=j-1;
	while(i1<10 && j1>=0){
		if(s[i1][j1]=='X')
			sumi++;
		else
			break;
		i1++;
		j1--;
	}
	if(sumi>=4){
		return 1;
	}
	return 0;

}
int main(){
    std::ios::sync_with_stdio(false);
    int i,j;
    rep(i,10){
    	cin>>s[i];
    }
    rep(i,10){
    	rep(j,10){
    		if(s[i][j]=='.'){
    			if(checkrow(i,j) || checkcol(i,j)||checkdiag(i,j)){
    				//cout<<i<<" "<<j<<endl;
    				cout<<"YES"<<endl;
    				return 0;
    			}
    		}
    	}

    }
    cout<<"NO"<<endl;

    return 0;      

}