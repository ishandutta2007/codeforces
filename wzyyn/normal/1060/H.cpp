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
int d,p,nd,a[20];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%p)
		if (y&1) s=1ll*s*x%p;
	return s;
}
void Add(int x,int y,int z){
	printf("+ %d %d %d\n",x,y,z);
	a[z]=(a[x]+a[y])%p;
}
void Pow(int x,int y){
	printf("^ %d %d\n",x,y);
	a[y]=power(a[x],d);
}
void Multiply(int x,int v,int z){
	int y=4;
	Add(x,x,y); Add(x,x,z);
	for (v-=2;v<0||v&1;v+=p);
	for (v>>=1;v;){
		if (v&1) Add(z,y,z);
		if (v/=2) Add(y,y,y);
	}
}
int Sqr(int x){
	static int a[12][12];
	static int c[12][12];
	memset(a,0,sizeof(a));
	For(i,0,d) c[i][0]=1;
	For(i,1,d) For(j,1,i) c[i][j]=c[i-1][j]+c[i-1][j-1];
	For(i,0,d) For(j,0,d) a[i][j]=1ll*c[d][i]*power(j,d-i)%p;
	a[2][d+1]=1;
	For(i,0,d){
		int pp=-1; 
		For(j,i,d) if (a[j][i]) pp=j;
		For(j,i,d+1) swap(a[i][j],a[pp][j]);
		int v=power(a[i][i],p-2);
		For(j,i,d+1) a[i][j]=1ll*a[i][j]*v%p;
		For(j,0,d) if (j!=i)
			Rep(k,d+1,i) a[j][k]=(a[j][k]+p-1ll*a[i][k]*a[j][i])%p;
	}
	int ans=++nd;
	Pow(x,ans);
	Multiply(ans,a[0][d+1],ans);
	For(i,1,d){
		Add(x,5,x);
		Pow(x,6);
		Multiply(6,a[i][d+1],6);
		Add(ans,6,ans);
	}
	return ans;
}
int main(){
	scanf("%d%d",&d,&p);
	For(i,1,15) a[i]=1;
	nd=6; Add(1,2,3);
	int X=Sqr(1),Y=Sqr(2),Z=Sqr(3);
	Add(X,Y,X); Multiply(X,p-1,X);
	Add(Z,X,Z); Multiply(Z,(p+1)/2,Z);
	printf("f %d\n",Z);
}