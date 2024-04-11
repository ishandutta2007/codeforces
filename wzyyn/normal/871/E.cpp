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
const int N=30005,K=205;
int n,k,fa[N];
int d[K][N],p[K];
int at[K][N];
vector<pii> vec[N];
void GG(){
	puts("-1");
	exit(0);
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,k) For(j,1,n)
		scanf("%d",&d[i][j]);
	For(i,1,k){
		For(j,1,n) if (!d[i][j])
			if (p[i]) GG();
			else p[i]=j;
		if (!p[i]) GG();
	}
	fa[p[1]]=-1;
	For(i,2,k){
		if (d[1][p[i]]!=d[i][p[1]]) GG();
		For(j,1,n)
			if (d[1][j]+d[i][j]==d[1][p[i]])
				if (at[i][d[1][j]]) GG();
				else at[i][d[1][j]]=j;
		For(j,0,d[1][p[i]])
			if (!at[j]) GG();
		For(j,1,d[1][p[i]]){
			int x=at[i][j],y=at[i][j-1];
			if (!fa[x]) fa[x]=y;
			else if (fa[x]!=y) GG();
		}
	}
	//cout<<233<<endl;
	//For(i,1,n) cout<<fa[i]<<' '; cout<<endl;
	For(i,1,n) if (fa[i]) vec[i].PB(pii(0,i));
	at[1][0]=p[1];
	For(i,1,n) if (!fa[i]){
		int id=1,v=0;
		For(j,2,k){
			int val=(d[1][i]+d[1][p[j]]-d[j][i])/2;
			if (val>v) v=val,id=j;
		}
		//cout<<i<<' '<<id<<' '<<v<<endl; 
		vec[at[id][v]].PB(pii(d[1][i]-v,i));
	}
	For(i,1,n) if (vec[i].size()){
		sort(vec[i].begin(),vec[i].end());
		pii la=vec[i][0];
		For(j,1,vec[i].size()-1){
			pii x=vec[i][j];
			if (x.fi>la.fi+1) la=vec[i][j-1];
			if (x.fi>la.fi+1) GG();
			fa[x.se]=la.se;
		}
	}
	For(i,1,n) if (fa[i]!=-1)
		printf("%d %d\n",i,fa[i]);
}
/*
 
*/