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

int T,n;
char s[1010][1010],ans[1010][1010];
pair<int,int> F(int d,int k) {
	int x=0,y=0;
	if (d<n-1) y=n-1-d;
	else if (d>n-1) x=d-(n-1);
	return MP(x+k,y+k);
}
int len[2010],rst[2010],lst[2010],m;
vector<pair<int,int> > vec;
int main() {
	read(T);
	while (T--) {
		read(n); read(m);
		for (int i=0;i<n;i++) scanf("%s",s[i]);
		for (int i=0;i<n;i++) for (int j=0;j<n;j++) ans[i][j]='1';
		for (int d=0;d<=n-1;d++) len[d]=d+1;
		for (int d=n;d<=2*(n-1);d++) len[d]=(2*(n-1)-d)+1;
		for (int d=0;d<=2*(n-1);d++) rst[d]=max(0,len[d]-(m-1)),lst[d]=-1;
		int flag=1;
		for (int rd=0;flag&&rd<=2*n;rd++) {
			vec.clear();
			for (int d=0;d<=2*(n-1)&&flag;d++) if (abs(d-(n-1))%2==rd%2&&rst[d]&&abs(d-(n-1))<=rd) {
				int x=lst[d]+1;
				if (d-1>=0) {
					if (d-1<n-1) x=max(x,lst[d-1]+1);
					else x=max(x,lst[d-1]);
				}
				if (d+1<=2*(n-1)) {
					if (d+1>n-1) x=max(x,lst[d+1]+1);
					else x=max(x,lst[d+1]);
				}
				while (1) {
					pair<int,int> A=F(d,x);
					if (A.first>=n||A.second>=n) { flag=0; break; }
					if (s[A.first][A.second]=='0') { x++; continue; }
					vec.push_back(MP(d,x)); ans[A.first][A.second]='0'; break;
				}
				rst[d]--;
			}
			for (pair<int,int> &A : vec) lst[A.first]=A.second;
		}
		if (!flag) { puts("NO"); continue; }
		puts("YES");
		for (int i=0;i<n;i++) {
			ans[i][n]=0; printf("%s\n",ans[i]);
		}
		
	}
	return 0;
}