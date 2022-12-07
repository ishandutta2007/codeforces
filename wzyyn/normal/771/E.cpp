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
const int N=300005;
map<ll,int> mp;
map<pii,int> mpf;
int n,a[3][N];
int p[3][N],f[N];
ll b[N];
void init(int *a,int *p){
	mp.clear();
	mp[0]=0;
	For(i,1,n){
		b[i]=b[i-1]+a[i]; p[i]=p[i-1];
		if (mp.find(b[i])!=mp.end())
			p[i]=max(p[i],mp[b[i]]+1);
		mp[b[i]]=i;
	}
}
int F(int x,int y){
	if (x<0||y<0) return -(1<<30);
	if (x==y) return f[x];
	if (mpf.find(pii(x,y))!=mpf.end()) return mpf[pii(x,y)];
	if (x>y) return mpf[pii(x,y)]=max(f[y],F(p[0][x]-1,y)+1);
	return mpf[pii(x,y)]=max(f[x],F(x,p[1][y]-1)+1);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[0][i]);
	For(i,1,n) scanf("%d",&a[1][i]);
	For(i,1,n) a[2][i]=a[0][i]+a[1][i];
	For(i,0,2) init(a[i],p[i]);
	For(i,1,n){
		f[i]=f[i-1];
		//cout<<p[0][i]<<' '<<p[1][i]<<' '<<p[2][i]<<endl;
		if (p[2][i]) f[i]=max(f[i],f[p[2][i]-1]+1);
		f[i]=max(f[i],F(p[0][i]-1,i)+1);
		f[i]=max(f[i],F(i,p[1][i]-1)+1);
	}
	printf("%d\n",f[n]);
}