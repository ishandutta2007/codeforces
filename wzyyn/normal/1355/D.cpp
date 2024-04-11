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
int n,S,a[1000005];
int main(){
	scanf("%d%d",&n,&S);
	int p=(n+1)/2; a[p]=S-n+1;
	For(i,1,n) if (i!=p) a[i]=1;
	if (a[p]>S-a[p]+1){
		printf("YES\n");
		For(i,1,n) printf("%d ",a[i]);
		printf("\n%d",a[p]-1);
	} 
	else puts("NO");
}