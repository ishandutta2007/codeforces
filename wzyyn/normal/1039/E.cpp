#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;

const int N=100005;
const int B=100;
int n,cnt,w,Q,top,a[N],ans[N];
int L[N],R[N],nx[N],Nx[N],d[N];
int mn[N][20],mx[N][20];
pii op1[N*B/2],op2[N]; 
void change(int p){
	nx[p]++;
	int be=(p-1)/B+1;
	Rep(i,R[be],L[be])
		if (nx[i]<=R[be]){
			Nx[i]=Nx[nx[i]];
			d[i]=d[nx[i]]+1;
		}
		else{
			Nx[i]=i;
			d[i]=0;
		}
}
int main(){
	//#ifdef zyy
	//	freopen("1.in","r",stdin);
	//#endif
	scanf("%d%d%d",&n,&w,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) mn[i][0]=mx[i][0]=a[i];
	For(i,1,17) For(j,1,n-(1<<i)+1){
		mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
		mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
	}
	cnt=(n-1)/B+1;
	For(i,1,cnt){
		L[i]=(i-1)*B+1;
		R[i]=min(i*B,n);
		For(j,L[i],R[i]){
			int v1=a[j],v2=a[j];
			nx[j]=j+1;
			Nx[j]=R[i];
			d[j]=R[i]-j;
			For(k,j+1,R[i]){	
				v2=max(v2,a[k]);
				v1=min(v1,a[k]);
				op1[++top]=pii(v2-v1,j);
			}
		}
	}
	For(i,1,Q) scanf("%d",&op2[i].fi);
	For(i,1,Q) op2[i].fi=w-op2[i].fi;
	For(i,1,Q) op2[i].se=i;
	sort(op1+1,op1+top+1);
	sort(op2+1,op2+Q+1);
	int pos=1;
	For(i,1,Q){
		if (i%1000==0) cerr<<i<<' '<<clock()<<endl;
		for (;pos<=top&&op1[pos].fi<=op2[i].fi;)
			change(op1[pos++].se);
		int p=1,v=0,val=op2[i].fi;
		for (;p<=n;){
			v+=d[p]+1; p=Nx[p];
			//cout<<p<<' '<<d[p]<<endl;
			int v1=0,v2=1e9,j=0;
			for (;p+(1<<j)-1<=n;++j){
				int tv1=max(v1,mx[p][j]);
				int tv2=min(v2,mn[p][j]);
				if (tv1-tv2<=val) p+=(1<<j),v1=tv1,v2=tv2;
				else break;
			}
			for (--j;j>=0;--j)
				if (p+(1<<j)-1<=n){		
					int tv1=max(v1,mx[p][j]);
					int tv2=min(v2,mn[p][j]);
					if (tv1-tv2<=val) p+=(1<<j),v1=tv1,v2=tv2;
				}
		}
		ans[op2[i].se]=v-1;
	}
	For(i,1,Q)
		printf("%d\n",ans[i]);
}