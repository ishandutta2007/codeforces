#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int M1=550;
const int M2=55;
char s[M2+5];
int l;
int f[M1*2+5][M2*2+5];
int g[M1*2+5][M2*2+5];
int main(){
	scanf("%s",s+1);
	l=strlen(s+1);
	reverse(s+1,s+l+1);
	For(i,1,l) s[i]=s[i]-'0';
	memset(f,30,sizeof(f));
	For(i,-M1,M1) f[i+M1][M2]=0;
	For(i,1,55){
		memset(g,30,sizeof(g));
		For(j,-M1,M1) For(k,-M2,M2)
			if ((j+k-s[i])%10==0)
				if (f[j+M1][k+M2]<=1000000){
					int nj=j,nk=(j+k-s[i])/10;
					if (nk>=-M2&&nk<=M2) g[nj+M1][nk+M2]=min(g[nj+M1][nk+M2],f[j+M1][k+M2]);
				}
		memcpy(f,g,sizeof(f));
		For(k,-M2,M2){
			For(j,-M1+1,M1)	f[j+M1][k+M2]=min(f[j+M1][k+M2],f[j+M1-1][k+M2]+i);
			Rep(j,M1-1,-M1)	f[j+M1][k+M2]=min(f[j+M1][k+M2],f[j+M1+1][k+M2]+i);
		}
	}
	cout<<f[M1][M2]<<endl;
}
/*
50
1000
100 
 
*/