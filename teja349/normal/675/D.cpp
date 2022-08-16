
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
//std::ios::sync_with_stdio(false);   


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

int main(){
	int n,val,i;
	set<int>::iterator it1,it2;
	cin>>n;
	cin>>val;
	set< int > set1;
	map<int,int> map1;
	int timer=0;
	map1[val]=timer++;
	set1.insert(val);
	f(i,1,n){
		cin>>val;
		map1[val]=timer++;
		it1=set1.upper_bound(val);
		if(it1==set1.begin()){
			//cout<<" dsfadas"<<endl;
			cout<<(*it1)<<" ";

		}
		else if(it1==set1.end()){
			it1--;
			//cout<<"dgddf";
			cout<<(*it1)<<" ";
		}
		else{
			//cout<<"dgddf";
			it2=it1--;
			if(map1[*it1]>map1[*it2]){
				cout<<(*it1)<<" ";
			}
			else{
				cout<<(*it2)<<" ";
			}

		}

		set1.insert(val);
	}

}