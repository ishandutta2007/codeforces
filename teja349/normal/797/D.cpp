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
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false); 
vi vec;
int l[123456],r[123456],val[123456];
map<int,int> mapi,lol;  
int compute(int root,int lef,int rig){
	int i;
	if(root==-1){
		f(i,lef,rig+1){
			lol[vec[i]]=-1;
		}
		return 0;		
	}
	vi::iterator it1;
	it1=lower_bound(vec.begin()+lef,vec.begin()+rig+1,val[root]);
	if(it1==vec.begin()+rig+1){
		compute(l[root],lef,rig);
		return 0;
	}
	//cout<<*it1<<" cc "<<val[root]<<endl;
	if(*it1==val[root]){
		lol[*it1]=1;
		//cout<<*it1<<" cc "<<endl;
		compute(l[root],lef,it1-vec.begin()-1);
		compute(r[root],it1-vec.begin()+1,rig);
	}
	else{
		compute(l[root],lef,it1-vec.begin()-1);
		compute(r[root],it1-vec.begin(),rig);
	}
	return 0;
}
set<int> seti,sear;
int main(){
    std::ios::sync_with_stdio(false); 
    int n;
    cin>>n;
    int i;
    int vee,lef,rig;
    rep(i,n){
    	cin>>vee>>lef>>rig;
    	l[i+1]=lef;
    	r[i+1]=rig;
    	val[i+1]=vee;
    	seti.insert(lef);
    	seti.insert(rig);
    	sear.insert(vee);
    	mapi[vee]++;
    }
    set<int>::iterator it;
    for(it=sear.begin();it!=sear.end();it++){
    	vec.pb(*it);
    }
    int root;
    f(i,1,n+1){
    	if(seti.find(i)==seti.end()){
    		root=i;
    	}
    }
    ll sumi=0;
    compute(root,0,vec.size()-1);
    map<int,int>::iterator it1;
    for(it1=lol.begin();it1!=lol.end();it1++){
    	//cout<<it1->ss<<endl;
    	if(it1->ss==-1){
    		sumi+=mapi[it1->ff];
    	}
    }
    cout<<sumi<<endl;
}