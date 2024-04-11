#include<bits/stdc++.h>
using namespace std;

const int  N = 300005 * 20;

int sz , son[N][2] , root , a[N / 20] , now , x , m , S[N] , n;
bool ep[N];

void add(int x) {
	int p = root;
	for(int i = 19;i >= 0;i --) {
		int k;
		if((1 << i) & x) k = 1; else k = 0;
		if(!son[p][k]) son[p][k] = ++sz;
//		cerr<<sz<<endl;
		p = son[p][k];
	}
	if(!ep[p]) {
		ep[p] = 1;
		p = root;
		for(int i = 19;i >=0;i --) {
			int k;
			if((1 << i) & x) k = 1; else k = 0;
			S[p] ++;
			p = son[p][k];
		}
		S[p] ++;
	}
}

int query(int x) {
	int p = root;
	vector<int>path;
	vector<int>it;
	path.clear(); it.clear();
	it.push_back(1);
	for(int i = 19;i >=0;i --) {
		int k;
		if((1 << i) & x) k = 1; else k = 0;
		path.push_back(k);
//		cerr<<p<<" "<<son[p][k]<<" it"<<endl;
		if(!son[p][k]) return 0;
		p = son[p][k];
		it.push_back(p);
	}
//	puts("arrive");
	int cnt = 2;
	int ret = 0;
	for(int i = it.size() - 2;i >= 0;i --) {
		if(S[it[i]] != cnt) {
			int p = it[i];
			while(cnt) {
				if(S[son[p][path[i]]] != cnt / 2) {
					p = son[p][path[i]];
				}
				else {
					ret += cnt / 2; 
					p = son[p][path[i] ^ 1];
				}
				cnt /= 2;
				if(!p) {
					return ret;
				}
				i ++;
				if(i == path.size()) break;
			}
			break;
		}
		cnt *= 2;
	}
	return ret;
}

int main() {
	scanf("%d%d",&n,&m);
	root = ++sz;
	for(int i = 1;i <= n;i ++) {
		int x;
		scanf("%d",&x);
		add(x);
	}
	for(int i = 1;i <= m;i ++) {
		scanf("%d",&x);
		now ^= x;
		printf("%d\n",query(now));
	}
}