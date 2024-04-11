#include<bits/stdc++.h>
#define ll long long
#define N 6005

inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int n,x[N],y[N];

int f[N][4][4][4];

ll ans[2];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			int tmp=gcd(std::abs(x[i]-x[j]),std::abs(y[i]-y[j]))&3;
			f[i][tmp][x[j]&3][y[j]&3]++;
			f[j][tmp][x[i]&3][y[i]&3]++;
		}
	for(int i=1;i<=n;i++)
	for(int p=0;p<4;p++) for(int q=0;q<4;q++)
	for(int xa=0;xa<4;xa++) for(int ya=0;ya<4;ya++)
	for(int xb=0;xb<4;xb++) for(int yb=0;yb<4;yb++){
		int tmp=gcd(std::abs(xa-xb),std::abs(ya-yb));
		if(tmp&1)
			continue;
		tmp=(tmp+p+q)>>1;
		int s=xa*yb-xb*ya+xb*y[i]-x[i]*yb+x[i]*ya-xa*y[i];
		if(!(((s>>1)^tmp)&1))
			ans[p&1]+=1ll*f[i][p][xa][ya]*(f[i][q][xb][yb]-(p==q&&xa==xb&&ya==yb));
	}
	printf("%lld\n",ans[0]/6+ans[1]/2);
}