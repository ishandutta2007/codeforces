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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// find_by_order()  // order_of_key
typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

vector< ordered_set > seg1(112345),seg2(112345);

int updatebit1(int pos,int typ,int val,int ind,int e){
	pos++;
	while(pos<e){
		if(typ==1)
			seg1[pos].insert(mp(val,ind));
		else
			seg1[pos].erase(mp(val,ind));

		pos+=pos&(-pos);
	}
	return 0;

}

int updatebit2(int pos,int typ,int val,int ind,int e){
	pos++;
	//cout<<pos<<endl;
	while(pos<e){
		if(typ==1)
			seg2[pos].insert(mp(val,ind));
		else
			seg2[pos].erase(mp(val,ind));

		pos+=pos&(-pos);
	}
	return 0;
}

int querybit1(int pos,int val){
	pos++;
	int ans=0;
	while(pos>0){
		ans+= seg1[pos].order_of_key(mp(val,inf));
		pos-=pos&(-pos);
	}
	return ans;
}

int querybit2(int pos,int val){
	pos++;
	int ans=0;
	while(pos>0){
		ans+= seg2[pos].order_of_key(mp(val,inf));
		pos-=pos&(-pos);
	}

	return ans;
}



int update1(int node,int s,int e,int pos,int val,int typ,int ind){
	updatebit1(pos,typ,val,ind,e);
	return 0;
}

int update2(int node,int s,int e,int pos,int val,int typ,int ind){
	pos=e-5-pos;

	updatebit2(pos,typ,val,ind,e);
	return 0;
}

int query1(int node,int s,int e,int l,int r,int val){
	return querybit1(r,val);
}

int query2(int node,int s,int e,int l,int r,int val){
	return querybit2(e-5-l,val);
}

int p[123456],s[123456],inc[123456],b[123456],pref[123456];
int fuck[123456];
map<int,int> mapi;

main(){
    //std::ios::sync_with_stdio(false); cin.tie(NULL);
  	int n,m;
  	//cin>>n>>m;
  	scanf("%d%d",&n,&m);
  	int i;
  	vii wow,haha;
  	rep(i,n){
  		scanf("%d",&p[i]);
  		haha.pb(mp(p[i],i));
  	}
  	rep(i,n){
  		scanf("%d",&s[i]);
  		wow.pb(mp(s[i],i));
  	}
  	vi vec;
  	rep(i,n){
  		scanf("%d",&b[i]);
  		mapi[b[i]]=0;
  		vec.pb(b[i]);
  	}
  	vec.pb(0);
  	vec.pb(inf);
  	sort(all(vec));
  	vii boo;
  	rep(i,m){
  		scanf("%d",&inc[i]);
  		boo.pb(mp(inc[i],i));
  	}
  	rep(i,m){
  		scanf("%d",&pref[i]);
  	}
  	int counter=0;
  	mapi[0]=0;
  	mapi[inf]=0;
  	int ind;
  	sort(all(vec));
  	map<int,int>::iterator it1;
  	for(it1=mapi.begin();it1!=mapi.end();it1++){
  		it1->ss=counter++;
  	}
  	sort(all(haha));
  	sort(all(wow));
  	sort(all(boo));
  	int j=0,k=0;
  	vi::iterator it;
  	rep(i,boo.size()){
  		while(j<haha.size() && boo[i].ff>=haha[j].ff){
  			ind=haha[j].ss;
  			update1(1,0,n+10,mapi[b[ind]],p[ind]-b[ind],1,ind);
  			update2(1,0,n+10,mapi[b[ind]],p[ind]+b[ind],1,ind);
  			//cout<<"+"<<mapi[b[ind]]<<endl;
  			j++;
  		}
  		while(k<wow.size() && boo[i].ff>wow[k].ff){
  			ind=wow[k].ss;
  			update1(1,0,n+10,mapi[b[ind]],p[ind]-b[ind],-1,ind);
  			update2(1,0,n+10,mapi[b[ind]],p[ind]+b[ind],-1,ind);
  			//cout<<"-"<<mapi[b[ind]]<<endl;
  			k++;
  		}
  		ind=boo[i].ss;
  		it=lower_bound(all(vec),pref[ind]);
  		//cout<<mapi[*it]<<endl;
  		fuck[ind]=query2(1,0,n+10,mapi[*it],n+10,inc[ind]+pref[ind]);
  		it--;
  		//cout<<*it<<endl;
  		fuck[ind]+=query1(1,0,n+10,0,mapi[*it],inc[ind]-pref[ind]);
  	}
  	rep(i,m){
  		printf("%d ",fuck[i]);
  	}
  	
    return 0;   
}