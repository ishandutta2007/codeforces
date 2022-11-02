#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n;
vector<char> s[10010];
int main() {
//	freopen("1.txt","r",stdin);
	read(n);
	for (int x=5;x<=n;x++)
		if (n%x==0&&n/x>=5) {
			int y=n/x,tot=0;
			for (int i=1;i<=x;i++) {
				for (int j=0;j<=y;j++) s[i].push_back('a');
				for (int j=1;j<=y;j++) {
					tot=(i+j)%5;
					if (tot==1) s[i][j]='a';
					if (tot==2) s[i][j]='e';
					if (tot==3) s[i][j]='i';
					if (tot==4) s[i][j]='o';
					if (tot==0) s[i][j]='u';
				}
			}
			for (int i=1;i<=x;i++) {
			for (int j=1;j<=y;j++)
				printf("%c",s[i][j]);
			//printf("\n");
			}
			printf("\n"); return 0;
		}
	printf("-1\n");
	return 0;
}