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
int n,m,v[N],a[N],sum[N*2];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,N-1) v[i]=(i-1)/2;
	int p=1;
	for (;m>v[p]&&p<=n;a[p]=p,m-=v[p++]);
	if (p>n) return puts("-1"),0;
	//cout<<p<<' '<<m<<endl;
	if (m){
		if (p>n) return puts("-1"),0;
		For(i,1,p-1) For(j,i+1,p-1) ++sum[i+j];
		For(i,p,2*p) if (sum[i]==m) a[p]=i;
		p++;
	}
	For(i,p,n) a[i]=100000000+i*10000;
	For(i,1,n) printf("%d ",a[i]);
}
/*
1234567
001122334455667788
*/