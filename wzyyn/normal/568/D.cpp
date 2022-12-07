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
const int N=100005;
int n,k,id[N],px[15],py[15];
int A[N],B[N],C[N];

int rnd(){
	int x=0;
	For(i,1,9)
		x=x*10+rand()%10;
	return x;
}
bool check(int a,int b,int c){
	if (!A[a]) swap(a,b);
	if (!A[a]) swap(a,c);
	//cout<<a<<' '<<b<<' '<<c<<endl;
	ll v1=1ll*A[a]*B[b]-1ll*A[b]*B[a];
	ll v2=1ll*A[a]*C[b]-1ll*A[b]*C[a];
	ll v3=1ll*A[a]*B[c]-1ll*A[c]*B[a];
	ll v4=1ll*A[a]*C[c]-1ll*A[c]*C[a];
	return 1ll*v4*v1==1ll*v2*v3;
}
/*
A1x+B1y+C1=0
A2x+B2y+C2=0
A3x+B3y+C3=0
*/
void HEIHEIHEI(){
	int top=n;
	For(i,1,top) id[i]=i;
	int rem=k;
	for (int j=1;j<=80&&rem&&rem<top;++j){
		int a=id[rnd()%top+1];
		int b=id[rnd()%top+1];
		if (1ll*A[a]*B[b]==1ll*B[a]*A[b]) continue;
		int tmp=0,sum=0;
		For(j,1,top)
			if (check(a,b,id[j])) ++sum;
		if (sum*rem<top) continue;
		px[rem]=a; py[rem]=b;
		For(j,1,top)
			if (!check(a,b,id[j]))
				id[++tmp]=id[j];
		top=tmp; --rem;
	}
	if (rem>=top){
		puts("YES");
		printf("%d\n",top+k-rem);
		For(j,1,top) printf("%d -1\n",id[j]);
		For(j,rem+1,k) printf("%d %d\n",px[j],py[j]);
		exit(0);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d%d%d",&A[i],&B[i],&C[i]);
	For(T,1,10) HEIHEIHEI();
	puts("NO");
}