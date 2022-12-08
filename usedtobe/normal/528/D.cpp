#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define re(i,a,b) for (int i=a;i<b;++i)
using namespace std;
typedef complex<double> CD;
const int N=1048576;
const double pi=acos(-1);
int r[N];CD a[N],b[N];
void rev(CD *a,int m){
	r[0]=0;re(i,1,1<<m)r[i]=(r[i>>1]>>1)|((i&1)<<m-1);
	re(i,0,1<<m)if(r[i]>i)swap(a[r[i]],a[i]);
}
void dft(CD *a,int m,int inv=0) {
	rev(a,m);
	re(i,0,m){
		double the=pi/(1<<i)*(inv?-1:1);
		CD c=CD(cos(the),sin(the));
		for(int j=0;j<1<<m;j+=1<<i+1) {
			CD w=1;
			re(k,j,j+(1<<i)){
				CD u=a[k],v=a[k+(1<<i)];
				a[k]=u+w*v;a[k+(1<<i)]=u-w*v;
				w*=c;
			}
		}
	}
	if(inv)re(i,0,1<<m)a[i]/=1<<m;
}
void fft(CD *a,CD *b,int n){
	int M=0;for(;1<<M<n;M++);
	dft(a,M);dft(b,M);
	re(i,0,1<<M)a[i]=a[i]*b[i];
	dft(a,M,-1);
}
int n,m,K;CD tmp[N],tmp2[N];
bool ok[4][N];int pre[N];
char S[N],T[N];
void work(char c,int tt){
	memset(a,0,sizeof a);memset(pre,0,sizeof pre);
	re(i,0,n)if(S[i]==c){
		pre[max(0,i-K)]++;
		pre[min(N,i+K+1)]--;
	}
	memset(tmp,0,sizeof tmp);
	re(i,0,n){pre[i]+=pre[i-1];if(pre[i])tmp[i]=CD(1,0);}
	memset(tmp2,0,sizeof tmp2);
	int cs=0;
	re(i,0,m)if(T[i]==c)tmp2[m-i-1]=CD(1,0),++cs;
	fft(tmp,tmp2,n+m+1);
	re(i,m-1,n+m+5)if((int)(real(tmp[i])+0.5)>=cs&&(i-(m-1))<n)ok[tt][i-(m-1)]=1;
} 
int tot;
int main() {
	scanf("%d%d%d",&n,&m,&K);
	scanf("%s%s",S,T);
	work('A',0);
	work('C',1);
	work('G',2);
	work('T',3);
	re(i,0,n){
		bool f=1;
		rep(j,0,3)f&=ok[j][i];
		if (f)++tot;
	}
	cout<<tot<<endl;
	return 0;
}