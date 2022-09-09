#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll lim=1e16;
vector<ll> bpw;

const int N=100050;
const int M=2*N;
int cur[N],n;
set<int> ids;
int Prev(int i){return *--ids.upper_bound(i);}

int ls[M],rs[M],tsz,root;
pair<ll,int> mn[M];
ll lzy[M];
void upd(int c,ll x){
	mn[c].first+=x;
	lzy[c]+=x;
}
void push(int c){
	if(!lzy[c])return;
	upd(ls[c],lzy[c]);
	upd(rs[c],lzy[c]);
	lzy[c]=0;
}
void Set(int&c,int ss,int se,int qi,ll x){
	if(!c)c=++tsz;
	if(ss==se){mn[c]={x,ss};return;}
	int mid=ss+se>>1;
	push(c);
	if(qi<=mid)Set(ls[c],ss,mid,qi,x);
	else Set(rs[c],mid+1,se,qi,x);
	mn[c]=min(mn[ls[c]],mn[rs[c]]);
}
void Add(int c,int ss,int se,int qs,int qe,ll x){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se){upd(c,x);return;}
	int mid=ss+se>>1;
	push(c);
	Add(ls[c],ss,mid,qs,qe,x);
	Add(rs[c],mid+1,se,qs,qe,x);
	mn[c]=min(mn[ls[c]],mn[rs[c]]);
}
pair<ll,int> Get(int c,int ss,int se,int qs,int qe){
	if(qs<=ss&&qe>=se)return mn[c];
	int mid=ss+se>>1;
	pair<ll,int> ans;
	if(qe<=mid)ans=Get(ls[c],ss,mid,qs,qe);
	else if(qs>mid)ans=Get(rs[c],mid+1,se,qs,qe);
	else ans=min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
	ans.first+=lzy[c];
	return ans;
}
ll GetOne(int i){
	return bpw[cur[i]]-Get(root,1,n,i,i).first;
}

void Fix(int i){
	if(ids.count(i)||i==n+1)return;
	int j=Prev(i);
	ids.insert(i);
	cur[i]=cur[j];
	Set(root,1,n,i,Get(root,1,n,j,j).first);
}
bool Work(int l,int r){
	pair<ll,int> tmp=Get(root,1,n,l,r);
	bool ret=false;
	while(tmp.first<=0){
		ll x=bpw[cur[tmp.second]]-tmp.first;
		if(tmp.first==0)ret=true;
		while(bpw[cur[tmp.second]]<=x){
			cur[tmp.second]++;
			if(bpw[cur[tmp.second]]==x)ret=true;
		}
		Set(root,1,n,tmp.second,bpw[cur[tmp.second]]-x);
		tmp=Get(root,1,n,l,r);
	}
	return ret;
}
int a[N];
int main(){
	bpw.pb(1);
	while(bpw.back()*42<lim)bpw.pb(bpw.back()*42);
	bpw.pb(bpw.back()*42);
	int q;
	scanf("%i %i",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%i",&a[i]);
		cur[i]=0;
		while(bpw[cur[i]]<a[i])cur[i]++;
		Set(root,1,n,i,bpw[cur[i]]-a[i]);
		ids.insert(i);
	}
	while(q--){
		int t;
		scanf("%i",&t);
		if(t==1){
			int i;
			scanf("%i",&i);
			printf("%lld\n",GetOne(Prev(i)));
		}else if(t==2){
			int l,r,x;
			scanf("%i %i %i",&l,&r,&x);
			Fix(l);Fix(r+1);
			for(auto it=ids.lower_bound(l);it!=ids.upper_bound(r);){
				Set(root,1,n,*it,1e18);
				ids.erase(it++);
			}
			cur[l]=0;
			while(bpw[cur[l]]<x)cur[l]++;
			Set(root,1,n,l,bpw[cur[l]]-x);
			ids.insert(l);
		}else{
			int l,r,x;
			scanf("%i %i %i",&l,&r,&x);
			Fix(l);Fix(r+1);
			do{
				Add(root,1,n,l,r,-x);
			}while(Work(l,r));
		}
	}
	return 0;
}