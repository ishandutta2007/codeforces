#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int FFTN=1<<17;
const int N=1<<17|5;
const int mo=998244353;

int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int W[N],w[N],R[N];
int A[16][N];
void FFTinit(){
	W[0]=1;
	W[1]=power(3,(mo-1)/FFTN);
	for (int i=2;i<N;i++) W[i]=1ll*W[i-1]*W[1]%mo;
}
int FFTinit(int n){
	int L=1;
	for (;L<=n;L<<=1);
	for (int i=0;i<L;i++) R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
	return L;
}
ull p[N];
void DFT(int *a,int n){
	for (int i=0;i<n;i++) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=0;i<d;i++,j+=len) w[i]=W[j];
		for (int i=0;i<n;i+=d<<1)
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	for (int i=0;i<n;i++)
		a[i]=p[i]%mo;
}
void IDFT(int *a,int n){
	for (int i=0;i<n;i++) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=FFTN;i<d;i++,j-=len) w[i]=W[j];
		for (int i=0;i<n;i+=d<<1)
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	int inv=power(n,mo-2);
	for (int i=0;i<n;i++)
		a[i]=p[i]*inv%mo;
}
int a[N],q[N],n;
struct node{
	vector<int> a[2][2];
	node(){}
	node(int l){
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				a[i][j].resize(l);
	}
};
node divide(int l,int r){
	node ans(r-l+1);
	if (r-l+1==2){
		ans.a[q[l]==1][q[r]==1][1]++;
		ans.a[0][0][0]++;
		return ans;
	}
	if (r-l+1==3){
		ans.a[q[l]==1][q[r]==1][2]+=(q[l+1]==1?1:2);
		ans.a[0][q[r]==1][1]++;
		ans.a[q[l]==1][0][1]++;
		ans.a[0][0][0]++;
		return ans;
	}
	int mid=(l+r)/2;
	node ansl=divide(l,mid);
	node ansr=divide(mid+1,r);
	int L=FFTinit(r-l+1);
	for (int i=0;i<16;i++)
		for (int j=0;j<L;j++) A[i][j]=0;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++){
			int i1=i*2+j,i2=i*2+j+4;
			for (int p=1;p<mid-l+1;p++) A[i1][p]=ansl.a[i][j][p];
			for (int p=1;p<r-mid;p++) 	A[i2][p]=ansr.a[i][j][p];
		}
	for (int i=0;i<8;i++)
		DFT(A[i],L);
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int k=0;k<2;k++)
				for (int m=0;m<2;m++){
					int i1=i*2+j,i2=k*2+m+4;
					int i3=i*2+m+8,i4=i*2+m+12;
					for (int p=0;p<L;p++) A[i3][p]=(A[i3][p]+1ll*A[i1][p]*A[i2][p]*(j?1:2)*(k?1:2))%mo;
					for (int p=0;p<L;p++) A[i4][p]=(A[i4][p]+2ll*A[i1][p]*A[i2][p])%mo;
					for (int p=1;p<mid-l+1;p++){
						ans.a[i][m][p+1]=(ans.a[i][m][p+1]+1ll*ansl.a[i][j][p]*ansr.a[k][m][0]*(j?1:2))%mo;
						ans.a[i][m][p]=(ans.a[i][m][p]+1ll*ansl.a[i][j][p]*ansr.a[k][m][0])%mo;
					}
					for (int p=1;p<r-mid;p++){
						ans.a[i][m][p+1]=(ans.a[i][m][p+1]+1ll*ansl.a[i][j][0]*ansr.a[k][m][p]*(k?1:2))%mo;
						ans.a[i][m][p]=(ans.a[i][m][p]+1ll*ansl.a[i][j][0]*ansr.a[k][m][p])%mo;	
					}
					ans.a[i][m][1]=(ans.a[i][m][1]+1ll*ansl.a[i][j][0]*ansr.a[k][m][0])%mo;
					ans.a[i][m][0]=(ans.a[i][m][0]+1ll*ansl.a[i][j][0]*ansr.a[k][m][0])%mo;
					
				}
	for (int i=8;i<16;i++)
		IDFT(A[i],L);
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++){
			int i1=i*2+j+8,i2=i*2+j+12;
			for (int p=1;p<r-l+1;p++) ans.a[i][j][p]=(ans.a[i][j][p]+A[i1][p-1])%mo;
			for (int p=0;p<r-l+1;p++) ans.a[i][j][p]=(ans.a[i][j][p]+A[i2][p  ])%mo;
		}
	return ans;
}
int main(){
	FFTinit();
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;){
		if (i+a[i]-1>n) return puts("0"),0;
		for (int j=i;j<i+a[i];j++)
			if (a[j]!=a[i]) return puts("0"),0;
		q[++*q]=a[i]; i+=a[i];
	}
	if (*q==1){
		printf("%d\n",n==1?1:2);
		return 0;
	}
	node ans=divide(1,*q);
	int tr=1,res=0;
	for (int p=0;p<*q;p++){
		int v;
		if (p==0) v=(2ll*ans.a[0][0][p]+1ll*ans.a[1][1][p])%mo;
		else v=(4ll*ans.a[0][0][p]+2ll*ans.a[0][1][p]+2ll*ans.a[1][0][p]+ans.a[1][1][p])%mo;
		//cout<<p+1<<' '<<v<<endl;
		tr=1ll*tr*(p+1)%mo;
		if (((*q)-(p+1))&1) res=(res+mo-1ll*tr*v%mo)%mo;
		else res=(res+1ll*tr*v)%mo;
	}
	cout<<res<<endl;
}