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
const int N=505,M=105;
int n,m,k,top;
int a[N],id[N],e[N][N],deg[N];
double d[N][N],v[N*N],prob[N];
int x[N*N],y[N*N],type[N*N];
struct mat{
	double a[M][M];
	mat(){
		memset(a,0,sizeof(a));
	}
}tr,ans;
mat operator *(mat a,mat b){
	mat ans;
	For(i,1,*id) For(j,1,*id) For(k,1,*id)
		ans.a[i][j]+=a.a[i][k]*b.a[k][j];
	return ans;
}
void gauss(){
	For(i,1,n){
		int p=-1;
		For(j,i,n)
			if (fabs(d[j][i])>1e-6){
				p=j; break;
			}
		if (p!=i){
			For(k,1,n)
				swap(d[i][k],d[p][k]);
			type[++top]=1;
			x[top]=i; y[top]=p;
		}
		For(j,1,n) if (j!=i){
			double tmp=-d[j][i]/d[i][i];
			type[++top]=2;
			x[top]=j; y[top]=i; v[top]=tmp;
			For(k,i,n) d[j][k]+=tmp*d[i][k];
		}
	}
}
/*
f(2)=(2f(1)+0.33)/3
f(1)=f(2)
*/
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) if (a[i]) id[i]=++*id;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		++deg[x]; ++deg[y];
		++e[x][y]; ++e[y][x];
	}
	For(i,1,n) For(j,1,n)
		if (!a[i]) d[j][i]=1.0*e[j][i]/deg[j];
	//cout<<d[2][3]<<' '<<d[2][1]<<endl;
	For(i,1,n) d[i][i]--;
	gauss();
	For(i,1,n) if (id[i]){
		For(j,1,n) prob[j]=-1.0*e[j][i]/deg[j];
		For(j,1,top){
			if (type[j]==1)
				swap(prob[x[j]],prob[y[j]]);
			else prob[x[j]]+=v[j]*prob[y[j]];
		}
		For(j,1,n) prob[j]/=d[j][j];
		//For(j,1,n) cout<<i<<' '<<j<<' '<<prob[j]<<endl;
		ans.a[1][id[i]]=prob[1];
		For(j,1,n) if (id[j])
			tr.a[id[j]][id[i]]=prob[j];
	}
	//cout<<ans.a[1][1]<<' '<<ans.a[1][2]<<endl;
	//cout<<tr.a[1][1]<<' '<<tr.a[1][2]<<endl;
	for (k-=2;k;k/=2,tr=tr*tr)
		if (k&1) ans=ans*tr;
	printf("%.15lf\n",ans.a[1][id[n]]);
}