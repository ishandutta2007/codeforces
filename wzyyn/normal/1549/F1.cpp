#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=6005;
int n,x[N],y[N];
int s[8][8],e[8][8][8][8];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		++s[x%8][y%8];
	}
	for (int i=0;i<=6;i+=2)
		for (int j=0;j<=6;j+=2)
			for (int k=0;k<=6;k+=2)
				for (int l=0;l<=6;l+=2){
					int rem=i*l-j*k;
					e[i][j][k][l]=(abs(rem)&4?1:0);
				}
	long long ans=0;
	for (int i=0;i<=6;i+=2)
		for (int j=0;j<=6;j+=2)
			if (!e[i][j][i][j]){
				ans+=1ll*s[i][j]*(s[i][j]-1)*(s[i][j]-2)/6;
				for (int k=0;k<=6;k+=2)
					for (int l=0;l<=6;l+=2)
						if (k!=i||l!=j)
							ans+=1ll*s[i][j]*(s[i][j]-1)/2*s[k][l];
			}
	//cout<<ans<<endl;
	for (int i=0;i<=6;i+=2)
		for (int j=0;j<=6;j+=2)
			for (int k=i;k<=6;k+=2)
				for (int l=(k==i?j+2:0);l<=6;l+=2)
					for (int p=k;p<=6;p+=2)	
						for (int q=(p==k?l+2:0);q<=6;q+=2)
							if (!(e[i][j][k][l]^e[i][j][p][q]^e[k][l][p][q])){
								ans+=1ll*s[i][j]*s[k][l]*s[p][q];
								//cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<p<<' '<<q<<' '<<ans<<endl;
							}
	cout<<ans<<endl;
}
/*
S = 4
B = 8
I = 1
*/