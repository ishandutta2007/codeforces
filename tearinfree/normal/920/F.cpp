#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

struct seg_tr{
	int n;
	lli tr[300001];
	seg_tr() {}
	void init(int n) {
		this->n=n;
		for(int i=0;i<=n;i++) tr[i]=0;
	}
	void upd(int cur,int val) {
		while(cur<=n) {
			tr[cur]+=val;
			cur += cur&-cur;
		}
	}
	lli sum(int cur) {
		lli res=0;
		while(cur) {
			res+=tr[cur];
			cur-=cur&-cur;
		}
		return res;
	}
	lli find(int l,int r) {
		return sum(r)-sum(l-1);
	}
}tr;

int n,arr[300001],cnt[1000001],m;
vector<pii> dp[1000001];
int vis[1000001];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);

	vector<int> prime;
	for(int i=2;i<=1000000;i++) {
		if(!vis[i]) {
			prime.push_back(i);
			for(lli j=1ll*i*i;j<=1000000;j+=i) vis[j]=1;
			
			dp[i].push_back(pii(i,1));
			cnt[i]=2;
		}
		else {
			for(auto &v:prime) {
				if(i%v==0) {
					dp[i]=dp[i/v];
					cnt[i]=1;
					int f=0;
					for(auto &t:dp[i]) {
						if(t.first==v) t.second++,f=1;
						cnt[i]*=t.second+1;
					}
					if(!f) dp[i].push_back(pii(v,1)),cnt[i]*=2;
					break;
				}
			}
		}
	}
	cnt[1]=1;
	
	tr.init(n);
	set<int> tr_idx;
	for(int i=1;i<=n;i++) {
		tr.upd(i,arr[i]);
		if(cnt[arr[i]]!=arr[i])tr_idx.insert(i);
	}

	int t,l,r;
	while(m--) {
		scanf("%d%d%d",&t,&l,&r);
		if(t==2) {
			printf("%lld\n",tr.find(l,r));
		}
		else {
			for(auto it=tr_idx.lower_bound(l); it!=tr_idx.end() && *it<=r;) {
				int i=*it;
				tr.upd(i,-arr[i]+cnt[arr[i]]);
				arr[i]=cnt[arr[i]];
				
				if(arr[i]==cnt[arr[i]]) it=tr_idx.erase(it);
				else it++;
			}
		}
	}

	return 0;
}