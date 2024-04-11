#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, k;
vector<int> lis[200100];

int col2[200100];
void dfs2(int here, int p, int c) {
	col2[here] = c;
	for (int &there : lis[here]) {
		if (there==p) continue;
		dfs2(there,here,3-c);
	}
}
int col3[200100];
void dfs3(int here, int p, int c) {
	col3[here] = c+1;
	for (int &there : lis[here]) {
		if (there==p) continue;
		dfs3(there,here,(c+1)%3);
	}
}

int dead[200100];
int sz[200100];
int idfs(int here, int p) {
	sz[here] = 1;
	for (int &there : lis[here]) {
		if (there!=p&&!dead[there]) sz[here] += idfs(there,here);
	}
	return sz[here];
}
int cdfs(int here, int p, int asz) {
	for (int &there : lis[here]) {
		if (there!=p&&!dead[there]&&sz[there]>asz/2) return cdfs(there,here,asz);
	}
	return here;
}
int find_cen(int head) {
	return cdfs(head,-1,idfs(head,-1));
}
int D[200100], dep[200100];
void dfs(int here, int p) {
	D[here] = 0;
	dep[here] = (~p?dep[p]:-1)+1;
	for (int &there : lis[here]) {
		if (!dead[there]&&there!=p) {
			dfs(there,here);
			D[here] = max(D[here],D[there]+1);
		}
	}
}
int possible = 1;
void fidfs(int here, int p) {
	D[here] = 0;
	for (int &there: lis[here]) {
		if (there==p) continue;
		fidfs(there,here);
		D[here] = max(D[here],D[there]+1);
	}
}
void sedfs(int here, int p, int far) {
	vector<int> vec;
	for (int &there : lis[here]) {
		if (there==p) continue;
		vec.push_back(D[there]+1);
	}
	if (far) vec.push_back(far);
	sort(vec.begin(),vec.end());
	if (vec.size()>=3&&vec[(int)vec.size()-3]+vec[(int)vec.size()-2]+1>=k) {
		possible = 0;
		return;
	}
	if (!far) vec.push_back(far);
	sort(vec.begin(),vec.end());
	for (int &there : lis[here]) {
		if (there==p) continue;
		sedfs(there,here,(D[there]+1==vec.back()?vec[(int)vec.size()-2]:vec.back())+1);
	}
}
int ans[200100];
void ddfs(int here, int p, int lim, int c) {
	ans[here] = c+1;
	for (int &there : lis[here]) {
		if (there==p||dead[there]) continue;
		if (D[there]+dep[there]>=lim) {
			ddfs(there,here,lim,(c+k-1)%k);
		}
		else {
			ddfs(there,here,lim,(c+1)%k);
		}
	}
}
void mdfs(int here, int p, int c) {
	ans[here] = c+1;
	for (int &there : lis[here]) {
		if (there==p||dead[there]) continue;
		mdfs(there,here,(c+1)%k);
	}
}
void dnc(int head) {
	int cen = find_cen(head);
	dep[cen] = 0;
	dfs(cen,-1);
	vector<int> drr;
	for (int &there : lis[cen]) {
		if (dead[there]) continue;
		drr.push_back(D[there]+1);
	}
	dead[cen] = 1;
	sort(drr.begin(),drr.end());
	if (drr.size()<2||(drr.back()+drr[(int)drr.size()-2]+1<k)) {
		ans[cen] = 1;
		for (int &there : lis[cen]) {
			if (!dead[there]) dnc(there);
		}
		return;
	}
	int t = -1;
	for (int &there : lis[cen]) {
		if (dead[there]) continue;
		if (D[there]+1==drr.back()) {
			t=there;
			break;
		}
	}
	ans[cen] = 1;
	ddfs(t,cen,k-1-drr[(int)drr.size()-2],k-1);
	for (int &there : lis[cen]) {
		if (dead[there]||there==t) continue;
		mdfs(there,cen,1);
	}
}

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n-1;i++)  {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	if (k==2) {
		puts("Yes");
		dfs2(0,-1,1);
		for (int i=0;i<n;i++) printf("%d ",col2[i]);
		return 0;
	}
	if (k==3) {
		int c = 0;
		for (int i=0;i<n;i++) {
			c += (lis[i].size()>=3);
		}
		if (c) {
			puts("No");
			return 0;
		}
		int t = 0;
		for (int i=0;i<n;i++) {
			if (lis[i].size()==1) {
				t=i;
				break;
			}
		}
		dfs3(t,-1,0);
		puts("Yes");
		for (int i=0;i<n;i++) {
			printf("%d ",col3[i]);
		}
		printf("\n");
		return 0;
	}
	fidfs(0,-1);
	sedfs(0,-1,0);
	if (!possible) {
		puts("No");
		return 0;
	}
	dnc(0);
	puts("Yes");
	for (int i=0;i<n;i++) printf("%d ",ans[i]); printf("\n");

	return 0;
}