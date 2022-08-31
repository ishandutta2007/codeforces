
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
	string s[4];
	int i,j,k,ch1,ch2,flag=0;;
	rep(i,4){
		cin>>s[i];
	}
	rep(i,4){
		rep(j,2){
			ch1=0;
			ch2=0;
			rep(k,3){
				if(s[i][j+k]=='x')
					ch1++;
				if(s[i][j+k]=='.')
					ch2++;
			}
			if(ch1==2&&ch2==1)
				flag=1;

		}
	}
	rep(j,2){
		rep(i,4){
			ch1=0;
			ch2=0;
			rep(k,3){
				if(s[j+k][i]=='x')
					ch1++;
				if(s[j+k][i]=='.')
					ch2++;
			}
			if(ch1==2&&ch2==1)
				flag=1;

		}
	}
	rep(i,2){
		rep(j,2){
			ch1=0;
			ch2=0;
			rep(k,3){
				if(s[j+k][i+k]=='x')
					ch1++;
				if(s[j+k][i+k]=='.')
					ch2++;
			}
			if(ch1==2&&ch2==1)
				flag=1;
		}
	}
	rep(i,2){
		rep(j,2){
			ch1=0;
			ch2=0;
			rep(k,3){
				if(s[j+k][3-i-k]=='x')
					ch1++;
				if(s[j+k][3-i-k]=='.')
					ch2++;
			}
			if(ch1==2&&ch2==1)
				flag=1;
		}
	}
	if(flag){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}

}