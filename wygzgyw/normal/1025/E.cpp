#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0'; ch=getchar();} while ('0'<=ch&&ch<='9');t*=f;
}
struct node {
	int x,y,id;
} a[60],s[20000],t[20000];
int n,m;
bool cmp(node A,node B) {
	if (A.x==B.x) return A.y<B.y;
	return A.x<B.x;
}
int move(int cnt,int x1,int y1,int x2,int y2) {
	while (x1!=x2) {
		s[++cnt].x=x1; s[cnt].y=y1;
		if (x1<x2) x1++;
		else x1--;
		t[cnt].x=x1; t[cnt].y=y1;
	}
	while (y1!=y2) {
		s[++cnt].x=x1; s[cnt].y=y1;
		if (y1<y2) y1++;
		else y1--;
		t[cnt].x=x1; t[cnt].y=y1;
	}
	return cnt;
}
int solve(int cnt) {
	sort(a+1,a+(m+1),cmp);
	for (int i=1;i<=m;i++)
		if (i<a[i].x) {
			cnt=move(cnt,a[i].x,a[i].y,i,a[i].y);
			a[i].x=i;
		}
	for (int i=m;i>=1;i--) {
		cnt=move(cnt,a[i].x,a[i].y,i,a[i].y);
		a[i].x=i;
	}
	// x,y --> rank,y
	for (int i=1;i<=m;i++) {
		cnt=move(cnt,a[i].x,a[i].y,a[i].x,a[i].id);
		a[i].y=a[i].id;
	}
	// rank,y --> rank,i
	for (int i=1;i<=m;i++) {
		cnt=move(cnt,a[i].x,a[i].y,a[i].id,a[i].y);
		a[i].x=a[i].id;
	}
	// rank,i --> i,i
	return cnt;
}
int main() {
	read(n); read(m);
	for (int i=1;i<=m;i++)
		read(a[i].x),read(a[i].y),a[i].id=i;
	int c1=solve(0);
	for (int i=1;i<=m;i++)
		read(a[i].x),read(a[i].y),a[i].id=i;
	int c2=solve(c1);
	printf("%d\n",c2);
	for (int i=1;i<=c1;i++)
		printf("%d %d %d %d\n",s[i].x,s[i].y,t[i].x,t[i].y);
	for (int i=c2;i>c1;i--)
		printf("%d %d %d %d\n",t[i].x,t[i].y,s[i].x,s[i].y);
	return 0;
}