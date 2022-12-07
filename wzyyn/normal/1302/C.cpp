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
const int mo=998244353;
const int FFTN=(1<<18);
const int M=FFTN+5;
const int N=200005;
const int B=3000;
int n,m,Q;
char s1[N],s2[N];
int a[M],b[M];
int W[M],w[M],R[M];
ull p[M];
short res[105][N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFTinit(){
	W[0]=1;
	W[1]=power(3,(mo-1)/FFTN);
	For(i,2,M-1) W[i]=1ll*W[i-1]*W[1]%mo;
	//cout<<W[FFTN/2]<<endl;
}
int FFTinit(int n){
	int L=1;
	for (;L<=n;L<<=1);
	For(i,0,L-1) R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
	return L;
}
void DFT(int *a,int n){
	For(i,0,n-1) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=0;i<d;i++,j+=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
		if (d==1<<9)
			For(i,0,n-1) p[i]%=mo;
	}
	For(i,0,n-1) a[i]=p[i]%mo;
}
void IDFT(int *a,int n){
	For(i,0,n-1) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=FFTN;i<d;i++,j-=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
		if (d==1<<9)
			For(i,0,n-1) p[i]%=mo;
	}
	int v=power(n,mo-2);
	For(i,0,n-1) a[i]=p[i]*v%mo;
}
void UPD(int &l,int &x,int &y,int &ans){
	for (;l>=8;l-=8,x+=8,y+=8){
		ans+=(s1[x+0]!=s2[y+0]);
		ans+=(s1[x+1]!=s2[y+1]);
		ans+=(s1[x+2]!=s2[y+2]);
		ans+=(s1[x+3]!=s2[y+3]);
		ans+=(s1[x+4]!=s2[y+4]);
		ans+=(s1[x+5]!=s2[y+5]);
		ans+=(s1[x+6]!=s2[y+6]);
		ans+=(s1[x+7]!=s2[y+7]);
	}
	for (;l;--l,++x,++y)
		ans+=(s1[x]!=s2[y]);
}
int main(){
	//freopen("1.in","r",stdin);
	FFTinit();
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	int L=FFTinit(m+B+2);
	For(i,0,L-1) b[i]=0;
	For(i,1,m) b[i]=(s2[i]=='1'?1:mo-1);
	DFT(b,L);
	for (int i=1;i+B-1<=n;i+=B){
		For(j,0,L-1) a[j]=0;
		For(j,1,B) a[B-j+1]=(s1[i+j-1]=='1'?1:mo-1);
		DFT(a,L);
		For(j,0,L-1) a[j]=1ll*a[j]*b[j]%mo;
		IDFT(a,L);
		int id=(i-1)/B+1,v;
		For(j,1,m){
			v=a[j+B];
			if (v>10000) v-=mo;
			//cout<<i<<' '<<j<<' '<<v<<endl;
			res[id][j]=(B-v)/2;
		}
	}
	scanf("%d",&Q);
	int sum=0;
	//scanf("%d",&Q);
	while (Q--){
		int x,y,l,ans=0;
		scanf("%d%d%d",&x,&y,&l);
		++x; ++y;
		//cout<<x<<' '<<y<<endl;
		//x=rand()%100+1; y=rand()%100+1; l=199000;
		if (l<=2*B) UPD(l,x,y,ans);
		else{
			int be=(x-1)/B+1,tmp=be*B+1-x;
			l-=tmp; UPD(tmp,x,y,ans); be++;
			//cout<<ans<<' '<<x<<' '<<y<<' '<<l<<' '<<be<<endl;
			for (;l>=B;l-=B,x+=B,y+=B,be++) ans+=res[be][y]; 
			UPD(l,x,y,ans);
		}
		sum+=ans;
		printf("%d\n",ans);
	}
}