
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
#define pdqueuei priority_queue< pii,vii ,greater< pii > >

//std::ios::sync_with_stdio(false);
vector < vi > vec(100010);  
vector<set<int> > po(1002000);
int main(){
	pdqueue pqserv;
	pdqueue pq;

	int n,q,i,j,aa,bb,cc,serv;
	cin>>n>>q;
	rep(i,n){
		pqserv.push(i+1);
	}
	serv=n;
	rep(i,q){

		cin>>aa>>bb>>cc;
		
		//cout<<"hiii";
		//fflush(stdout);

		while(!pq.empty()&&pq.top()<aa){
			 int val=pq.top();
			 pq.pop();
			 int pos=*po[val].begin();
			 po[val].erase(pos);
			// cout<<vec[pos].size()<<"   sdf "<<pos<<endl;
			rep(j,vec[pos].size()){
				pqserv.push(vec[pos][j]);
				serv++;

			}
			vec[pos].clear();
			//cout<<serv;
		}
		if(serv<bb){
			cout<<-1<<endl;
			
		}
		else{

			int sumi=0;
			int val=bb;

			while(val--){
				vec[i].pb(pqserv.top());
				sumi+=pqserv.top();
				pqserv.pop();
				serv--;

			}
			cout<<sumi<<endl;
			po[aa+cc-1].insert(i);
			//cout<<aa+cc-1;
			pq.push(aa+cc-1);
		}
	}


}