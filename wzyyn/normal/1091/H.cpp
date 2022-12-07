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
const int N=200005;
int n,Ban,ans;
int S1[N],S2[N],sg[N];
bitset<N> P,B[233];
int main(){
	scanf("%d%d",&n,&Ban);
	For(i,2,N-1) if (!S1[i]) For(j,1,(N-1)/i) ++S1[i*j];
	For(i,2,N-1) if (S1[i]==1) For(j,1,(N-1)/i) ++S2[i*j];
	For(i,2,N-1) P[i]=(S2[i]<=2&&i!=Ban);
	For(i,0,N-1){
		for (;B[sg[i]][i];++sg[i]);
		B[sg[i]]|=P<<i;
	}
	For(i,1,n){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ans^=sg[y-x-1]^sg[z-y-1];
	}
	puts(ans?"Alice":"Bob");
	puts(ans?"Bob":"Alice");
}