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
string strfor,strback;
int query(int r1,int c1,int r2,int c2){
	cout<<"? "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
	string str;
	cin>>str;
	if(str=="YES")
		return 1;
	else
		return 0;
}
 int n;
int getdownpath(int r,int c){
	if(abs(r-1)+abs(c-1)==n-1){
		return 0;
	}
	int val;
	val=query(1,1,r-1,c);
	if(val==1){
		strback+="D";
		r--;
	}
	else{
		strback+="R";
		c--;
	}
	getdownpath(r,c);
	return 0;
}
int getuppath(int r,int c){
	if(abs(r-n)+abs(c-n)==n-1){
		return 0;
	}
	int val;
	val=query(r,c+1,n,n);
	if(val==1){
		strfor+="R";
		c++;
	}
	else{
		strfor+="D";
		r++;
	}
	getuppath(r,c);
	return 0;
}



int main(){
    std::ios::sync_with_stdio(false);
   
    cin>>n;
    getdownpath(n,n);
    getuppath(1,1);
    int i;
    fd(i,strback.length()-1,0){
    	strfor+=strback[i];
    }
    cout<<"! "<<strfor<<endl;
    return 0;     
}