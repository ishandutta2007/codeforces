#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,m,c,q,fa[maxn];
map<int,int> fst[maxn];
set<int> s[maxn];
set<int>::iterator it;
char S[2];
int find(int x) {
	if (fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
	x=find(x); y=find(y);
	if (x==y) return;
	if (s[x].size()>s[y].size()) swap(x,y);
	for (it=s[x].begin();it!=s[x].end();it++)
		s[y].insert(*it);
	s[x].clear(); fa[x]=y;
}
void add(int x,int y,int z) {
	if (fst[x][z]) merge(fst[x][z],y);
	else fst[x][z]=y;
	if (fst[y][z]) merge(fst[y][z],x);
	else fst[y][z]=x;
	s[find(x)].insert(y);
	s[find(y)].insert(x);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(c); read(q); int x,y;
	for (int i=1;i<=n;i++) fa[i]=i,s[i].insert(i);
	for (int i=1;i<=m+q;i++) {
		if (i<=m) S[1]='+';
		else scanf("%s",S+1);
		read(x); read(y);
		if (S[1]=='+') read(c),add(x,y,c);
		else {
			if (find(x)==find(y)||s[find(x)].count(y))
				printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}