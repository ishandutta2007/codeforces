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
const int mo=1e9+7;
const int N=55;
int f[2][2*N][N];
int g[2][2][2*N][N][N];
int e[N][N],st[N*N],ed[N*N],n,m;
int v1[2*N][N][N],v2[2*N][N][N];
vector<int> seq[N*N];
pii walk(vector<int> &vec,int x,int flg){
	int p=0;
	for(;p+1<=vec.size();){
		int y=vec[p],ed=e[x][y];
		if (!ed||vec.size()>2*n||((ed>m)^flg))
			return pii(23333,-1);
		for (auto j:seq[ed]) vec.PB(j);
		x=y; ++p;
	}
	return pii(vec.size(),x);
}
void work(bool flg){
	memset(v1,0,sizeof(v1));
	memset(v2,0,sizeof(v2));
	For(i,1,2*m) if ((i<=m)^flg)
		For(j,0,seq[i].size()-1) if (seq[i][j]==st[i]){
			//cout<<i<<' '<<j<<endl;
			int sz=seq[i].size();
			vector<int> t1,t2;
			Rep(k,j-1,0) t1.PB(seq[i][k]);
			pii res1=walk(t1,st[i],flg^1);
			//cout<<i<<' '<<j<<' '<<res1.fi<<' '<<res1.se<<endl;
			if (res1.fi>2*n) continue;
			if (j+1==sz) ++v2[res1.fi+1][res1.se][ed[i]];
			else if (seq[i][j+1]==ed[i]){
				For(k,j+2,sz-1) t2.PB(seq[i][k]);
				pii res2=walk(t2,ed[i],flg);
				if (res2.fi+res1.fi+1<=2*n)
					++v1[res1.fi+res2.fi+1][res1.se][res2.se];
			}			
		}
}
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y,cnt,v;
		scanf("%d%d%d",&x,&y,&cnt);
		e[x][y]=i; e[y][x]=i+m;
		st[i]=ed[i+m]=x; ed[i]=st[i+m]=y;
		For(j,1,cnt){
			scanf("%d",&v);
			seq[i].PB(v);
		}
		seq[i+m]=seq[i];
		reverse(seq[i+m].begin(),seq[i+m].end());
		if (!cnt) ++g[0][0][1][x][y];
	}
	work(0);
	memcpy(g[1][1],v1,sizeof(v1));
	memcpy(g[1][0],v2,sizeof(v2));
	work(1);
	For(l,1,n*2) For(x,1,n) For(y,1,n)
		g[0][1][l][x][y]=v2[l][y][x];
	For(l,1,n*2) For(x,1,n) For(y,1,n) For(fl,0,1)
		UPD(f[fl][l][y],g[1][fl][l][x][y]);
	For(l,1,n*2){
		int ans=0;
		For(i,1,n){
			UPD(ans,f[1][l][i]);
			For(la,0,1) For(no,0,1)
				For(j,0,2*n-l) For(k,1,n)
					UPD(f[no][l+j][k],1ll*f[la][l][i]*g[la^1][no][j][i][k]%mo);
		}
		printf("%d\n",ans);
	}
}