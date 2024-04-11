#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=400005;
int n,Q,top;
int x[N],y[N];
int qx[N],qy[N];
int vx[N],vy[N];
vector<int> vecx[N],vecy[N];
map<pii,int> mp;
struct node{
	int l,r,v;
}op[N];
bool check(int x,int y){
	int l=1,r=top;
	while (l<=r){
		int mid=(l+r)/2;
		if (op[mid].r<x) l=mid+1;
		else if (op[mid].l>x) r=mid-1;
		else return y==x+op[mid].v;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	For(i,1,n) mp[pii(x[i],y[i])]=1;
	For(i,1,n) qx[i]=x[i],qy[i]=y[i];
	*qx=n; *qy=n;
	qx[++*qx]=qy[++*qy]=-1;
	qx[++*qx]=qy[++*qy]=1<<30;
	sort(qx+1,qx+*qx+1);
	sort(qy+1,qy+*qy+1);
	*qx=unique(qx+1,qx+*qx+1)-qx-1;
	*qy=unique(qy+1,qy+*qy+1)-qy-1;
	For(i,1,n){
		int px=lower_bound(qx+1,qx+*qx+1,x[i])-qx;
		int py=lower_bound(qy+1,qy+*qy+1,y[i])-qy;
		vecx[px].PB(py);
		vecy[py].PB(px);
	}
	int tx=1,ty=1,px=0,py=0;
	for (;;){
		//cout<<tx<<' '<<ty<<' '<<px<<' '<<py<<' '<<qx[tx+1]<<' '<<qy[ty+1]<<' '<<endl;
		int v=min(qx[tx+1]-px,qy[ty+1]-py);
		if (v) op[++top]=(node){px,px+v-1,py-px};
		px+=v; py+=v;
		bool flg=0;
		if (qx[tx+1]==px) flg|=vx[tx+1]; 
		if (qy[ty+1]==py) flg|=vy[ty+1];
		if (!flg){
			op[++top]=(node){px,px,py-px};
			if (qx[tx+1]==px){
				++tx;
				for (auto i:vecx[tx]) vy[i]=1;
			}
			if (qy[ty+1]==py){
				++ty;
				for (auto i:vecy[ty]) vx[i]=1;
			}
			++px; ++py;
		}
		else{
			if (qx[tx+1]==px&&vx[tx+1]){
				++tx; ++px;
				for (auto i:vecx[tx]) vy[i]=1;
			}
			if (qy[ty+1]==py&&vy[ty+1]){
				++ty; ++py;
				for (auto i:vecy[ty]) vx[i]=1;
			}
		}
		if (tx==*qx||ty==*qy) break;
	}
	//For(i,1,top) cout<<op[i].l<<' '<<op[i].r<<' '<<op[i].v<<endl;
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (mp.count(pii(x,y))) puts("LOSE");
		else if (check(x,y)) puts("LOSE");
		else puts("WIN");
	}
}