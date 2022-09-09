#include <bits/stdc++.h>
using namespace std;
void ckmx(int &x,int y){x=max(x,y);}
const int N=2050;
struct DSU{
	int p[N];
	void init(){for(int i=0;i<N;i++)p[i]=i;}
	DSU(){init();}
	int Find(int x){return p[x]==x?x:p[x]=Find(p[x]);}
}L[N],R[N];
char s[N][N];
int dp[N][N],l[N],r[N],x[N],y[N],ans[N];
int main(){
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=k;i++)scanf("%i %i",&x[i],&y[i]),s[x[i]][y[i]]='X';
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		dp[i][j]=s[i][j]=='X'?0:min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1,
		ckmx(ans[k],dp[i][j]),L[i].p[j]=s[i][j]=='X'?j:j-1,R[i].p[j]=s[i][j]=='X'?j:j+1;
	for(int j=k;j>=2;j--){
		int now=ans[j];
		L[x[j]].p[y[j]]=y[j]-1;
		R[x[j]].p[y[j]]=y[j]+1;
		l[x[j]]=L[x[j]].Find(y[j]);
		r[x[j]]=R[x[j]].Find(y[j]);
		for(int i=x[j]-1;i>=1;i--){
			l[i]=max(l[i+1],L[i].Find(y[j]));
			r[i]=min(r[i+1],R[i].Find(y[j]));
		}
		for(int i=x[j]+1;i<=n;i++){
			l[i]=max(l[i-1],L[i].Find(y[j]));
			r[i]=min(r[i-1],R[i].Find(y[j]));
		}
		for(int i=min(x[j],n-now);i>=1 && i+now>=x[j] && i+now<=n;i--)
			while(i+now<=n && min(r[i],r[i+now])-max(l[i],l[i+now])-1>=now+1)
				now++;
		ans[j-1]=now;
	}
	for(int i=1;i<=k;i++)printf("%i\n",ans[i]);
	return 0;
}