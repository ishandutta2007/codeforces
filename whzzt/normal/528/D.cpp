#include"algorithm"
#include"iostream"
#include"string.h"
#include"stdlib.h"
#include"stdio.h"
#include"math.h"
#include"vector"
#include"time.h"
#include"queue"
#include"map"
#include"set"

using namespace std;
typedef long long LL;

const int N=1050005,P=1004535809,M=500005;

int power(int a,int t){
	int r=1;
	while(t){
		if(t&1)r=(LL)r*a%P;
		a=(LL)a*a%P;t>>=1;
	}
	return r;
}

int wt[N],len;
void gtw(int le){
	int ml=power(3,(P-1)/le);
	wt[0]=1;len=le;
	for(int i=1;i<len;i++)wt[i]=(LL)wt[i-1]*ml%P;
}

int _wn[25];
void ntt(int*a,int dft){
	int i,j=len>>1,k,l,u,v,step,x,inv;
	for(i=1;i<len-1;i++){
		if(i>j)swap(a[i],a[j]);
		for(k=len>>1;(j^=k)<k;k>>=1);
	}
	for(l=2;l<=len;l<<=1){
		for(step=len/l,i=l>>1,j=0;j<len;j+=l){
			for(x=0,k=j;k<j+i;k++,x+=step){
				u=a[k],v=(LL)a[k+i]*wt[x]%P;
				(a[k]=u+v)<P?:a[k]-=P;
				(a[k+i]=u-v)>=0?:a[k+i]+=P;
			}
		}
	}
	if(dft==-1){
		inv=power(len,P-2);
		for(i=1;i<len/2;i++)swap(a[i],a[len-i]);
		for(i=0;i<len;i++)a[i]=(LL)a[i]*inv%P;
	}
}

int gl(int n){
	int l;
	for(l=1;l<=2*n;l<<=1);
	return l;
}

int trans(char c){
	switch(c){
		case'T':return 0;
		case'A':return 1;
		case'G':return 2;
		default:return 3;
	}
}

int n,m,k,val[4][N],cnt[N],x[N],num[7][N],dat[N],xt[N],L,pre[M][4],suf[M][4],sum[N],ans;
char S[N],T[N];
bool ok[N];

int main(){
	scanf("%d%d%d%s%s",&n,&m,&k,S+1,T+1);
	for(int i=1;i<=n;i++){
		memcpy(pre[i],pre[i-1],16);
		pre[i][trans(S[i])]=i;
	}
	suf[n+1][0]=suf[n+1][1]=suf[n+1][2]=suf[n+1][3]=n+1;
	
	for(int i=n;i>=1;i--){
		memcpy(suf[i],suf[i+1],16);
		suf[i][trans(S[i])]=i;
	}
	
	for(int i=1;i<=n;i++){
		val[0][i]=val[1][i]=val[2][i]=val[3][i]=trans(S[i]);
		int l=i-k,r=i+k;
		for(int c=0;c<4;c++)
			if(pre[i][c]>=max(l,1)||suf[i][c]<=min(r,n))
				val[cnt[i]++][i]=c;
	}
	for(int i=0;i<m;i++)x[i]=trans(T[m-i]),xt[i]=1;
	
	for(int j=1;j<=n;j++){
		if(cnt[j]<4){
			int aj=val[0][j],bj=val[1][j],cj=val[2][j],aj2=aj*aj,bj2=bj*bj,cj2=cj*cj;
			num[0][j]=aj2*bj2*cj2;
			num[1][j]=-2*aj2*bj2*cj-2*aj2*bj*cj2-2*aj*bj2*cj2;
			num[2][j]=aj2*bj2+aj2*cj2+bj2*cj2+4*aj2*bj*cj+4*aj*bj2*cj+4*aj*bj*cj2;
			num[3][j]=-2*aj2*bj-2*aj2*cj-2*bj2*aj-2*bj2*cj-2*cj2*aj-2*cj2*bj-8*aj*bj*cj;
			num[4][j]=aj2+bj2+cj2+4*aj*bj+4*bj*cj+4*aj*cj;
			num[5][j]=-2*aj-2*bj-2*cj;
			num[6][j]=1;
		}else{
			num[0][j]=0;
			num[1][j]=0;
			num[2][j]=0;
			num[3][j]=0;
			num[4][j]=0;
			num[5][j]=0;
			num[6][j]=0;
		}
	}
	
	L=gl(n);
	gtw(L);
	for(int y=0;y<7;y++){
		memset(dat,0,L<<2);
		for(int i=0;i<m;i++)dat[i]=xt[i],xt[i]=(LL)xt[i]*x[i]%P;
		ntt(dat,1);
		ntt(num[y],1);
		for(int i=0;i<L;i++)sum[i]=(sum[i]+(LL)num[y][i]*dat[i])%P;
	}
	ntt(sum,-1);
	
	for(int p=m;p<=n;p++)
		ans+=sum[p]==0;
	printf("%d\n",ans);
	return 0;
}