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
int n,f[1000005];
int main(){
	f[1]=f[2]=1;
	for (int i=4,t=1;i<=1000000;i=i*2+t,t=3-t)
		f[i]=f[i+1]=1;
	scanf("%d",&n);
	printf("%d\n",f[n]);
}