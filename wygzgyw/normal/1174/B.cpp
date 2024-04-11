#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
const int maxn=(1e5)+10;
int n,a[maxn],l1,l2,tmp,cur;
pair<int,int> A,B;
set<pair<int,int> > q[2];
void SW(int u,int i) {
	if (u<i) swap(u,i);
	int op=a[u]%2;
	//printf("S %d %d\n",a[u],a[i]);
	if (u>=cur) q[op].erase(q[op].find(make_pair(a[u],u)));
	if (i>=cur) q[op].insert(make_pair(a[u],i));
	if (i>=cur) q[op^1].erase(q[op^1].find(make_pair(a[i],i)));
	if (u>=cur) q[op^1].insert(make_pair(a[i],u));
	swap(a[u],a[i]);
	if (l1==u) l1=i;
	else if (l1==i) l1=u;
	if (l2==u) l2=i;
	else if (l2==i) l2=u;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) q[a[i]%2].insert(make_pair(a[i],i));
	for (int i=1;i<=n;i++) if (a[i]&1) l1=i; else l2=i;
	for (int i=1;i<=n;i++) {
		int u,v; cur=i;
		if (q[0].empty()) u=INF;
		else A=*(q[0].begin()),u=A.first;
		if (q[1].empty()) v=INF;
		else B=*(q[1].begin()),v=B.first;
		/*printf("%d %d %d\n",u,v,i);
		for (int j=1;j<=n;j++)
			printf("%d ",a[j]);
		printf("\n");*/
		if (a[i]==min(u,v)) {
			int op=a[i]%2;
			q[op].erase(q[op].find(make_pair(a[i],i)));
			continue;
		}
		if (min(u,v)%2!=a[i]%2) {
			if (u<v) {
				u=A.second;
				SW(u,i);
			} else {
				v=B.second;
				SW(v,i);
			}
		} else {
			if (u<v) {
				//printf("%d %d\n",B.second,i);
				tmp=l1;
				if (!tmp) continue;
				//printf("%d %d %d\n",tmp,i,A.second);
				SW(tmp,i);
				//printf("%d %d\n",A.second,i);
				SW(A.second,i);
				SW(tmp,A.second);
			} else {
				tmp=l2;
				if (!tmp) continue;
				SW(tmp,i);
				SW(B.second,i);
				SW(tmp,B.second);
			}
		}
		int op=a[i]%2;
		q[op].erase(q[op].find(make_pair(a[i],i)));
	}
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}