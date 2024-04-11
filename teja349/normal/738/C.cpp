
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


int check(ll val);


ll n,k,s,t,g[200100];

int main(){
	std::ios::sync_with_stdio(false);
	cin>>n>>k>>s>>t;
	vll vec(200009),vec1;
	int it1=-1;
	vll::iterator it;
	ll i,j,p,q;
	rep(i,n){
		cin>>p>>q;
		vec1.pb(mp(q,p));
	}
	sort(vec1.begin(),vec1.end());
	for(it=vec1.begin();it<vec1.end();it++){
		
		
		while(it1>=0 && it->ss<=vec[it1].ss)
		{
			it1--;
		}
		vec[++it1]=*it;

	}
	//return 0;
	//sort()
	//cout<<it1;
	g[0]=0;
	g[k+1]=s;
	f(i,1,k+1){
		cin>>g[i];
	}
	sort(g,g+k+2);
	
	ll high=it1;
	//cout<<high<<endl;
	//high-=1;
	ll low=0;
	ll mid=(high+low)/2;
	ll mini=1;
	mini=mini*inf*inf;
	//cout<<mini<<"  hii"<<endl; 
	while(low<=high){
		int val=check(vec[mid].ff);
		if(val==1){
			high=mid-1;
			if(mini>vec[mid].ss){
				mini=vec[mid].ss;
			}
		}
		else{
			low=mid+1;

		}
		mid=(low+high)/2;
		
	}
	ll maxi=1;
	maxi=maxi*inf*inf;
	if(mini==maxi)
		cout<<-1<<endl;
	else
		cout<<mini<<endl;
}
int check(ll val){
	//cout<<"hii";
	ll sum=0,i;
	f(i,1,k+2){
		ll dist=g[i]-g[i-1];
		if(dist>val){
			//cout<<dist<<val<<endl;
			return 0;
		}
		if(val>=2*dist)
			sum+=dist;
		else
			sum+=3*dist-val;
	}
	//cout<<val<<" "<<sum<<endl;
	if(sum<=t)
		return 1;
	else
		return 0;

}