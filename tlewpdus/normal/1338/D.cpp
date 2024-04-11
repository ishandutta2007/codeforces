#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
vector<int> lis[100100];
int ans;
int D[100100], E[100100];

void idfs(int here, int p) {
	int numc = 0, me = 0, mde = 0;
	for (int &there : lis[here]) {
		if (there==p) continue;
		numc++;
		idfs(there,here);
		me = max(me,E[there]);
		mde = max({mde,D[there],E[there]});
	}
	D[here] = 1+me;
	E[here] = max(numc-1,0)+mde;
}

void rdfs(int here, int p, int pd, int pe) {
	int ta = 0;
	if (~p) {
		int me = 0;
		for (int &there : lis[here]) {
			if (there!=p) me = max(me,E[there]);
		}
		me = max(me,pe);
		ans = max(ans,me+1);
		ta = me+1;
	}
	else {
		ans = max(ans,D[here]);
		ta = D[here];
	}
	//printf("%d : %d\n",here+1,ta);
	int me2[] = {pe,0}, mde2[] = {max(pd,pe),0};
	for (int &there : lis[here]) {
		if (there==p) continue;
		if (me2[0]<E[there]) {
			me2[1] = me2[0];
			me2[0] = E[there];
		}
		else if (me2[1]<E[there]) {
			me2[1] = E[there];
		}
		if (mde2[0]<max(D[there],E[there])) {
			mde2[1] = mde2[0];
			mde2[0] = max(D[there],E[there]);
		}
		else if (mde2[1]<max(D[there],E[there])) {
			mde2[1] = max(D[there],E[there]);
		}
	}
	int numc = (int)lis[here].size()-1;
	for (int &there : lis[here]) {
		if (there==p) continue;
		int npd = me2[0]+1;
		if (me2[0]==E[there]) npd = me2[1]+1;
		int npe = max(numc-1,0)+mde2[0];
		if (mde2[0]==max(D[there],E[there])) npe = max(numc-1,0)+mde2[1];
		rdfs(there,here,npd,npe);
	}
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	idfs(0,-1);
	rdfs(0,-1,0,0);
	printf("%d\n",ans);

	return 0;
}