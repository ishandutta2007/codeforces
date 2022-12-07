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
int a[105];
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		int n,d;
		scanf("%d%d",&n,&d);
		For(i,1,n) scanf("%d",&a[i]);
		For(i,1,d){
			int p=-1;
			Rep(j,n,2) if (a[j]) p=j;
			if (p==-1) break;
			a[p]--; a[p-1]++;
		}
		printf("%d\n",a[1]);
	}
}