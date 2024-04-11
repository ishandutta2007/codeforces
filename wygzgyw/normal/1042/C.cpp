#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,a[maxn],b[maxn],cnt,fu;
int c[maxn],tot;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) {
		read(a[i]);
		if (a[i]==0) cnt++;
		if (a[i]<0) fu++;
	}
	if (cnt==n) {
		for (int i=1;i<n;i++)
			printf("1 %d %d\n",i,n);
		return 0;
	}
	if ((fu==2||fu+cnt==0)&&n==2) {
		printf("1 1 2\n");
		return 0;
	}
	int id=0,id2=0;
	for (int i=1;i<=n;i++)
		if (a[i]==0) id=i;
	if (!id) {
		if (fu%2==1) {
			for (int i=1;i<=n;i++)
				if (a[i]<0&&(abs(a[i])<abs(a[id])||id==0))
					id=i;
		} else {
			for (int i=1;i<n;i++)
				printf("1 %d %d\n",i,n);
			return 0;
		}
		if (id==n) id2=n-1; else id2=n;
		printf("2 %d\n",id);
		for (int i=1;i<=n;i++)
			if (i!=id&&i!=id2) printf("1 %d %d\n",i,id2);
		return 0;
	}
	if (fu==1&&cnt==n-1) {
		for (int i=1;i<=n;i++)
			if (i!=id) printf("1 %d %d\n",i,id);
		return 0;
	}
	if (fu%2==1) {
		for (int i=1;i<=n;i++)
			if (a[i]<0&&(abs(a[i])<abs(a[id2])||id2==0))
				id2=i;
	}
	for (int i=1;i<=n;i++)
		if (a[i]==0&&i!=id) printf("1 %d %d\n",i,id);
	if (fu%2==1) printf("1 %d %d\n",id2,id);
	printf("2 %d\n",id);
	int k=0;
	for (int i=1;i<=n;i++)
		if (a[i]!=0&&i!=id2) k=i;
	for (int i=1;i<=n;i++)
		if (a[i]!=0&&i!=id2&&i!=k) printf("1 %d %d\n",i,k);
	return 0;
}