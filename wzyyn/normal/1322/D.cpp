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
const int N=5005;
int n,m,l[N],s[N],c[N];
int mx[N],f[N][N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&l[i]);
	For(i,1,n) scanf("%d",&s[i]);
	For(i,1,n+m) scanf("%d",&c[i]);
	For(i,1,n) s[i]=c[l[i]]-s[i];
	memset(f,233,sizeof(f));
	For(i,1,n+m) f[i][0]=0;
	Rep(i,n,1){
		int L=l[i];
		Rep(j,mx[L],0){
			int val=f[L][j]+s[i],t=j+1,p=L;
			for (;t;){
				//cout<<p<<' '<<t<<' '<<val<<endl;
				mx[p]=max(mx[p],t);
				f[p][t]=max(f[p][t],val);
				p++; t/=2; val+=c[p]*t;
			}
		}
		For(j,1,n+m)
			f[j][0]=max(f[j][0],max(f[j-1][0],f[j-1][1]));
	}
	printf("%d\n",f[n+m][0]);
}