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
const int moo=1000000000;
const int mo=1000000007;
const int N=300005;
int n,R[N],c[N];
int b[N],l,rem[N];
int f[2][N];
char s[N];
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
int DIV(int v){
	ll x=0;
	Rep(i,l,1){
		x=x*moo+b[i];
		b[i]=x/v;
		x%=v;
	}
	for (;l&&!b[l];--l);
	return x;
}
int main(){
	scanf("%d",&n);
	R[1]=1; R[n+1]=1e9;
	For(i,2,n) scanf("%d",&R[i]);
	For(i,1,n) scanf("%d",&c[i]);
	scanf("%s",s+1);
	l=strlen(s+1);
	reverse(s+1,s+l+1);
	Rep(i,l,1) b[(i-1)/9+1]=b[(i-1)/9+1]*10+s[i]-'0';
	l=(l-1)/9+1;
	For(i,1,n)
		if (R[i+1]==1) rem[i]=0;
		else rem[i]=DIV(R[i+1]);
	if (l!=0) return puts("0"),0;
	f[0][0]=1;
	int l=0,pr=0,su=1;
	For(i,1,n){
		For(j,0,l+c[i]) f[su][j]=0;
		For(j,0,l){
			UPD(f[su][j],f[pr][j]);
			UPD(f[su][j+c[i]+1],mo-f[pr][j]);
		}
		l+=c[i];
		For(j,1,l) UPD(f[su][j],f[su][j-1]);
		int nl=max(0,(l-rem[i])/R[i+1]);
		//cout<<"FDP "<<l<<' '<<rem[i]<<' '<<R[i+1]<<endl;
		For(j,0,nl)
			if (j*R[i+1]+rem[i]<=l)
				f[su][j]=f[su][j*R[i+1]+rem[i]];
			else f[su][j]=0;
		//For(j,0,nl) cout<<f[su][j]<<' '; cout<<endl;
		l=nl; swap(pr,su);
	}
	printf("%d\n",f[pr][0]);
}