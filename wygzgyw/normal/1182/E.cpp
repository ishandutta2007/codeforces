#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const ll m=(1e9)+6;
ll n,a,b,c,d;
struct Matrix {
	int x,y; ll d[6][6];
	void init(int a) {
		x=y=a;
		for (int i=1;i<=a;i++)
		for (int j=1;j<=a;j++)
			if (i==j) d[i][j]=1;
			else d[i][j]=0;
	}
	Matrix operator * (Matrix t) {
		Matrix res;
		res.x=x; res.y=t.y;
		for (int i=1;i<=x;i++)
		for (int j=1;j<=t.y;j++) {
			res.d[i][j]=0;
			for (int k=1;k<=y;k++)
				res.d[i][j]=(res.d[i][j]+d[i][k]*t.d[k][j]%m)%m;
		}
		return res;
	}
} A,B,C;
ll ksm(ll x,ll y) {
	ll res=1; x%=mod;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
Matrix cheng(Matrix x,ll y) {
	Matrix res; res.init(x.x);
	while (y) {
		if (y&1) res=res*x;
		x=x*x; y>>=1;
	}
	/*
	for (int i=1;i<=3;i++) {
		for (int j=1;j<=3;j++)
			printf("%lld ",res.d[i][j]);
		printf("\n");
	}*/
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(a); read(b); read(c); read(d);
	A.x=1; A.y=3; A.d[1][1]=1;
	B.x=B.y=3;
	B.d[2][1]=1;
	B.d[3][2]=1;
	B.d[1][3]=B.d[2][3]=B.d[3][3]=1;
	ll x,y,z,w;
	C=A*cheng(B,n-3);
	x=C.d[1][3];
	A.d[1][1]=0; A.d[1][2]=1;
	C=A*cheng(B,n-3);
	y=C.d[1][3];
	A.d[1][2]=0; A.d[1][3]=1;
	C=A*cheng(B,n-3);
	z=C.d[1][3];
	A.x=1; A.y=5; A.d[1][1]=A.d[1][2]=0;
	A.d[1][3]=0; A.d[1][4]=0; A.d[1][5]=1;
	B.x=B.y=5; memset(B.d,0,sizeof(B.d));
	B.d[2][1]=B.d[3][2]=1;
	B.d[1][3]=B.d[2][3]=B.d[3][3]=B.d[4][3]=1;
	B.d[5][3]=B.d[5][4]=2;
	B.d[4][4]=B.d[5][5]=1;
	C=A*cheng(B,n-3);
	w=C.d[1][3];
	//printf("%lld %lld %lld %lld\n",x,y,z,w);
	printf("%lld\n",ksm(a,x)*ksm(b,y)%mod*ksm(c,z)%mod*ksm(d,w)%mod);
	return 0;
}