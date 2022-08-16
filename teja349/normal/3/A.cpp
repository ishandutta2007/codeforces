
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
	char a,b;
	int p,q;
	cin>>a>>p>>b>>q;
	int p1=abs(p-q);
	int q1=abs(a-b);
	cout<<min(p1,q1)+abs(p1-q1)<<endl;
	while(a<b){
		a++;
		if(p<q){
			p++;
			cout<<"RU"<<endl;
		}
		else if(p>q){
			p--;
			cout<<"RD"<<endl;
		}
		else{
			cout<<"R"<<endl;
		}
	}
	while(a>b){
		
		a--;
		if(p>q){
			p--;
			cout<<"LD"<<endl;
		}
		else if(p<q){
			p++;
			cout<<"LU"<<endl;
		}
		else{
			cout<<"L"<<endl;
		}
	}
	while(p>q){
		p--;
		cout<<"D"<<endl;
	}
	while(p<q){
		p++;
		cout<<"U"<<endl;
	}


}