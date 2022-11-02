#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e18;
int T,id[5],tot;
ll tmp,ans=INF,d[5];
struct node { int x,y; } p[10],p2[10];
void add(int x,int y) {
	tmp+=abs(x-y);
}
void solve(int x1,int x2,int y1,int y2) {
	p2[1]=(node){x1,y1},p2[2]=(node){x1,y2};
	p2[3]=(node){x2,y1},p2[4]=(node){x2,y2};
	for (int i=1;i<=4;i++) id[i]=i;
	do {
		tmp=0; tot=0;
		for (int i=1;i<=4;i++) {
			add(p[id[i]].x,p2[i].x),add(p[id[i]].y,p2[i].y);
		}
		ans=min(ans,tmp);
	} while (next_permutation(id+1,id+5));
}
int main() {
	//freopen("1.txt","r",stdin);
	int x1,y1,x2,y2;
	read(T);
	while (T--) {
		for (int i=1;i<=4;i++) read(p[i].x),read(p[i].y);
		ans=INF;
		for (int i=1;i<=4;i++)
		for (int j=i;j<=4;j++)
		for (int k=1;k<=4;k++) {
			x1=p[i].x,x2=p[j].x,y1=p[k].y;
			solve(x1,x2,y1,y1-abs(x2-x1));
			solve(x1,x2,y1,y1+abs(x2-x1));
			y1=p[i].y,y2=p[j].y,x1=p[k].x;
			solve(x1,x1+abs(y2-y1),y1,y2);
			solve(x1,x1-abs(y2-y1),y1,y2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}