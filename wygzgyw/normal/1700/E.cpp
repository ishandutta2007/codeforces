// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(4e5)+10;
int n,m;
int rub[maxn];
int *now,*a[maxn];
int calc(int i,int j) {
	if (i>0&&a[i-1][j]<a[i][j]) return 1;
	if (j>0&&a[i][j-1]<a[i][j]) return 1;
	if (i<n-1&&a[i+1][j]<a[i][j]) return 1;
	if (j<m-1&&a[i][j+1]<a[i][j]) return 1;
	return 0;
}
vector<pair<int,int> > V,V2,V3;
int vis[maxn],tim,Now,rem[maxn];
void add(int x,int y) {
	if (vis[x*m+y]!=tim) vis[x*m+y]=tim,Now-=rem[x*m+y],Now+=calc(x,y);
}
void insert(int i,int j) {
	add(i,j);
	if (i>0) add(i-1,j);
	if (j>0) add(i,j-1);
	if (i<n-1) add(i+1,j);
	if (j<m-1) add(i,j+1);
}
int mk[maxn];
int main() {
	read(n),read(m);
	now=rub;
	for (int i=0;i<n;i++) a[i]=now,now+=m;
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) read(a[i][j]);
	int cnt=0;
	for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
		rem[i*m+j]=calc(i,j);
		if (rem[i*m+j]) cnt++;
		else if (a[i][j]>1) V.push_back(MP(i,j));
	}
	if (cnt==n*m-1) { puts("0"); return 0; }
	if ((int)V.size()>10) { puts("2"); return 0; }
	for (auto [x,y] : V) {
		V2.push_back(MP(x,y));
		if (x>0) V2.push_back(MP(x-1,y));
		if (y>0) V2.push_back(MP(x,y-1));
		if (x<n-1) V2.push_back(MP(x+1,y));
		if (y<m-1) V2.push_back(MP(x,y+1));
	}
	int C=0;
	sort(V2.begin(),V2.end());
	V2.resize(unique(V2.begin(),V2.end())-V2.begin());
	for (int i=0;i<V2.size();i++) mk[V2[i].first*m+V2[i].second]=i+1;
	for (int i=0;i<(int)V2.size();i++) for (int x=0;x<n;x++) for (int y=0;y<m;y++) if (V2[i]!=MP(x,y)) {
		if (mk[x*m+y]&&mk[x*m+y]-1>i) continue;
		swap(a[V2[i].first][V2[i].second],a[x][y]);
		tim++;
		Now=cnt;
		insert(V2[i].first,V2[i].second);
		insert(x,y);
		if (Now==n*m-1) C++;
		swap(a[V2[i].first][V2[i].second],a[x][y]);
	}
	if (C) printf("1 %d\n",C);
	else puts("2");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/