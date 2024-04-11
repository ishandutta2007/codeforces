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
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);
int a[512345],b[512345],mama[512345],c[512345],seg[1512345],n;
int N=511123;
map<int,int> map1,map2,map3;
int update(int node,int s,int e,int p,int val){
	if(s==e){
		seg[node]=max(val,seg[node]);
		return 0;
	}
	int mid=(s+e)/2;
	if(p<=mid)
		update(2*node,s,mid,p,val);
	else
		update(2*node+1,mid+1,e,p,val);
	seg[node]=max(seg[2*node+1],seg[2*node]);
	return 0;
}   
int query(int node,int s,int e,int l,int r){
	if(l>e || r<s){
		return 0;
	}
	if(l<=s && e<=r){
		return seg[node];
	}
	int mid=(s+e)/2;
	int a=query(2*node,s,mid,l,r);
	int b=query(2*node+1,mid+1,e,l,r);
	return max(a,b);
}
vector< pair<int,pii> > vec;
int updateall(int val){
	//cout<<val<<endl;
	int i;
	if(mama[vec[val].ss.ff]<vec[val].ss.ss){
		mama[vec[val].ss.ff]=vec[val].ss.ss;
		update(1,0,N,vec[val].ss.ff,vec[val].ss.ss);

	}
		
	//cout<<vec[val].ss.ff<<" "<<vec[val].ss.ss<<endl;
	val++;
	while(val<n && vec[val-1].ff==vec[val].ff){
		if(mama[vec[val].ss.ff]<vec[val].ss.ss){
			mama[vec[val].ss.ff]=vec[val].ss.ss;
			update(1,0,N,vec[val].ss.ff,vec[val].ss.ss);

		}
		
		//cout<<vec[val].ss.ff<<" "<<vec[val].ss.ss;
		val++;
	}
	return 0;
}
int main(){
    //std::ios::sync_with_stdio(false); 
    int i;
    int sumi=0;
    map<int,int>::iterator it;
    cin>>n;
    int counter=1;
    rep(i,n){
    	scanf("%d",&a[i]);
    	map1[a[i]]=0;
    	//mapi[b[i]]=0;
    	//mapi[c[i]]=0;
    }
    rep(i,n){
    	scanf("%d",&b[i]);
    	map2[b[i]]=0;
    	//mapi[b[i]]=0;
    	//mapi[c[i]]=0;
    }
    rep(i,n){
    	scanf("%d",&c[i]);
    	//map3[c[i]]=0;
    	//mapi[b[i]]=0;
    	//mapi[c[i]]=0;
    }
    for(it=map1.begin();it!=map1.end();it++){
    	it->ss=counter++;
    }
    counter=1;
    for(it=map2.begin();it!=map2.end();it++){
    	it->ss=counter++;
    }
    counter=1;
    for(it=map3.begin();it!=map3.end();it++){
    	it->ss=counter++;
    }
    rep(i,n){
    	//a[i]=map1[a[i]];
    	b[i]=map2[b[i]];
    	//c[i]=map3[c[i]];
    	//cout<<c[i]<<endl;
    	vec.pb(mp(a[i],mp(b[i],c[i])));
    }
    sort(vec.begin(),vec.end());

    fd(i,vec.size()-2,0){
    	if(vec[i].ff!=vec[i+1].ff){
    		updateall(i+1);
    	}
    	int val=query(1,0,N,vec[i].ss.ff+1,inf);
    	//cout<<"yoo"<<endl;
    	//cout<<val<<" "<<vec[i].ss.ff<<" "<<vec[i].ss.ss<<endl;
    	if(val>vec[i].ss.ss){
    		sumi++;
    	}
    }
    cout<<sumi<<endl;


}