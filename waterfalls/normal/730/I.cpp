#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int n,p,s;
int x[3013], y[3013];
int byY[3013];
priority_queue<pair<int,int> > l, m, r;
int use[3013];

bool compY(int i, int j) { return y[i]>y[j]; }

int main() {
	scanf("%d%d%d",&n,&p,&s);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) scanf("%d",&y[i]);
	iota(byY,byY+n,1);
	sort(byY,byY+n,compY);
	int ans = 0;
   	for (int i=0;i<s;i++) {
		ans+=y[byY[i]];
		m.push(MP(x[byY[i]]-y[byY[i]],byY[i]));
	}
	for (int i=s;i<n;i++) {
		l.push(MP(x[byY[i]],byY[i]));
		r.push(MP(y[byY[i]],byY[i]));
	}
	for (int i=0;i<p;i++) {
		while (use[l.top().B]) l.pop();
		while (use[r.top().B]) r.pop();
		if (l.top().A>m.top().A+r.top().A) {
			ans+=l.top().A;
			use[l.top().B] = 1;
			l.pop();
		} else {
			ans+=m.top().A+r.top().A;
			use[m.top().B] = 1;
			m.pop();
			m.push(MP(x[r.top().B]-y[r.top().B],r.top().B));
			use[r.top().B] = 2;
			r.pop();
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++) if (use[i]==1) printf("%d ",i);
	printf("\n");
	while (m.size()) {
		printf("%d ",m.top().B);
		m.pop();
	}
	printf("\n");

	return 0;
}