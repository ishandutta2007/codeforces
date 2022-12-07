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
const int N=105;
int n,m,id[N],ans[N];
int a[N][N],dif[N];
bool cmp(int x,int y){
	return dif[x]<dif[y];
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m) For(j,1,n) scanf("%d",&a[i][j]);
	For(i,1,m) ans[++*ans]=i;
	For(i,1,m) id[i]=i;
	For(i,1,n-1){
		int S=0;
		For(j,1,m) dif[j]=a[j][i]-a[j][n];
		sort(id+1,id+m+1,cmp);
		For(j,1,m) S+=dif[j];
		For(j,1,m){
			if (S>=0){
				//printf("A %d %d\n",i,j);
				if (j-1<=*ans){
					*ans=0;
					For(k,1,j-1) ans[++*ans]=id[k];
				}
				break;
			}
			S-=dif[id[j]];
		}
	}
	printf("%d\n",*ans);
	For(i,1,*ans) printf("%d ",ans[i]);
}