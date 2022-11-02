#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int n,m[10],x,a[10],ans;
int b[10][4];
char s[100];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=7;i++) m[i]=(1e8);
	for (int i=1;i<=n;i++) {
		read(x); scanf("%s",s+1);
		int len=strlen(s+1);
		if (len==3) m[7]=min(m[7],x);
		else {
			memset(a,0,sizeof(a));
			for (int j=1;j<=len;j++)
				a[s[j]-'A'+1]=1;
			if (a[1]&&!a[2]&&!a[3]) m[1]=min(m[1],x);
			else if (!a[1]&&a[2]&&!a[3]) m[2]=min(m[2],x);
			else if (!a[1]&&!a[2]&&a[3]) m[3]=min(m[3],x);
			else if (a[1]&&a[2]&&!a[3]) m[4]=min(m[4],x);
			else if (a[1]&&!a[2]&&a[3]) m[5]=min(m[5],x);
			else m[6]=min(m[6],x);
		}
	}
	b[1][1]=1;
	b[2][2]=1;
	b[3][3]=1;
	b[4][1]=b[4][2]=1;
	b[5][1]=b[5][3]=1;
	b[6][2]=b[6][3]=1;
	b[7][1]=b[7][2]=b[7][3]=1;
	ans=(5e8);
	for (int i=1;i<=7;i++)
	for (int j=0;j<=7;j++)
	for (int k=0;k<=7;k++) {
		if (i==j||i==k) continue;
		if (j==k&&j>0) continue;
		if (m[i]==(1e8)||m[j]==(1e8)||m[k]==(1e8)) continue;
		memset(a,0,sizeof(a));
		for (int l=1;l<=3;l++)
			a[l]|=b[i][l]|b[j][l]|b[k][l];
		if (!a[1]||!a[2]||!a[3]) continue;
		ans=min(ans,m[i]+m[j]+m[k]);
	}
	if (ans==(5e8)) ans=-1;
	printf("%d\n",ans);
	return 0;
}