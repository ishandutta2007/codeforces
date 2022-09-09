//	2020 :D
#include <bits/stdc++.h>
using namespace std;
const int N=500050;
int a[N],b[N],ord[N],ans[N];
int main(){
	int n;scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),b[i]=2,ord[i]=i;
	sort(ord+1,ord+1+n,[&](int i,int j){return a[i]<a[j];});
	int mx_len=1;
	set<int> work;for(int i=1;i<=n;i++)work.insert(i);
	set<pair<int,int>> seg;
	for(int i=1;i<=n;i++)seg.insert({i,i});
	auto Split=[&](int x){
		auto it=seg.upper_bound({x,N});it--;
		if(it->first==x||it->second<x)return;
		int l=it->first,r=it->second;
		seg.erase(it);
		seg.insert({l,x-1});
		seg.insert({x,r});
	};
	auto Get=[&](int x){
		auto it=seg.upper_bound({x,N});it--;
		return *it;
	};
	auto Ins=[&](int x){
		auto it=seg.upper_bound({x,N});
		int l=x,r=x;
		if(x>1&&b[x]!=b[x-1])l=prev(it)->first,seg.erase(prev(it));
		if(x<n&&b[x]!=b[x+1])r=it->second,seg.erase(it);
		seg.insert({l,r});
	};
	auto Take=[&](int l,int r){
		auto it=work.lower_bound(l);
		if(it!=work.end()&&*it<=r)return *it;
		return 0;
	};
	auto Solve=[&](int x,int A){
		int l,r;tie(l,r)=Get(x);
		mx_len=max(mx_len,r-l+1);
		int mid=l+r>>1;
		if(b[l]==1){
			int x;
			while(x=Take(l,mid))ans[x]=A,work.erase(x);
		}
		if(b[r]==1){
			int x;
			while(x=Take(mid+1,r))ans[x]=A,work.erase(x);
		}
	};
	for(int i=1,j;i<=n;i=j){
		for(j=i;j<=n&&a[ord[i]]==a[ord[j]];j++){
			b[ord[j]]=1;
			Split(ord[j]);Split(ord[j]+1);
			seg.erase({ord[j],ord[j]});
			Ins(ord[j]);
		}
		for(j=i;j<=n&&a[ord[i]]==a[ord[j]];j++){
			Solve(ord[j],a[ord[i]]);
			if(ord[j]<n&&b[ord[j]]==b[ord[j]+1])Solve(ord[j]+1,a[ord[i]]);
			if(ord[j]>1&&b[ord[j]]==b[ord[j]-1])Solve(ord[j]-1,a[ord[i]]);
		}
	}
	printf("%i\n",(mx_len-1)/2);
	for(int i=1;i<=n;i++)printf("%i ",ans[i]);
	return 0;
}