#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=5010;
int T,n;
char s[maxn];
void move(int &x,int &y,char ch) {
	if (ch=='U') y++;
	else if (ch=='D') y--;
	else if (ch=='L') x--;
	else x++;
}
bool solve(int xx,int yy) {
	int nx,ny,x=0,y=0;
	for (int i=1;i<=n;i++) {
		nx=x,ny=y; move(nx,ny,s[i]);
		if (nx==xx&&ny==yy);
		else x=nx,y=ny;
	}
	return x==0&&y==0;
}
int main() {
	//freopen("1.txt","r",stdin);
	int x,y,flag;
	read(T);
	while (T--) {
		scanf("%s",s+1); n=strlen(s+1);
		x=y=flag=0;
		for (int i=1;i<=n;i++) {
			move(x,y,s[i]);
			if (solve(x,y)) {
				flag=1;
				printf("%d %d\n",x,y);
				break;
			}
		}
		if (!flag) puts("0 0");
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/