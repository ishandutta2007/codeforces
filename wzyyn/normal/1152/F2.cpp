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
const int mo=1000000007;
int n,k,m,nd;
int cnt[16],id[16][16];
struct Mat{
	int a[210][210];
	Mat(){
		memset(a,0,sizeof(a));
	}
	Mat operator *(const Mat &b)const{
		Mat ans;
		For(i,1,nd) For(j,1,nd) if (a[i][j])
			For(k,1,nd) ans.a[i][k]=(ans.a[i][k]+1ll*a[i][j]*b.a[j][k])%mo;
		return ans;
	}
}tr;
Mat power(Mat x,int y){
	Mat s;
	For(i,1,nd) s.a[i][i]=1;
	for (;y;y/=2,x=x*x)
		if (y&1) s=s*x;
	return s;
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	For(i,0,(1<<m)-1) For(j,0,k) id[i][j]=++nd;
	For(i,0,(1<<m)-1) cnt[i]=cnt[i/2]+(i&1);
	For(i,0,(1<<m)-1) For(j,0,k){
		tr.a[id[i][j]][id[i>>1][j]]=1;
		if (j^k) tr.a[id[i][j]][id[(i>>1)|(1<<(m-1))][j+1]]=cnt[i]+1;
	}
	tr=power(tr,n);
	int ans=0;
	For(i,0,(1<<m)-1)
		ans=(ans+tr.a[id[0][0]][id[i][k]])%mo;
	printf("%d\n",ans);
}