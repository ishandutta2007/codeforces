
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


multiset< ll > set1;


ll query(ll x);	


int main(){
	std::ios::sync_with_stdio(false); 
	multiset< ll >::iterator it;
	set1.insert(0);
	int q;
	ll x;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		if(s=="+"){
			cin>>x;
			set1.insert(x);
		}
		else if(s=="-"){
			cin>>x;
			it=set1.find(x);
			set1.erase(it);
		}
		else if(s=="?"){
			cin>>x;
			query(x);
		}
	}
	//cout<<11<<endl<<10<<endl<<14<<endl<<13<<endl;
}


ll query(ll x){
	// ll i,ans=0;
	// multiset< ll >::iterator l,low,high,high1;
	// low=set1.begin();
	// high=set1.end();
	// high--;
	// for(i=30;i>=0;i--){

	// 	high++;
	// 	l=lower_bound(low,high,ans+1<<i);
		
	// 	high1=high;
	// 	high--;
	// 	if(l!=low && l!=high1){
			
	// 		if(((x>>i)&1) == 0){
			
	// 			low=l;
	// 			ans+=(1<<i);
				
	// 		}
	// 		else{
				
	// 			--l;
	// 			high=l;

	// 			l++;
	// 		}
			
	// 	}
	// 	else if(l==low){
	// 		ans+=1<<i;
	// 	}
	// }
	// ll val=*low;
	// cout<<(x^val)<<endl;

	multiset< ll >::iterator it;
	int cur = 0;
			for(int i = 30; i >= 0; i--)
			{
				if(((1 << i) & x) == 0)
				{
					cur |= (1 << i);
					 it = set1.lower_bound(cur);
					if(it == set1.end() || (cur >> i) != (*it >> i)) cur ^= (1 << i);
				}
				else
				{
					 it = set1.lower_bound(cur);
					if(it == set1.end() || (cur >> i) != (*it >> i)) cur |= (1 << i);
				}
			}
			cout << (x ^ cur) << '\n';
}