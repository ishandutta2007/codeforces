#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> coors;
map<int,int> ids;

class ST {
private:
	int size;
	int st[1600013];
	int lazy[1600013];
	int left(int w) { return w<<1; }
	int right(int w) { return (w<<1)+1; }
	void process(int w, int L, int R) {
		st[w] = coors[R+1]-coors[L];
		if (L!=R) {
			lazy[left(w)] = 1;
			lazy[right(w)] = 1;
		}
		lazy[w] = 0;
	}
	void updateI(int w, int L, int R, int a, int b) {
		if (lazy[w]) process(w,L,R);
		if (a>R || b<L) return;
		if (a<=L && R<=b) {
			lazy[w] = 1;
			process(w,L,R);
			return;
		}
		updateI(left(w),L,(L+R)/2,a,b);
		updateI(right(w),(L+R)/2+1,R,a,b);
		st[w] = st[left(w)]+st[right(w)];
	}
	int queryI(int w, int L, int R, int a, int b) {
		if (lazy[w]) process(w,L,R);
		if (a>R || b<L) return 0;
		if (a<=L && R<=b) return st[w];
		int one = queryI(left(w),L,(L+R)/2,a,b);
		int two = queryI(right(w),(L+R)/2+1,R,a,b);
		return one+two;
	}
public:
	ST(int s=0) {
		size = s;
		fill(st,st+4*size,0);
		fill(lazy,lazy+4*size,0);
	}
	void update(int a, int b) { updateI(1,0,size-1,a,b); }
	int query(int a, int b) { return queryI(1,0,size-1,a,b); }
};

int n,q;
int p[200000];
int l[200000];
int x[200000];
int y[200000];
vector<int> needs[200000];
int ans[200000];
ST tree;

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d%d",&p[i],&l[i]);
        if (!ids.count(p[i])) {
            ids[p[i]] = 1;
            coors.push_back(p[i]);
        }
        if (!ids.count(p[i]+l[i])) {
            ids[p[i]+l[i]] = 1;
            coors.push_back(p[i]+l[i]);
        }
    }
    sort(coors.begin(),coors.end());
    ids.clear();
    for (int i=0;i<coors.size();i++) ids[coors[i]] = i;
    scanf("%d",&q);
    for (int i=0;i<q;i++) {
        scanf("%d%d",&x[i],&y[i]);
        x[i]-=1; y[i]-=1;
        needs[x[i]].push_back(i);
    }
    tree = ST(coors.size()-1);
    for (int i=n-1;i>=0;i--) {
        tree.update(ids[p[i]],ids[p[i]+l[i]]-1);
        for (int j=0;j<needs[i].size();j++) ans[needs[i][j]] = p[y[needs[i][j]]]-p[i]-tree.query(ids[p[i]],ids[p[y[needs[i][j]]]]-1);
    }
    for (int i=0;i<q;i++) printf("%d\n",ans[i]);

    return 0;
}