#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int pr=3;
const int MAXP=1<<16;
const int MOD=998244353;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,k,A[MAXP+5],B[MAXP+5];
int LEN=1,LOG=0,inv[MAXP+5],rev[MAXP+5],prs[MAXP+5][2],ipr;
void NTT(int *a,int len,int type){
	int lg=log2(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		int W=prs[i][type<0];
		for(int j=0;j<len;j+=i){
			int w=1;
			for(int k=0;k<(i>>1);k++,w=1ll*w*W%MOD){
				int X=a[j+k],Y=1ll*w*a[(i>>1)+j+k]%MOD;
				a[j+k]=(X+Y)%MOD;a[(i>>1)+j+k]=(X-Y+MOD)%MOD;
			}
		}
	}
	if(type==-1) for(int i=0;i<len;i++) a[i]=1ll*a[i]*inv[len]%MOD;
}
struct data{int a[3][MAXP+5];data(){memset(a,0,sizeof(a));}};
int tmp[6][MAXP+5];
void merge(data &a,data &b){
//	puts("-1");
	for(int i=0;i<LEN;i++) tmp[0][i]=a.a[0][i],tmp[1][i]=a.a[1][i],tmp[2][i]=a.a[2][i];
	for(int i=0;i<LEN;i++) tmp[3][i]=b.a[0][i],tmp[4][i]=b.a[1][i],tmp[5][i]=b.a[2][i];
	for(int i=0;i<6;i++) NTT(tmp[i],LEN,1);
	for(int i=0;i<LEN;i++){
		int t1=1ll*tmp[0][i]*tmp[3][i]%MOD;
		int t2=1ll*tmp[0][i]*tmp[4][i]%MOD;
		int t3=1ll*tmp[1][i]*tmp[4][i]%MOD;
		int t4=1ll*tmp[1][i]*tmp[5][i]%MOD;
		int t5=1ll*tmp[2][i]*tmp[5][i]%MOD;
		tmp[0][i]=t1;tmp[1][i]=t2;tmp[2][i]=t3;tmp[3][i]=t4;tmp[4][i]=t5;
	}
	for(int i=0;i<5;i++) NTT(tmp[i],LEN,-1);
//	polymul(a.a[0],b.a[0],tmp[0],LEN);polymul(a.a[0],b.a[1],tmp[1],LEN);
//	polymul(a.a[1],b.a[1],tmp[2],LEN);polymul(a.a[1],b.a[2],tmp[3],LEN);
//	polymul(a.a[2],b.a[2],tmp[4],LEN);
	for(int i=0;i<=k;i++){
		a.a[0][i]=(tmp[0][i]+tmp[2][i-1])%MOD;
		a.a[1][i]=(tmp[1][i]+tmp[3][i-1])%MOD;
		a.a[2][i]=(tmp[2][i]+tmp[4][i-1])%MOD;
	}
}
int main(){
//	freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&k);ipr=qpow(pr,MOD-2);
	while(LEN<=k+k) LEN<<=1,LOG++;
	for(int i=1;i<=LEN;i<<=1){
		inv[i]=qpow(i,MOD-2);
		prs[i][0]=qpow(pr,(MOD-1)/i);
		prs[i][1]=qpow(ipr,(MOD-1)/i);
	}
	data x,y;x.a[0][0]=1;y.a[0][0]=y.a[0][1]=y.a[1][0]=1;
	for(;n;n>>=1,merge(y,y)) if(n&1) merge(x,y);
	for(int i=1;i<=k;i++) printf("%d%c",x.a[0][i],(i==k)?'\n':' ');
	return 0;
}