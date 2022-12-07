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
const int N=1000005;
int n,m,S,a[N],sp[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m) scanf("%d",&a[i]),S+=a[i];
	a[m+1]=1<<30;
	For(i,2,m) sp[i]=(sp[i-1]+a[i-1])%n;
	sort(sp+1,sp+m+1); sp[m+1]=n;
	Rep(i,m+1,1) sp[i]-=sp[i-1];
	For(i,1,m) sp[i]=sp[i+1];
	int pos=1;
	printf("%d\n",(S-1)/n+1);
	For(i,1,m) printf("%d ",sp[i]); puts("");
	For(i,1,(S-1)/n+1){
		For(j,1,m){
			for (;!a[pos]&&pos<m;++pos);
			a[pos]-=sp[j];
			printf("%d ",pos);
		}
		puts("");
	}
}