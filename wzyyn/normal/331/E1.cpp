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
int e[N][N],st[N*N],ed[N*N],n,m;
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
	For(i,1,2*m) if ((i<=m)^flg)
		For(j,0,seq[i].size()-2)
			if (seq[i][j]==st[i]&&seq[i][j+1]==ed[i]){
			int sz=seq[i].size();
			vector<int> t1,t2;
			Rep(k,j-1,0) t1.PB(seq[i][k]);
			For(k,j+2,sz-1) t2.PB(seq[i][k]);
			pii res1=walk(t1,st[i],flg^1);
			pii res2=walk(t2,ed[i],flg);	
			if (res1.fi+res2.fi+1<=2*n){
				vector<int> ans;
				reverse(t1.begin(),t1.end());
				for (auto i:t1) ans.PB(i);
				ans.PB(st[i]); ans.PB(ed[i]);
				for (auto i:t2) ans.PB(i);
				if (flg) reverse(ans.begin(),ans.end());
				printf("%d\n",ans.size());
				for (auto i:ans) printf("%d ",i);
				exit(0);
			}		
		}
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
	}
	work(0);
	work(1);
	puts("0");
}