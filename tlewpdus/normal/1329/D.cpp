#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
char str[200100];

struct mlist {
	int nxt[200100];
	int pre[200100];
	int live[200100];
	int cnt[26];
	vector<int> loc[26];
	vector<pii> ans;

	void init(int n) {
		for (int i=0;i<26;i++) loc[i].clear(), cnt[i] = 0;
		for (int i=0;i<=n+1;i++) {
			pre[i] = i-1;
			nxt[i] = i+1;
		}
		for (int i=1;i<=n;i++) live[i] = 0;
		live[0] = live[n+1] = 1;
		ans.clear();
	}
	void insert(int a) {
		live[a] = 1;
		cnt[str[a]-'a']++;
		loc[str[a]-'a'].push_back(a);
	}
	int fin_nxt(int a) {
		if (live[a]) return a;
		return nxt[a] = fin_nxt(nxt[a]);
	}
	int fin_pre(int a) {
		if (live[a]) return a;
		return pre[a] = fin_pre(pre[a]);
	}
	void ref(int a) {
		while(!loc[a].empty()&&!live[loc[a].back()]) loc[a].pop_back();
	}
	void que(int a){
		int t = loc[a].back();
		int s = fin_nxt(nxt[t]);
		int tc = str[s]-'a';
		if (s==n+1) {
			int maxi = 0, ti = -1;
			for (int i=0;i<26;i++) {
				if (i==a||loc[i].empty()) continue;
				if (maxi<loc[i].back()) {
					maxi=loc[i].back();
					ti = i;
				}
			}
			if (ti<0) {
				ans.push_back({t,t});
				live[t] = 0;
				cnt[str[t]-'a']--;
				ref(a);
				return;
			}
			t = maxi;
			s = fin_nxt(nxt[t]);
			assert(str[s]==a+'a');
			tc = str[t]-'a';
		}
		ans.push_back({t+1,s});
		live[t] = 0;
		live[s] = 0;
		cnt[str[t]-'a']--;
		cnt[str[s]-'a']--;
		ref(a);
		ref(tc);
	}
} l;

struct slis {
	int nxt[200100];
	int pre[200100];
	int live[200100];
	int bit[200100];
	void upd(int i,int v) {
		while(i<=n) {
			bit[i]+=v;
			i += i&-i;
		}
	}
	int getv(int i) {
		int a = 0;
		while(i) {
			a += bit[i];
			i&=i-1;
		}
		return a;
	}
	void init(int n) {
		for (int i=1;i<=n;i++) bit[i] = 0;
		for (int i=1;i<=n;i++) upd(i,1);
		for (int i=0;i<=n+1;i++) {
			pre[i] = i-1;
			nxt[i] = i+1;
		}
		for (int i=1;i<=n;i++) live[i] = 1;
		live[0] = live[n+1] = 1;
	}
	int fin_nxt(int a) {
		if (live[a]) return a;
		return nxt[a] = fin_nxt(nxt[a]);
	}
	int fin_pre(int a) {
		if (live[a]) return a;
		return pre[a] = fin_pre(pre[a]);
	}
	pii que(int l, int r) {
		int t = l;
		pii ret = {getv(l),getv(r)};
		while(t<=r) {
			upd(t,-1);
			live[t] = 0;
			t = fin_nxt(nxt[t]);
		}
		return ret;
	}
} l2;

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		scanf("%s",str+1);
		n = strlen(str+1);
		l.init(n);
		int c = 0;
		for (int i=1;i<n;i++) {
			if (str[i]==str[i+1]) {
				l.insert(i);
				c++;
			}
		}
		while(true) {
			int maxi = 0, ti = -1;
			for (int i=0;i<26;i++) {
				if (maxi<l.cnt[i]) {
					maxi=l.cnt[i];
					ti = i;
				}
			}
			if (ti<0) break;
			l.que(ti);
		}
		l2.init(n);
		printf("%d\n",(int)l.ans.size()+1);
		int len = n;
		for (pii &v : l.ans) {
			//printf("%d %d\n",v.first,v.second);
			pii tmp = l2.que(v.first,v.second);
			printf("%d %d\n",tmp.first,tmp.second);
			len -= tmp.second-tmp.first+1;
		}
		printf("%d %d\n",1,len);
	}

	return 0;
}