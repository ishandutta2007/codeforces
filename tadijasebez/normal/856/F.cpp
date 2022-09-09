//	2222 :D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=800050;
const ll inf=9e18;
mt19937 rng(time(0));
int ls[N],rs[N],tsz,root,pri[N];
ll x[N],y[N],lzy_x[N],lzy_y[N],my[N],ms[N],ss[N],se[N];
void pull(int c){
	ss[c]=se[c]=x[c];
	if(ls[c])ss[c]=ss[ls[c]];
	if(rs[c])se[c]=se[rs[c]];
	my[c]=max({my[ls[c]],my[rs[c]],y[c]});
	ms[c]=max({ms[ls[c]],ms[rs[c]],y[c]-x[c]});
}
void upd(int c,ll ax,ll ay){
	x[c]+=ax;y[c]+=ay;
	ss[c]+=ax;se[c]+=ax;
	my[c]+=ay;ms[c]+=ay-ax;
	lzy_x[c]+=ax;lzy_y[c]+=ay;
}
void push(int c){
	if(lzy_x[c]==0&&lzy_y[c]==0)return;
	if(ls[c])upd(ls[c],lzy_x[c],lzy_y[c]);
	if(rs[c])upd(rs[c],lzy_x[c],lzy_y[c]);
	lzy_x[c]=lzy_y[c]=0;
}
int make(ll x,ll y,ll s){
	++tsz;pri[tsz]=rng();
	::x[tsz]=x;::y[tsz]=max(y,s+x);
	pull(tsz);
	return tsz;
}
void rot_l(int&c){int a=rs[c],b=ls[a];rs[c]=b;ls[a]=c;pull(c);pull(a);c=a;}
void rot_r(int&c){int a=ls[c],b=rs[a];ls[c]=b;rs[a]=c;pull(c);pull(a);c=a;}
void ins(int&c,ll x,ll y,ll s){
	if(!c)c=make(x,y,s);
	else{
		push(c);
		if(::x[c]==x){
			::y[c]=max({::y[c],max(y,my[ls[c]]),max(s,ms[rs[c]])+x});
			pull(c);
		}else if(::x[c]<x){
			ins(rs[c],x,max({y,my[ls[c]],::y[c]}),s);
			if(pri[rs[c]]>pri[c])rot_l(c);
			else pull(c);
		}else{
			ins(ls[c],x,y,max({s,ms[rs[c]],::y[c]-::x[c]}));
			if(pri[ls[c]]>pri[c])rot_r(c);
			else pull(c);
		}
	}
}
void add(int c,ll qs,ll qe,ll ay){
	if(!c||ss[c]>qe||qs>se[c])return;
	if(qs<=ss[c]&&qe>=se[c])upd(c,0,ay);
	else{
		push(c);
		if(::x[c]>=qs&&::x[c]<=qe)::y[c]+=ay;
		add(ls[c],qs,qe,ay);
		add(rs[c],qs,qe,ay);
		pull(c);
	}
}
int main(){
	my[0]=ms[0]=-inf;
	int n,m;ll C;scanf("%i %i %lld",&n,&m,&C);
	vector<pair<ll,int>> evs;
	for(int i=1;i<=2*n;i++){ll x;scanf("%lld",&x);evs.pb({x,1});}
	for(int i=1;i<=2*m;i++){ll x;scanf("%lld",&x);evs.pb({x,2});}
	sort(evs.begin(),evs.end());
	root=make(0,0,0);
	for(int i=1,mask=evs[0].second;i<evs.size();i++){
		ll t=evs[i].first-evs[i-1].first;
		if(mask&1)upd(root,t,t);
		if(mask&2)upd(root,-t,0);
		if(mask==3){
			ins(root,-C,-inf,-inf);
			ins(root,C,-inf,-inf);
			add(root,-C,C,t);
		}
		mask^=evs[i].second;
	}
	printf("%lld\n",my[root]);
	return 0;
}