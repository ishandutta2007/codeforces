#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=5e8;
int T,x[5],y[5];
int d[5],p[5],ans;
int tx[5],ty[5];
void update(int &l,int &r,int L,int R) {
	l=max(l,L),r=min(r,R);
}
bool solve(int mid,bool flag) {
	int Lx,Rx,Ly,Ry,Lc,Rc;
	int La,Ra,Lb,Rb,Lac,Rac,Lbc,Rbc;
	La=Lb=Lac=Lbc=-INF,Ra=Rb=Rac=Rbc=INF;
	for (int i=1;i<=4;i++) {
		if (d[i]==1) Lx=x[i],Rx=x[i]+mid,Ly=Ry=y[i];
		else if (d[i]==2) Lx=Rx=x[i],Ly=y[i],Ry=y[i]+mid;
		else if (d[i]==3) Lx=x[i]-mid,Rx=x[i],Ly=Ry=y[i];
		else Lx=Rx=x[i],Ly=y[i]-mid,Ry=y[i];
		if (p[i]==1||p[i]==4) update(La,Ra,Lx,Rx);
		else update(Lac,Rac,Lx,Rx);
		if (p[i]==1||p[i]==2) update(Lb,Rb,Ly,Ry);
		else update(Lbc,Rbc,Ly,Ry);
	}
	if (La>Ra||Lb>Rb||Lac>Rac||Lbc>Rbc) return 0;
	Lc=max(Lac-Ra,Lbc-Rb),Rc=min(Rac-La,Rbc-Lb);
	Lc=max(1,Lc);
	if (Lc>Rc) return 0;
	if (flag) {
		int c=Lc,a=max(La,Lac-c),b=max(Lb,Lbc-c);
		for (int i=1;i<=4;i++) {
			if (p[i]==1||p[i]==4) tx[i]=a; else tx[i]=a+c;
			if (p[i]==1||p[i]==2) ty[i]=b; else ty[i]=b+c;
		}
	}
	return 1;
}
void dfs(int x) {
	if (x>5) {
		int l,r,mid,res;
		for (int i=1;i<=4;i++) p[i]=i;
		do {
			l=0,r=ans,res=ans+1;
			while (l<=r) {
				mid=(l+r)>>1;
				if (solve(mid,0)) res=mid,r=mid-1;
				else l=mid+1;
			}
			if (res<=ans) {
				ans=res,solve(res,1);
			}
		} while (next_permutation(p+1,p+5));
		return;
	}
	for (int i=1;i<=4;i++) d[x]=i,dfs(x+1);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		ans=INF;
		for (int i=1;i<=4;i++) read(x[i]),read(y[i]);
		dfs(1);
		if (ans==INF) puts("-1");
		else {
			printf("%d\n",ans);
			for (int i=1;i<=4;i++) printf("%d %d\n",tx[i],ty[i]);
		}
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/