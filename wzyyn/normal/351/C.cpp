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
int n,m,a[25],b[25];
struct Mat{
	ll a[45][45];
	Mat(){
		memset(a,10,sizeof(a));
	}
	Mat operator *(const Mat &b)const{
		Mat ans;
		For(i,0,2*n) For(j,0,2*n) For(k,0,2*n)
			ans.a[i][j]=min(ans.a[i][j],a[i][k]+b.a[k][j]);
		return ans;
	}
};
Mat power(Mat a,int b){
	Mat s;
	For(i,0,2*n) s.a[i][i]=0;
	for (;b;b/=2,a=a*a)
		if (b&1) s=s*a;
	return s;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	Mat ans;
	For(i,0,2*n) ans.a[i][i]=0;
	For(i,1,n){
		Mat tmp;
		For(j,1,2*n){
			tmp.a[j-1][j]=a[i];
			tmp.a[j][j-1]=b[i];
		}
		ans=ans*tmp;
	}
	ans=power(ans,m);
	printf("%lld ",ans.a[0][0]);
}