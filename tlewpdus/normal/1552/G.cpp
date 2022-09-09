#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
 
void pung() {
	puts("REJECTED");
	exit(0);
}
 
 
int pcnt(ll v) {
    return __builtin_popcountll((unsigned long long)v);
}
 
int N, K;
vector<int> groups[12];
ll bit[12][50];
ll msk[12];
void bt(int idx, ll v) {
//	printf("%d, %lld\n",idx,v);
	if (idx==K) {
		if ((v+1)!=((v+1)&(-(v+1)))) pung();
		return;
	}
	ll tv = (v&~msk[idx]);
	int c = pcnt(v&msk[idx]);
	for (int i=0;i<=groups[idx].size();i++) {
		bt(idx+1, tv|bit[idx][c+i]);
	}
}
 
int chk[50];
int main() {
	scanf("%d%d",&N,&K);
	if (N==1) {
	    puts("ACCEPTED");
	    return 0;
	}
	for (int i=0;i<K;i++) {
		int a;
		scanf("%d",&a);
		vector<int> lis;
		for (int j=0;j<a;j++) {
			int b;
			scanf("%d",&b); b--;
			lis.push_back(b);
			if (!chk[b]) {
				groups[i].push_back(b);
				chk[b] = 1;
			}
			msk[i] |= (1LL<<b);
		}
		sort(lis.begin(),lis.end());
		ll x = 0;
		bit[i][0] = 0;
		for (int j=1;j<=lis.size();j++) {
			x |= (1LL<<lis[j-1]);
			bit[i][j] = x;
		}
	}
	for (int i=0;i<N;i++) {
		if (!chk[i]) pung();
	}
//	puts("!");
	bt(0,0);
	puts("ACCEPTED");
 
	return 0;
}