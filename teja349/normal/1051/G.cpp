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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//cout<<fixed<<setprecision(15)<<ans;
#define int ll 
template <typename T>
void printvec(vector<T>& vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

struct node{
	node* l;
	node* r;
	int val,prior,siz,sum;
};
typedef node* pnode;
pnode createnode(int value){
	pnode newnode = (pnode)malloc(sizeof(node));
	newnode->l = newnode->r = NULL;
	newnode->val = value;
	newnode->prior=rng();
	newnode->siz=1;
	newnode->sum=value;
	return newnode;
}
int getsiz(pnode t){
	if(!t) return 0;
	return t->siz;
}
int getsum(pnode t){
	if(!t) return 0;
	return t->sum;
}
void upd_siz(pnode t){
	if(!t)
		return;
	t->sum=t->val+getsum(t->l)+getsum(t->r);
	t->siz=getsiz(t->l)+1;
	t->siz+=getsiz(t->r);
}

void merge(pnode &t,pnode l,pnode r){
	if(!l){
		t=r;
		return;
	}
	if(!r){
		t=l;
		return;
	}
	if(l->prior<r->prior){
		t=r;
		merge(t->l,l,r->l);
	}
	else{
		t=l;
		merge(t->r,l->r,r);
	}
	upd_siz(t);
}
pnode haha[412345];
int a[412345],b[412345];
void split(pnode t,pnode &l,pnode &r,int x){
	if(!t){
		l=r=NULL;
		return;
	}
	if(t->val<=x){
		l=t;
		split(t->r,l->r,r,x);
	}
	else{
		r=t;
		split(t->l,l,r->l,x);
	}
	upd_siz(t);
}
int fre[412345];
int findright(int pos){
	if(fre[pos]==pos)
		return pos;
	fre[pos]=findright(fre[pos]);
	return fre[pos];
}
int dsu[412345];
int par(int u){
	if(dsu[u]<0)
		return u;
	dsu[u]=par(dsu[u]);
	return dsu[u];
}
int st[412345];
ll ans=0;
int baba[412345];
vector<vi> vec(412345);
int merge(int u,int v){
	//cout<<ans
	int wow;
	u=par(u);
	v=par(v);
	if(dsu[u]<dsu[v]){
		swap(u,v);
	}
	//exit(0);
	//cout<<ans<<endl;
	ans-=baba[u];

	ans-=baba[v];	
	if(st[v]>st[u]){
		baba[v]+=dsu[u]*(haha[v]->sum);
		st[v]=st[u];
		//cout<<"dads"<<endl;
	}
	//cout<<st[v]<<" "<<st[u]<<endl;
	int i;
	pnode l,r;
	rep(i,vec[u].size()){
		vec[v].pb(vec[u][i]);
		split(haha[v],l,r,vec[u][i]);

		if(l)
			baba[v]+=l->sum;
		if(!r){
			wow=0;
		}
		else{
			wow=r->siz;
		}
		baba[v]+=(st[v]+wow)*vec[u][i];
		pnode foo = createnode(vec[u][i]);

		merge(haha[v],l,foo);
		//return 0;
		merge(haha[v],haha[v],r);
	}
	vec[u].clear();
	//destroy(haha[u]);

	dsu[v]+=dsu[u];
	dsu[u]=v;
	ans+=baba[v];
	return 0;
}

signed main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    //ll ans=0;
    rep(i,412345){
    	dsu[i]=-1;
    	fre[i]=i;	
    	st[i]=i;
    }


    rep(i,n){
    	cin>>a[i]>>b[i];
    }
    int val;
    rep(i,n){
    	ans-=a[i]*b[i];
    	val=findright(a[i]);
    	haha[val]=createnode(b[i]);
    	
    	fre[val]=val+1;
    	baba[val]=b[i]*val;
    	vec[val].pb(b[i]);
    	ans+=baba[val];
    	if(fre[val-1]!=val-1){

    		//cout<<val<<endl;
    		merge(val,val-1);
    	}
    	if(fre[val+1]!=val+1){
    		//cout<<ans<<"   anssa"<<endl;
    		merge(val,val+1);
    	}
    	cout<<ans<<endl;
    	//cout<<baba[par(val)]<<endl;
    	
    }


    return 0;   
}