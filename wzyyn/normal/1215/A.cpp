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
int a1,a2,k1,k2,n;
int main(){
	scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
	int low=a1*(k1-1)+a2*(k2-1);
	printf("%d ",max(n-low,0));
	if (k1>k2) swap(k1,k2),swap(a1,a2);
	int T1=min(n/k1,a1); a1-=k1; n-=T1*k1;
	printf("%d",T1+n/k2);
}