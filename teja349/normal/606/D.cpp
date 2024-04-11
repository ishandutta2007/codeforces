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
#define tri pair<pii,int>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< pii >
#define pdqueue priority_queue< pii,vii ,greater< pii > >

//std::ios::sync_with_stdio(false);   
int compar(tri a,tri b){
	if(a.ff.ff!=b.ff.ff){
		return (a.ff.ff<b.ff.ff);
	}
	return (a.ff.ss>b.ff.ss);
}
vii ed(123456);
viii vec;
pdqueue pq;
int main(){
	std::ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int i,u,v;
	rep(i,m){
		cin>>u>>v;
		vec.pb(mp(mp(u,v),i));
	}
	int vert;
	pii papa;
	sort(vec.begin(),vec.end(),compar);
	f(i,1,n){
		pq.push(mp(i+2,i));
	}
	
	if(vec[0].ff.ss==0){
		//cout<<"y--"
		cout<<-1<<endl;
		return 0;
	}

	vert=2;
	ed[vec[0].ss]=(mp(1,2));
	//cout<<"Yoo";
	f(i,1,m){
		if(vec[i].ff.ss==1){
			ed[vec[i].ss]=(mp(vert,vert+1));
			vert++;
			//cout<<vert<<endl;
		}
		else{
			papa=pq.top();
			pq.pop();

			if(papa.ff<=vert){
				ed[vec[i].ss]=(mp(papa.ss,papa.ff));
				papa.ff++;
				pq.push(papa);
			}
			else{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	rep(i,m){
		cout<<ed[i].ff<<" "<<ed[i].ss<<endl;

	}
	return 0;



}