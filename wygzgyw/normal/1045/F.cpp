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
typedef long long ll;
const int maxn=(2e5)+10;
int n;
struct node {
	ll x,y;
	friend node operator + (node A,node B) { return (node){A.x+B.x,A.y+B.y}; }
	friend node operator - (node A,node B) { return (node){A.x-B.x,A.y-B.y}; }
	friend ll operator * (node A,node B) { return A.x*B.y-A.y*B.x; }
	ll len() { return x*x+y*y; }
	friend bool operator < (node A,node B) {
		return (A*B)>0||(A*B==0&&A.len()<B.len());
	}
};
int st[maxn],tot;
bool mk[maxn];
void convex(vector<node> A,vector<node> &B,vector<node> &C,bool flag) {
	int n=(int)A.size();
	int k=0;
	for (int i=1;i<n;i++) if (A[i].y<A[k].y||(A[i].y==A[k].y&&A[i].x<A[k].x)) k=i;
	swap(A[0],A[k]);
	node delta=A[0];
	for (int i=0;i<n;i++) A[i]=A[i]-delta;
	st[tot=1]=0;
	sort(A.begin()+1,A.end());
	for (int i=1;i<n;i++) {
		if (!flag) {
			while (tot>1&&(A[i]-A[st[tot-1]])*(A[st[tot]]-A[st[tot-1]])>0) tot--;
		} else {
			while (tot>1&&(A[i]-A[st[tot-1]])*(A[st[tot]]-A[st[tot-1]])>=0) tot--;
		}
		st[++tot]=i;
	}
	B.clear(); C.clear();
	for (int i=0;i<n;i++) mk[i]=0;
	for (int i=1;i<=tot;i++) mk[st[i]]=1;
	for (int i=1;i<=tot;i++) B.push_back(A[st[i]]+delta);
	for (int i=0;i<n;i++) if (!mk[i]) C.push_back(A[i]+delta);
}
int main() {
	read(n);
	vector<node> d(n);
	for (int i=0;i<n;i++) {
		read(d[i].x),read(d[i].y);
		if (d[i].x==0&&d[i].y==0) i--,n--;
	}
	d.push_back((node){0,0});
	vector<node> e,f;
	convex(d,e,f,1);
	for (node &A : e) if (A.x%2==1||A.y%2==1) { puts("Ani"); return 0; }
	convex(d,e,f,0);
	vector<node> A,B;
	for (node &t : f) A.push_back(t),B.push_back(t);
	for (int i=1;i<e.size();i++) if (i%2==1) A.push_back(e[i]); else B.push_back(e[i]);
	A.push_back((node){0,0}),B.push_back((node){0,0});
	convex(A,e,f,1);
	for (node &t : e) if (t.x%2==1||t.y%2==1) { puts("Ani"); return 0; }
	convex(B,e,f,1);
	for (node &t : e) if (t.x%2==1||t.y%2==1) { puts("Ani"); return 0; }
	puts("Borna");
	return 0;
}