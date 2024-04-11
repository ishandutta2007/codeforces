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
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

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
struct node{
	int val,lazy,sz,prior;
	node* l;
	node* r;
};
typedef node* pnode;
pnode init(int val){
	pnode t=pnode(malloc(sizeof(node)));
	t->val=val;
	t->lazy=0;
	t->sz=1;
	t->l=NULL;
	t->r=NULL;
	t->prior =rand();
	//cout<<t->prior<<endl;
	return t;
}
int updateall(pnode t){
	if(!t) return 0;
	t->sz=1;
	if(t->l) t->sz+=(t->l)->sz;
	if(t->r) t->sz+=(t->r)->sz;
	return 0;
}
int pushlazy(pnode t){
	if(!t || !t->lazy) return 0;
	t->val+=t->lazy;
	if(t->l) (t->l)->lazy+=t->lazy;
	if(t->r) (t->r)->lazy+=t->lazy;
	t->lazy=0;
	return 0;
}
int split(pnode t,pnode &l,pnode &r,int val,int add){
	pushlazy(t);
	if(!t){
		l=NULL;
		r=NULL;
		return 0;
	}
	int currsiz=add;
	if(t->l)
		currsiz+=(t->l)->sz;
	if(currsiz<=val){
		l=t;
		split(t->r,t->r,r,val,currsiz+1);
	}
	else{
		r=t;
		split(t->l,l,t->l,val,add);
	}
	updateall(t);
	return 0;
}
int merge(pnode &t,pnode l,pnode r){
	if(!l || !r){
		t=l?l:r;
		return 0;
	}

	if(l->prior>=r->prior){
		pushlazy(l);
		t=l;
		merge(t->r,l->r,r);
	}
	else{
		pushlazy(r);
		t=r;
		merge(t->l,l,r->l);
	}
	updateall(t);
	return 0;
}
pnode createtreap(int n){
	pnode t,newnode;

	int i;
	t=init(0);

	f(i,1,n){
		newnode=init(inf);
		merge(t,t,newnode);
	}
	return t;
}
int getless(pnode t,int haha,int &ans,int add){
	
	if(!t) return 0;
	pushlazy(t);
	int currsiz=add;
	if(t->l)
		currsiz+=(t->l)->sz;
	if(t->val<haha){
		ans=currsiz;
		getless(t->r,haha,ans,currsiz+1);
	}
	else{
		getless(t->l,haha,ans,add);
	}
	return 0;

}
int l[312345],r[312345];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    //int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>l[i]>>r[i];
    }
    pnode t=createtreap(n+10);
    pnode rr,reqd,newnode,waste;
    int ans1,ans2;
    rep(i,n){

    	getless(t,l[i],ans1,0);
    	getless(t,r[i],ans2,0);
    	split(t,t,rr,ans2,0);
    	split(rr,waste,rr,0,0);
    	//return 0;
    	split(t,t,reqd,ans1,0);
    	
    	//split(rr,waste,rr,ans2+1,0);
    	newnode=init(l[i]);
    	merge(t,t,newnode);
    	//return 0;
    	//split(rr,reqd,rr,ans2,0);
    	if(reqd)
    		reqd->lazy++;
    	//return 0;
    	merge(t,t,reqd);
    	merge(t,t,rr);

    }
    getless(t,inf,ans1,0);
    cout<<ans1<<endl;
    return 0;  
    
}