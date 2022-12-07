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
int q[65],k;
ll n;
struct Mat{
	int a[32][32];
	Mat(){
		memset(a,0,sizeof(a));
	}
	Mat operator *(const Mat &b)const{
		Mat c;
		For(i,0,::k) For(j,0,::k) For(k,0,::k)
			c.a[i][k]=(c.a[i][k]+1ll*a[i][j]*b.a[j][k])%mo;
		return c;
	}
};
Mat pre[32],suf[32];
Mat f[65][32],ans;
int main(){
	scanf("%lld%d",&n,&k);
	ans.a[0][k]=1;
	for (;n;n/=k) q[++*q]=n%k;
	For(i,0,k-1) For(j,0,k)
		f[1][i].a[j][i]=f[1][i].a[j][j]=1;
	//For(i,1,*q) cout<<q[i]<<' '; cout<<endl;
	For(i,2,*q){
		pre[0]=f[i-1][0];
		suf[k-1]=f[i-1][k-1];
		For(j,1,k-1) pre[j]=pre[j-1]*f[i-1][j];
		Rep(j,k-2,0) suf[j]=f[i-1][j]*suf[j+1];
		f[i][0]=suf[0];
		For(j,1,k-1) f[i][j]=suf[j]*pre[j-1];
	}
	int sum=0;
	Rep(i,*q,1){
		For(j,0,q[i]-1)
			ans=ans*f[i][(sum+j)%k];
		sum=(sum+q[i])%mo;
	}
	sum=0;
	For(i,0,k) sum=(sum+1ll*ans.a[0][i])%mo;
	printf("%d\n",sum);
}