
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
	std::ios::sync_with_stdio(false);
	int n,i;
	cin>>n;
	set<int> setr,setd;
	set<int>::iterator it;
	string s;
	cin>>s;
	rep(i,n){
		if(s[i]=='D'){
			setd.insert(i);
		}
		else{
			setr.insert(i);
		}
	}
	i=0;
	while(setr.size()!=0&&setd.size()!=0){
		if(setd.find(i)!=setd.end()){
			it=setr.lower_bound(i);
			if(it!=setr.end()){
				setr.erase(it);
			}
			else{
				it=setr.begin();
				setr.erase(it);
			}

		}
		else if(setr.find(i)!=setr.end()){
			it=setd.lower_bound(i);
			if(it!=setd.end()){
				setd.erase(it);
			}
			else{
				//cout<<"hii"<<endl;
				it=setd.begin();
				setd.erase(it);
			}
		}
		i++;
		if(i==n){
			i=0;
		}

	}
	if(setr.size()==0){
		cout<<"D";
	}
	else{
		cout<<"R";
	}


}