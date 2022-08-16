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
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

typedef struct node{
    int val,prior,size;
    struct node *l,*r;
}node;
typedef node* pnode;

int sz(pnode t){
    return t?t->size:0;
}
void upd_sz(pnode t){
    if(t)t->size=sz(t->l)+1+sz(t->r);
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t)return void(l=r=NULL);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)  // "<=" . element at pos goes to left subtree(l)
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else
       split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
}
void merge(pnode &t,pnode l,pnode r) { //l->leftarray,r->rightarray,t->resulting array
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else    merge(r->l,l,r->l),t=r;
    upd_sz(t);
}

void init(pnode &t,int valo)
{	
	t->prior=rng();
	t->size=1;
	t->val=valo;
	t->l=NULL;
	t->r=NULL;
	return;
}
int a[312345],b[312345];
int typ;
int dire(int p1,int p2){
	int ans;
	if(b[p1]<a[p2]){
		ans=1;
	}
	else{
		ans=0;
	}
	if(typ==2)
		ans^=1;
	return ans;
}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i,cnt1=0,cnt2=0;
    rep(i,n){
    	cin>>a[i]>>b[i];
    	if(a[i]<b[i]){
    		cnt1++;
    	}
    	else{
    		cnt2++;
    	}
    }
    vi vec;
    if(cnt1<cnt2){
    	rep(i,n){
    		if(a[i]>b[i]){
    			
    				vec.pb(i);
    		}
    	}
    	typ=1;
    	cout<<cnt2<<endl;
    }
    else{
    	rep(i,n){
    		if(a[i]<b[i]){
    			vec.pb(i);
    		}
    	}
    	typ=2;
    	cout<<cnt1<<endl;
    }
    pnode tr = new node,l,r,gg,ii,jj,hh,kk;
    
    init(tr,vec[0]);
    f(i,1,vec.size()){
    	split(tr,l,r,0);
    	//cout<<sz(l)<<endl;
    	pnode nn = new node;
    	init(nn,vec[i]);
    	if(dire(vec[i],l->val)){
    		merge(gg,nn,l);
    		merge(tr,gg,r);
    		continue;
    	}
    	merge(tr,l,r);
    	split(tr,l,r,i-2);
    	if(dire(r->val,vec[i])){
    		
    		merge(gg,r,nn);
    		merge(tr,l,gg);
    		continue;
    	}
    	merge(tr,l,r);
    	int low=0;
    	int high=i-2,mid;
    	while(low<=high){
    		mid=(low+high)/2;
    		split(tr,l,r,mid);
    		split(l,gg,hh,mid-1);
    		
    		if(dire(hh->val,vec[i])){
    			split(r,ii,jj,0);
    			if(dire(vec[i],ii->val)){
    				merge(kk,nn,ii);
    				merge(r,kk,jj);
    				merge(l,gg,hh);
    				merge(tr,l,r);
    				break;
    			}
    			else{
    				low=mid+1;
    				merge(r,ii,jj);
    				merge(l,gg,hh);
    				merge(tr,l,r);
    			}
    		}
    		else{
    			merge(l,gg,hh);
    			merge(tr,l,r);
    			high=mid-1;
    		}
    	}	
    }
    rep(i,vec.size()){
    	split(tr,l,r,0);
    	cout<<l->val+1<<" ";
    	tr=r;
    }
    cout<<endl;
    return 0;   
}