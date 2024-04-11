#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=1005;
int m,k;
ll a[N][N],S[N];
ll S2[N];
int main(){
	scanf("%d%d",&m,&k);
	for (int i=1;i<=k;i++)
		for (int j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
			S[i]+=a[i][j];
			S2[i]+=1ll*a[i][j]*a[i][j];
		}
	ll Sv=(S[k]-S[1])/(k-1),p=0;
	for (int i=1;i+2<=k;i++)
		if (S[i+1]-S[i]==Sv&&S[i+2]-S[i+1]==Sv)
			p=i+1;
	ll Sv2=(S2[p-1]+S2[p+1]-2*S2[p]);
	for (int i=2;i<=k-1;i++)
		if (S[i]-S[i-1]!=Sv)
			if (S[i+1]-S[i]!=Sv){
				for (int j=1;j<=m;j++){
					ll v=S[i+1]-Sv-(S[i]-a[i][j]);
					ll nS2=S2[i]-1ll*a[i][j]*a[i][j]+1ll*v*v;
					if (S2[i+1]+S2[i-1]==2*nS2+Sv2){
						printf("%d %lld\n",i-1,v);
						return 0;
					}
				}
			}
}