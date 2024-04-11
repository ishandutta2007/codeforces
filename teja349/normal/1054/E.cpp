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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct total{
	int x1,y1,x2,y2;
	total(int i,int j,int p,int q){	
		x1=i;
		y1=j;
		x2=p;
		y2=q;
	}
};
vector<total> vec;
string s[312][312],fin[312][312];
int cnt1[312],cnt0[312];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i,j,k;
    rep(i,n){
    	rep(j,m){
    		cin>>s[i][j];
    	}
    }
    rep(i,n){
    	rep(j,m){
    		cin>>fin[i][j];
    	}
    }
    fd(k,s[0][0].length()-1,0){
    	if(s[0][0][k]=='0'){
    		vec.pb(total(0,0,1,0));
    		cnt0[1]++;
    	}
    	else{
    		vec.pb(total(0,0,0,m-1));
    	}
    }
    fd(k,s[0][m-1].length()-1,0){
    	if(s[0][m-1][k]=='1'){
    		vec.pb(total(0,m-1,1,m-1));
    		cnt1[1]++;
    	}
    	else{
    		vec.pb(total(0,m-1,0,0));
    	}
    }
    f(i,1,n){
    	f(j,1,m-1){
    		fd(k,s[i][j].length()-1,0){
    			if(s[i][j][k]=='0'){
    				vec.pb(total(i,j,i,0));
    				cnt0[i]++;
    			}
    			else{
    				vec.pb(total(i,j,i,m-1));
    				cnt1[i]++;
    			}
    		}
    	}
    }
    f(i,1,n){
    	fd(k,s[i][0].length()-1,0){
    		if(s[i][0][k]=='0'){
    			vec.pb(total(i,0,0,0));
    		}
    		else{
    			cnt1[i]++;
    			vec.pb(total(i,0,i,m-1));
    		}
    	}
    	fd(k,s[i][m-1].length()-1,0){
    		if(s[i][m-1][k]=='1'){
    			vec.pb(total(i,m-1,0,m-1));
    		}
    		else{
    			cnt0[i]++;
    			vec.pb(total(i,m-1,i,0));
    		}
    	}

    }
    f(j,1,m-1){
    	i=0;
    	fd(k,s[i][j].length()-1,0){
    		if(s[i][j][k]=='0'){
    			vec.pb(total(i,j,i,0));
    		}
    		else{
    			vec.pb(total(i,j,i,m-1));
    		}
    	}
    }
    f(i,1,n){
    	rep(k,cnt1[i]){
    		vec.pb(total(i,m-1,0,m-1));
    	}
    	rep(k,cnt0[i]){
    		vec.pb(total(i,0,0,0));
    	}
    }
    f(j,1,m-1){
    	i=0;
    	fd(k,fin[i][j].size()-1,0){
    		if(fin[i][j][k]=='0'){
    			vec.pb(total(0,0,i,j));
    		}
    		else{
    			vec.pb(total(0,m-1,i,j));
    		}
    	}
    }
    f(i,1,n){
    	f(j,1,m-1){
    		fd(k,fin[i][j].size()-1,0){
	    		if(fin[i][j][k]=='0'){
	    			vec.pb(total(0,0,i,0));
	    			vec.pb(total(i,0,i,j));
	    		}
	    		else{
	    			vec.pb(total(0,m-1,i,m-1));
	    			vec.pb(total(i,m-1,i,j));
	    		}
	    	}
    	}
    }
    rep(i,n){
    	cnt1[i]=0;
    	cnt0[i]=0;
    }
   	f(i,1,n){
    	j=0;
    	rep(k,fin[i][j].length()){
    		if(fin[i][j][k]=='1'){
    			cnt1[i]++;
    		}
    	}
    	j=m-1;
    	rep(k,fin[i][j].length()){
    		if(fin[i][j][k]=='0'){
    			cnt0[i]++;
    		}
    	}
    }
    i=0;
    j=0;
    rep(k,fin[i][j].length()){
		if(fin[i][j][k]=='0'){
			cnt0[1]++;
		}
	}
	j=m-1;
	rep(k,fin[i][j].length()){
		if(fin[i][j][k]=='1'){
			cnt1[1]++;
		}
	}
	f(i,1,n){
		rep(j,cnt0[i]){
			vec.pb(total(0,0,i,0));
		}
		rep(j,cnt1[i]){
			vec.pb(total(0,m-1,i,m-1));
		}
	}
	f(i,1,n){
		j=0;
		fd(k,fin[i][j].length()-1,0){
			if(fin[i][j][k]=='1'){
				vec.pb(total(i,m-1,i,j));
			}
			else{
				vec.pb(total(0,0,i,j));
			}
		}
		j=m-1;
		fd(k,fin[i][j].length()-1,0){
			if(fin[i][j][k]=='1'){
				vec.pb(total(0,m-1,i,j));
			}
			else{
				vec.pb(total(i,0,i,j));
			}
		}

	}
	i=0;
	j=0;
	fd(k,fin[i][j].size()-1,0){
		if(fin[i][j][k]=='1'){
			vec.pb(total(i,m-1,i,j));
		}
		else{
			vec.pb(total(1,0,i,0));
		}
	}
	i=0;
	j=m-1;
	fd(k,fin[i][j].size()-1,0){
		if(fin[i][j][k]=='1'){
			vec.pb(total(1,m-1,i,j));
		}
		else{
			vec.pb(total(0,0,i,j));
		}
	}
	cout<<vec.size()<<'\n';
	rep(i,vec.size()){
		cout<<vec[i].x1+1<<" "<<vec[i].y1+1<<" "<<vec[i].x2+1<<" "<<vec[i].y2+1<<'\n';
	}









    return 0;   
}