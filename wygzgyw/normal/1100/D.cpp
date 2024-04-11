#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int mid=500;
int a,b,k,A,B;
bool rooks[1010][1010];
struct node { int x,y; } d[1010];
int cnt[2][2];
void move(int x,int y) {
	if (rooks[x][y]) y=b;
	printf("%d %d\n",x,y);
	fflush(stdout);
	a=x,b=y;
	read(k); read(x); read(y);
	if (k<=0||x<=0||y<=0) exit(0);
	rooks[d[k].x][d[k].y]=0;
	d[k]=(node){x,y};
	rooks[d[k].x][d[k].y]=1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(a); read(b);
	int x,y;
	for (int i=1;i<=666;i++) {
		read(x); read(y);
		rooks[x][y]=1;
		d[i]=(node){x,y};
	}
	while (a!=mid||b!=mid) {
		x=a,y=b;
		if (x==mid) {
			if (y>mid) y--; else y++;
		} else if (y==mid) {
			if (x>mid) x--; else x++;
		} else {
			if (x>mid) x--; else x++;
			if (y>mid) y--; else y++;
		}
		move(x,y);
	}
	for (int i=1;i<=666;i++)
		cnt[d[i].x>mid][d[i].y>mid]++;
	x=y=0;
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++)
		if (cnt[i][j]<cnt[x][y]) x=i,y=j;
	while (1) {
		A=a,B=b;
		if (!x) A++; else A--;
		if (!y) B++; else B--;
		move(A,B);
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/