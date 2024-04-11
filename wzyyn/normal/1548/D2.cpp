#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=6005;
int n,x[N],y[N];
int b[64],a[64][64];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void init(){
	for (int i=0;i<64;i++)
		for (int j=0;j<64;j++){
			int g1=i>>4,x1=(i>>2)&3,y1=i&3;
			int g2=j>>4,x2=(j>>2)&3,y2=j&3;
			if (x1*y2%2!=y1*x2%2) continue;
			if ((x1+x2)%2||(y1+y2)%2) continue;
			int ar=x1*y2-y1*x2+16,g3=(x1^x2)|(y1^y2);
			if ((g1+g2+g3)%4==ar%4) a[i][j]=(g1&1?3:1);
		}
}
int main(){
	init();
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	long long ans=0;
	for (int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for (int j=1;j<=n;j++) if (j!=i){
			int dx=((x[j]-x[i])%4+4)%4;
			int dy=((y[j]-y[i])%4+4)%4;
			int g=gcd(abs(x[j]-x[i]),abs(y[j]-y[i]))&3;
			++b[(g<<4)|(dx<<2)|dy];
		}
		for (int j=0;j<64;j++){
			ans+=1ll*b[j]*(b[j]-1)/2*a[j][j];
			for (int k=j+1;k<64;k++)
				ans+=1ll*b[j]*b[k]*a[j][k];
		}
	}
	printf("%lld\n",ans/3);
}