
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
	string s;int i,val,el;
	cin>>s;
	int b[3][30];
	int a[257];
	fill(a,a+257,-1);
	rep(i,27){
		if(a[s.at(i)]==-1)
			a[s.at(i)]=i;
		else{
			val=i;
			el=s.at(i);
		}
	}
	if(a[el]==val-1){
		printf("Impossible\n");
		return 0;
	}
	else{
		int i;
		int st=a[el]-1;
		int count=val-a[el]-1;
		f(i,count/2+1,13){
			if(st==-1)
				break;
			b[0][i]=s.at(st);
			st--;

			
		}
		fd(i,12,0){
			if(st==-1)
				break;
			b[1][i]=s.at(st);
			st--;

		}
		st=a[el];
		fd(i,count/2,0){
			b[0][i]=s.at(st);
			st++;


		}
		rep(i,13){
			if(st==val){
				st++;
				
			}
			if(st==27)
				break;
			b[1][i]=s.at(st);
			st++;
			
		}
		fd(i,12,0){
			if(st==val){
				st++;
				
			}
			if(st==27)
				break;
			b[0][i]=s.at(st);
			st++;
			//cout<<"hiii   "<<(char)b[1][i] <<endl;
		}
		rep(i,13){
			cout<<(char)b[0][i];
		}
		cout<<endl;
		rep(i,13){
			cout<<(char)b[1][i];
		}
		cout<<endl;
	}

}