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
int n,m,k;
char s[100005];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int p=0;
	For(i,1,n-1) s[++p]='U';
	For(i,1,m-1) s[++p]='L';
	For(i,1,n){
		For(j,1,m-1) s[++p]=(i&1?'R':'L');
		if (i!=n) s[++p]='D';
	}
	printf("%d\n%s",p,s+1);
}