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
int f[5][1000];
int n,x,y,z,mx,len;
ll a[300005];
int MEX(int x,int y,int z){
	if (x!=0&&y!=0&&z!=0) return 0;
	if (x!=1&&y!=1&&z!=1) return 1;
	if (x!=2&&y!=2&&z!=2) return 2;
	if (x!=3&&y!=3&&z!=3) return 3;
}
int Func(int x,ll y){
	if (y<=200) return f[x][y];
	return f[x][y-y/len*len+30*len];
}
void solve(){
	scanf("%d",&n);
	scanf("%d%d%d",&x,&y,&z);
	For(i,1,500){
		f[0][i]=MEX(f[0][max(0,i-x)],f[1][max(0,i-y)],f[2][max(0,i-z)]);
		f[1][i]=MEX(f[0][max(0,i-x)],3               ,f[2][max(0,i-z)]);
		f[2][i]=MEX(f[0][max(0,i-x)],f[1][max(0,i-y)],3);
	}
	len=10,mx=0;
	For(i,1,20){
		int v=0;
		For(j,i+1,500){
			v+=(f[0][j]==f[0][j-i]);
			v+=(f[1][j]==f[1][j-i]);
			v+=(f[2][j]==f[2][j-i]);
		}
		if (v>mx) mx=v,len=i;
	}
	//cout<<mx<<' '<<len<<endl;
	int val=0,sum=0;
	For(i,1,n){
		scanf("%lld",&a[i]);
		val^=Func(0,a[i]);
	}
	For(i,1,n){
		int tmp=val^Func(0,a[i]);
		if (tmp==Func(0,max(a[i]-x,0ll))) ++sum;
		if (tmp==Func(1,max(a[i]-y,0ll))) ++sum;
		if (tmp==Func(2,max(a[i]-z,0ll))) ++sum;
	}
	printf("%d\n",sum);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}