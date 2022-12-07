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
const int N=2005;
int n,deg[N],Deg[N],S[N];
int e[N][N];
char s[N];
bool CHK(int *d){
	For(i,0,n-1) S[i]=0;
	For(i,1,n) ++S[d[i]];
	int s1=0,s2=0;
	Rep(i,n,0){
		s1+=i*S[i]; s2+=S[i];
		if (s1==s2*(s2-1)/2+(n-s2)*s2&&s2!=n&&s2!=0)
			return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,n) e[i][j]=(s[j]=='1');
		For(j,1,n) deg[i]+=e[i][j];
	}
	if (CHK(deg)) return puts("0 1"),0;
	int sum=0;
	For(i,1,n){
		memcpy(Deg,deg,sizeof(deg));
		For(j,1,n) if (j!=i)
			if (e[i][j]) --Deg[i],++Deg[j];
			else ++Deg[i],--Deg[j];
		if (CHK(Deg)) ++sum;
	}
	if (sum)
		return printf("1 %d\n",sum),0;
	int mn=1<<30;
	For(i,2,(1<<n)-1){
		memset(Deg,0,sizeof(Deg));
		For(j,1,n) For(k,1,n) if (j!=k)
			if (e[j][k]^((i>>(j-1))&1)^((i>>(k-1))&1))
				++Deg[j];
		if (CHK(Deg)){
			int s=0;
			For(j,1,n) s+=((i>>(j-1))&1);
			if (s<mn) mn=s,sum=0;
			if (s==mn) ++sum;
		}
	}
	if (mn==(1<<30)) puts("-1");
	else{
		For(i,1,mn) sum*=i;
		printf("%d %d\n",mn,sum);
	}
}