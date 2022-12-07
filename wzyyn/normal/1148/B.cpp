#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=200005;
int n,m,T1,T2,k;
int a[N],b[N];
int main(){
	scanf("%d%d%d%d%d",&n,&m,&T1,&T2,&k);
	For(i,1,n) scanf("%d",&a[i]),a[i]+=T1;
	For(i,1,m) scanf("%d",&b[i]);
	int pos=1,rest=k;
	For(i,1,m){
		if (pos<=n&&a[pos]<=b[i])
			++pos,--rest;
		if (rest<0){
			printf("%lld\n",1ll*b[i]+T2);
			return 0;
		}
	}
	puts("-1");
}