#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstring>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const int mod=1e9+7;

struct seg_tr{
	static const int MAX=1<<19;
	int tr[MAX<<1];
	seg_tr() {}
	void init(int *arr,int n) {
		for(int i=0;i<n;i++) tr[i+MAX]=arr[i];
		for(int i=n;i<MAX;i++) tr[i+MAX]=0;
		for(int i=MAX-1;i>=0;i--) tr[i]=__gcd(tr[i<<1],tr[(i<<1)+1]);
	}
	void upd(int cur,int val) {
		cur+=MAX;
		tr[cur]=val;
		cur>>=1;
		while(cur) {
			tr[cur] = __gcd(tr[cur<<1],tr[(cur<<1)+1]);
			cur>>=1;
		}
	}
	int find(int cur,int s,int f,int l,int r,int x) {
		if(f<l || s>r) return 0;
		else if(l<=s && f<=r){
			if(tr[cur]%x==0) return 0;
			else return cur;
		}
		else {
			int nx=cur<<1,md=(s+f)>>1;
			int lv=find(nx,s,md,l,r,x),rv=find(nx+1,md+1,f,l,r,x);
			if(lv==-1 || rv==-1 || (lv>0 && rv>0)) return -1;
			else return max(lv,rv);
		}
	}
	bool query(int l,int r,int x) {
		int cur=find(1,0,MAX-1,l,r,x);
		if(cur==-1) return false;
		else if(cur==0) return true;

		while(cur<MAX) {
			int nx=cur<<1;
			int lv=tr[nx]%x,rv=tr[nx+1]%x;
			if(lv>0 && rv>0) return false;
			else if(lv>0) cur=nx;
			else cur=nx+1;
		}
		return true;
	}
}tr;

int n,arr[500001];
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	tr.init(arr,n);
	
	int q,t,l,r,x;
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&t);
		if(t==1) {
			scanf("%d%d%d",&l,&r,&x);
			l--;r--;
			if(tr.query(l,r,x)) puts("YES");
			else puts("NO");
		}
		else {
			scanf("%d%d",&l,&x);
			l--;
			tr.upd(l,x);
		}
	}

	return 0;
}