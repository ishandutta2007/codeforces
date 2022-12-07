#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=300005;
int n,Q,a[N],ans[N];
int d[20][20],tmp[20];
vector<pii > vec[N];
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,Q){
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].PB(pii(y,i));
	}
	For(i,0,18) For(j,0,18)
		d[i][j]=(1<<30);
	Rep(i,n,1){
		For(j,0,vec[i].size()-1){
			int x=i,y=vec[i][j].fi,fl=0;
			for (int v1=0;v1<=18&&!fl;++v1) if (a[x]&(1<<v1))
				for (int v2=0;v2<=18&&!fl;++v2) if (a[y]&(1<<v2))
					if (d[v1][v2]<=y) fl=1;
			ans[vec[i][j].se]=fl;
		}
		For(j,0,18) tmp[j]=(1<<30);
		For(j,0,18) if (a[i]&(1<<j))
			For(k,0,18) tmp[k]=min(tmp[k],d[j][k]);
		For(j,0,18) if (a[i]&(1<<j)) tmp[j]=i;
		For(j,0,18) if (a[i]&(1<<j))
			For(k,0,18) d[j][k]=tmp[k];
	}
	For(i,1,Q) puts(ans[i]?"Shi":"Fou");
}