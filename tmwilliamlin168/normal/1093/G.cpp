#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct Node {
	Node *r,*l;
	int st,ed,ma[33];
}pool[404040],*root;
int n,p[202020][5],ce = 1,k,l,r,aa[33],bb[33],tot = 1,q;
inline void update(Node *now) {
	for (int i = 0;i < ce; i++)
		now->ma[i] = max(now->l->ma[i],now->r->ma[i]);
}
inline void Build(Node *&now,int st,int ed) {
	now = &pool[++tot];
	now->st = st;
	now->ed = ed;
	if (st == ed) {
		for (int i = 0;i < ce; i++) {
			for (int j = 0;j < k; j++)
				if ((1<<j) & i)
					now->ma[i] += p[st][j];
				else
					now->ma[i] -= p[st][j];
		}
		return ;
	}
	Build(now->l,st,(st+ed)/2);
	Build(now->r,(st+ed)/2+1,ed);
	update(now);
}
inline void ins(Node *now,int pos) {
	if (now->st > pos || now->ed < pos)
		return ;
	if (now->st == now->ed) {
		for (int i = 0;i < ce; i++) {
			now->ma[i] = 0;
			for (int j = 0;j < k; j++)
				if ((1<<j) & i)
					now->ma[i] += p[0][j];
				else
					now->ma[i] -= p[0][j];
		}
		return ;
	}
	ins(now->l,pos);
	ins(now->r,pos);
	update(now);
}
inline void getans(Node *now,int st,int ed) {
	if (now->st >= st && now->ed <= ed) {
		for (int i = 0;i < ce; i++)
			aa[i] = max(now->ma[i],aa[i]);
		return ;
	}
	if (now->st > ed || now->ed < st)
		return ;
	getans(now->l,st,ed);
	getans(now->r,st,ed);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	ce = (1<<k);
	for (int i = 1;i <= n; i++)
		for (int j = 0;j < k; j++)
			cin >> p[i][j];
	Build(root,1,n);
	cin >> q;
	int ty;
	for (int i = 1;i <= q; i++) {
		cin >> ty;
		if (ty == 1) {
			cin >> ty;
			for (int j = 0;j < k; j++)
				cin >> p[0][j];
			ins(root,ty);
		}
		else {
			cin >> l >> r;
			for (int j = 0;j < ce; j++) 
				aa[j] = -999999999;
			getans(root,l,r);
			int ans = 0;
			for (int j = 0;j < ce; j++) {
				ans = max(ans,aa[j]+aa[(ce-1)^j]);
			}
			cout << ans << endl;
		}
	}
	return 0;
}