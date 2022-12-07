#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int mo=1000000007;
int n,m,f[100005];
int main(){
	f[0]=f[1]=1;
	For(i,2,100000) f[i]=(f[i-1]+f[i-2])%mo;
	scanf("%d%d",&n,&m);
	int ans=(1ll*f[n]+f[m]+mo-1)%mo;
	printf("%d\n",2ll*ans%mo);
}