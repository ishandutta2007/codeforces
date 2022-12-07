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
int n,m;
char s[N][N];
int L[N],R[N],U[N],D[N];
ll ans;
void init(){
	For(i,1,n) for (L[i]=1;L[i]<=m&&s[i][L[i]]=='.';++L[i]);
	For(i,1,n) for (R[i]=m;R[i]>=1&&s[i][R[i]]=='.';--R[i]);
	For(i,1,m) for (U[i]=1;U[i]<=n&&s[U[i]][i]=='.';++U[i]);
	For(i,1,m) for (D[i]=n;D[i]>=1&&s[D[i]][i]=='.';--D[i]);
}
void solve1(){
	For(i,2,n-1) For(j,2,m-1)
		ans+=((L[i]>j)+(R[i]<j))*((U[j]>i)+(D[j]<i));
}
void solve2(){
	For(i,2,n-1) ans+=(L[i]>m);
	For(i,2,m-1) ans+=(U[i]>n);
	For(i,2,n-1){
		int S=0;
		For(j,2,m-1)
			if (s[i][j]=='#') S=0;
			else{
				int SS=(U[j]>i)+(D[j]<i);
				if (j>2&&U[j]>i&&U[j-1]>i) ans--;
				if (j>2&&D[j]<i&&D[j-1]<i) ans--;
				ans+=SS*S; S+=SS;
			}
	}
	For(i,2,m-1){
		int S=0;
		For(j,2,n-1)
			if (s[j][i]=='#') S=0;
			else{
				int SS=(L[j]>i)+(R[j]<i);
				if (j>2&&L[j]>i&&L[j-1]>i) ans--;
				if (j>2&&R[j]<i&&R[j-1]<i) ans--;
				ans+=SS*S; S+=SS;
			}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	init(); solve1(); solve2();
	printf("%lld\n",ans);
}