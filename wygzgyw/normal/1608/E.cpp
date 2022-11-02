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
const int maxn=(3e5)+10;
int n;
struct node {
	int x,y,id;
};
vector<node> AX[3],AX2[3],BX[3],BX2[3],AX_Y[3],AX2_Y[3],BX_Y[3],BX2_Y[3];
int p[10];
int a,b,c;
bool cmpx(node A,node B) { return A.x<B.x; }
bool cmpy(node A,node B) { return A.y<B.y; }
vector<int> ans;
bool SOLVE(int mid,int flag,vector<node> *X,vector<node> *Y) {
	for (int i=0;i<3;i++) p[i]=i;
	do {
		a=p[0],b=p[1],c=p[2];
		int x=X[a][n/3-1-mid+1].x-1,y,C=0;
		for (int i=0;i<n/3;i++) if (Y[b][i].x<=x) { C++; if (C==mid) { y=Y[b][i].y+1; break; } }
		if (C==mid) {
			int cnt=0;
			for (int i=0;i<n/3;i++) if (X[c][i].x<=x&&X[c][i].y>=y) cnt++;
			if (cnt>=mid) {
				if (flag) {
					for (int i=n/3-1-mid+1;i<n/3;i++) ans.push_back(X[a][i].id);
					C=0;
					for (int i=0;i<n/3;i++) if (Y[b][i].x<=x) { C++; ans.push_back(Y[b][i].id); if (C==mid) break; }
					cnt=0;
					for (int i=0;i<n/3;i++) if (X[c][i].x<=x&&X[c][i].y>=y) {
						if (cnt==mid) break;
						cnt++; ans.push_back(X[c][i].id);
					}
				}
				return 1;
			}
		}
	} while (next_permutation(p,p+3));
	return 0;
}
int remX[maxn],remY[maxn],remZ[maxn];
bool solve(int mid,int flag=0) {
	if (mid==0) {
		return 1;
	}
	for (int i=0;i<3;i++) p[i]=i;
	do {
		a=p[0],b=p[1],c=p[2];
		int x=AX[c][mid-1].x+1,fd=-1,f2;
		for (int i=0;i<n/3;i++) if (AX[b][i].x>=x) { fd=i; break; }
		if (fd!=-1&&fd+mid-1<n/3) {
			x=AX[b][fd+mid-1].x+1; f2=-1;
			for (int i=0;i<n/3;i++) if (AX[a][i].x>=x) { f2=i; break; }
			if (f2!=-1&&f2+mid-1<n/3) {
				if (flag) {
					for (int i=0;i<mid;i++) ans.push_back(AX[c][i].id);
					for (int i=fd;i<=fd+mid-1;i++) ans.push_back(AX[b][i].id);
					for (int i=f2;i<=f2+mid-1;i++) ans.push_back(AX[a][i].id);
				}	
				return 1;
			}
		}
	} while (next_permutation(p,p+3));
	for (int i=0;i<3;i++) p[i]=i;
	do {
		a=p[0],b=p[1],c=p[2];
		int x=AX_Y[c][mid-1].y+1,fd=-1,f2;
		for (int i=0;i<n/3;i++) if (AX_Y[b][i].y>=x) { fd=i; break; }
		if (fd!=-1&&fd+mid-1<n/3) {
			x=AX_Y[b][fd+mid-1].y+1; f2=-1;
			for (int i=0;i<n/3;i++) if (AX_Y[a][i].y>=x) { f2=i; break; }
			if (f2!=-1&&f2+mid-1<n/3) {
				if (flag) {
					for (int i=0;i<mid;i++) ans.push_back(AX_Y[c][i].id);
					for (int i=fd;i<=fd+mid-1;i++) ans.push_back(AX_Y[b][i].id);
					for (int i=f2;i<=f2+mid-1;i++) ans.push_back(AX_Y[a][i].id);
				}	
				return 1;
			}
		}
	} while (next_permutation(p,p+3));
	if (SOLVE(mid,flag,AX,AX_Y)) return 1;
	if (SOLVE(mid,flag,AX2,AX2_Y)) return 1;
	if (SOLVE(mid,flag,BX,BX_Y)) return 1;
	if (SOLVE(mid,flag,BX2,BX2_Y)) return 1;
	return 0;
}
int xyr[10],L1[3],R1[3],L2[3],R2[3]; bool used[maxn];
void insert(int i) {
	if (used[i]) assert(0); used[i]=1;
	int x=remX[i],y=remY[i],z=remZ[i];
	xyr[z]++;
	if (xyr[z]==1) L1[z]=R1[z]=x,L2[z]=R2[z]=y;
	else L1[z]=min(L1[z],x),L2[z]=min(L2[z],y),R1[z]=max(R1[z],x),R2[z]=max(R2[z],y);
	for (int i=0;i<3;i++) for (int j=i+1;j<3;j++) if (xyr[i]&&xyr[j]) {
		if (max(L1[i],L1[j])<=min(R1[i],R1[j])&&max(L2[i],L2[j])<=min(R2[i],R2[j])) assert(0);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	int x,y,z;
	for (int i=1;i<=n;i++) {
		read(x),read(y),read(z); z--;
		remX[i]=x,remY[i]=y,remZ[i]=z;
		AX[z].push_back((node){x,y,i}); AX_Y[z].push_back((node){x,y,i});
		AX2[z].push_back((node){-x,y,i}); AX2_Y[z].push_back((node){-x,y,i});
		BX[z].push_back((node){y,x,i}); BX_Y[z].push_back((node){y,x,i});
		BX2[z].push_back((node){-y,x,i}); BX2_Y[z].push_back((node){-y,x,i});
	}
	for (int i=0;i<3;i++) {
		sort(AX[i].begin(),AX[i].end(),cmpx);
		sort(AX_Y[i].begin(),AX_Y[i].end(),cmpy);
		sort(AX2[i].begin(),AX2[i].end(),cmpx);
		sort(AX2_Y[i].begin(),AX2_Y[i].end(),cmpy);
		sort(BX[i].begin(),BX[i].end(),cmpx);
		sort(BX_Y[i].begin(),BX_Y[i].end(),cmpy);
		sort(BX2[i].begin(),BX2[i].end(),cmpx);
		sort(BX2_Y[i].begin(),BX2_Y[i].end(),cmpy);
	}
	int l=0,r=n/3,res,mid;
	while (l<=r) {
		mid=(l+r)>>1;
		if (solve(mid)) res=mid,l=mid+1; else r=mid-1;
	}
	solve(res,1);
	
	//for (int &i : ans) insert(i);
	//assert(xyr[0]==xyr[1]&&xyr[1]==xyr[2]);
	//puts("AC");
	//exit(0);
	printf("%d\n",(int)ans.size());
	//for (int &x : ans) printf("%d ",x); puts("");
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