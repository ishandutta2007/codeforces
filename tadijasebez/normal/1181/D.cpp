#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=500050;
const int M=20*N;
int ls[M],rs[M],tsz,root[N],sz[M];
void Set(int p,int &c,int ss,int se,int qi){
	c=++tsz;ls[c]=ls[p];rs[c]=rs[p];sz[c]=sz[p]+1;
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int c,int ss,int se,int k){
	if(ss==se)return ss;
	int mid=ss+se>>1;
	if(sz[ls[c]]>=k)return Get(ls[c],ss,mid,k);
	else return Get(rs[c],mid+1,se,k-sz[ls[c]]);
}
int a[N],cnt[N],idx[N];
vector<pair<ll,int>> ckp;
int main(){
	int n,m,q;
	scanf("%i %i %i",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),cnt[a[i]]++;
	for(int i=1;i<=m;i++)idx[i]=i;
	sort(idx+1,idx+1+m,[&](int i,int j){return cnt[i]<cnt[j];});
	ll sum=n;
	for(int i=1,j;i<=m;i=j){
		ckp.pb({sum,i-1});
		root[ckp.size()]=root[ckp.size()-1];
		for(j=i;j<=m && cnt[idx[i]]==cnt[idx[j]];j++)Set(root[ckp.size()],root[ckp.size()],1,m,idx[j]);
		if(j<=m)sum+=(ll)(j-1)*(cnt[idx[j]]-cnt[idx[i]]);
	}
	ckp.pb({9e18,m});
	while(q--){
		ll k;
		scanf("%lld",&k);
		int i=lower_bound(ckp.begin(),ckp.end(),(pair<ll,int>){k,0})-ckp.begin();
		k-=ckp[i-1].first+1;
		int sz=ckp[i].second;
		//printf("%lld %i\n",k,sz);
		printf("%i\n",Get(root[i],1,m,k%sz+1));
	}
	//for(auto p:ckp)printf("->%lld %i\n",p.first,p.second);
	return 0;
}