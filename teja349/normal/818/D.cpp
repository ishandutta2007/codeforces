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
#define pdqueue priority_queue< pii,vii ,greater< pii > >

//std::ios::sync_with_stdio(false); 
set<pii> ::iterator it;
set<pii> seti;
set<int> setirem;
int haha[1234567];
int relax(){
	while(1){
		it=seti.begin();
		if(it->ss>0){
			setirem.insert(it->ss);
			seti.erase(it);
		}
		else{
			return 0;
		}
	}
	return 0;
}  
//set<pii> seti;
int main(){
    std::ios::sync_with_stdio(false);
	int n,a;
	cin>>n>>a;
	int i,val;
	f(i,1,1000*1000){

		seti.insert(mp(0,i));
		haha[i]=0;
	}
	seti.erase(mp(0,a));
	seti.insert(mp(0,-1*a));
	rep(i,n){
		cin>>val;
		if(val==a){
			seti.erase(mp(haha[a],-1*a));
			haha[a]++;
			seti.insert(mp(haha[a],-1*a));
		}
		else{
			if(setirem.find(val)!=setirem.end())
				continue;
			seti.erase(mp(haha[val],val));
			haha[val]++;
			seti.insert(mp(haha[val],val));
		}
		relax();

	}
	if(seti.size()==1){
		cout<<-1<<endl;
	}
	else{
		it=seti.begin();
		it++;
		cout<<it->ss<<endl;
	}
	return 0;

    
}