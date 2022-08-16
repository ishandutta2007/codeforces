
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
#define inf 1000*1000*1000+5
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod 1000*1000*1000+7
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

int main(){
	string s;
	int i,c[100004]={0},b[100004]={0};
	cin>>s;
	rep(i,s.length()-1){
		if(i&&s.at(i)!='B'&& s.at(i)!='A'){
			b[i]=max(b[i],b[i-1]);
			c[i]=max(c[i],c[i-1]);
		}
		if(s.at(i)=='A'&&s.at(i+1)=='B'){
			//cout<<i<<"AB"<<endl;
			//cout<<c[0]<<"     ";
			if(i&&c[i-1]){
				cout<<"YES";
				return 0;
			}
			else if(i){
				//cout<<c[0]<<"Hii"<<endl;
				c[i]=max(c[i],c[i-1]);
				b[i]=max(b[i],b[i-1]);
				//cout<<c[0]<<"HiiBYEE"<<endl;
			}
			b[i+1]=1;
		}
		else if(i){
			c[i]=max(c[i],c[i-1]);
			b[i]=max(b[i],b[i-1]);
		}
		if(s.at(i)=='B'&&s.at(i+1)=='A'){
			//cout<<i<<"BA"<<endl;
			if(i&&b[i-1]){
				cout<<"YES";
				return 0;
			}
			else if(i){
				c[i]=max(c[i],c[i-1]);
				b[i]=max(b[i],b[i-1]);
				
			}
			//cout<<"mee";
			c[i+1]=1;
		}
		else if(i){
			c[i]=max(c[i],c[i-1]);
			b[i]=max(b[i],b[i-1]);
		}

	}
	cout<<"NO"<<endl;
}