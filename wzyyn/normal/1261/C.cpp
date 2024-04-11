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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
const int N=10000005;
#define ID(i,j) ((i)*(m+2)+(j))
char s[N];
int SS[N],n,m,T;
int SSS[N],SSSS[N];
bool check(int v){
	++T;
	memset(SSS,0,sizeof(SSS));
	For(i,1+v,n-v) For(j,1+v,m-v){
		int sum=SS[ID(i+v,j+v)]-SS[ID(i-v-1,j+v)]-SS[ID(i+v,j-v-1)]+SS[ID(i-v-1,j-v-1)];
		if (sum!=(2*v+1)*(2*v+1)) continue;
		SSSS[ID(i,j)]=T;
		++SSS[ID(i-v,j-v)]; ++SSS[ID(i+v+1,j+v+1)];
		--SSS[ID(i-v,j+v+1)]; --SSS[ID(i+v+1,j-v)];
	}
	For(i,1,n) For(j,1,m) SSS[ID(i,j)]+=SSS[ID(i,j-1)];
	For(i,1,n) For(j,1,m) SSS[ID(i,j)]+=SSS[ID(i-1,j)];
	For(i,1,n) For(j,1,m)
		if ((s[ID(i,j)]=='X')^(SSS[ID(i,j)]!=0))
			return 0;
	return 1;	
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s+(ID(i,1)));
	For(i,1,n) For(j,1,m) SS[ID(i,j)]=(s[ID(i,j)]=='X');
	For(i,1,n) For(j,1,m) SS[ID(i,j)]+=SS[ID(i,j-1)];
	For(i,1,n) For(j,1,m) SS[ID(i,j)]+=SS[ID(i-1,j)];
	int l=0,r=min(n,m)/2,ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	check(ans);
	printf("%d\n",ans);
	For(i,1,n){
		For(j,1,m) putchar(SSSS[ID(i,j)]==T?'X':'.');
		puts("");
	}
}