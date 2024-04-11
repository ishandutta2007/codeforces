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
const int N=1005;
char s[N*N],ans[N][N];
int n,l,k,ed[N];
int main(){
	scanf("%d%d%d",&n,&l,&k);
	scanf("%s",s+1);
	sort(s+1,s+n*l+1);
	int L=1,p1=1,p2=k;
	For(i,1,l){
		For(j,p1,p2) ans[j][i]=s[L++],ed[j]=i;
		for (;ans[p1][i]!=ans[p2][i];++p1);
	}
	For(i,1,n) for (;ed[i]<l;++ed[i]) ans[i][ed[i]+1]=s[L++];
	For(i,1,n) printf("%s\n",ans[i]+1);
}