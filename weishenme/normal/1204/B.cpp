#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define int long long
const int N=1000005;
int a[N],b[N],c[N],n,m,k,l,r,tot,ne[N],fi[N],zz[N];
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
signed main(){
	scanf("%lld%lld%lld",&n,&l,&r);
	int ans1=n-l+1,ans2=0;
	for (int i=1;i<l;i++)ans1+=1<<i;
	for (int i=0;i<r-1;i++)ans2+=1<<i;
	ans2+=(1<<(r-1))*(n-r+1);
	printf("%lld %lld\n",ans1,ans2);
}