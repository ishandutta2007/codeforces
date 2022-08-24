#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const long double pi=acos(-1);
struct atom{
    long double x,y;
}A[600000],B[600000];
atom operator + (atom k1,atom k2){
    return (atom){k1.x+k2.x,k1.y+k2.y};
}
atom operator - (atom k1,atom k2){
    return (atom){k1.x-k2.x,k1.y-k2.y};
}
atom operator * (atom k1,atom k2){
    return (atom){k1.x*k2.x-k1.y*k2.y,k1.x*k2.y+k1.y*k2.x};
}
char getin(){
    char ch=getchar(); while (ch<'0'||ch>'9') ch=getchar(); return ch;
}
void fft(atom *x,int n,int fl=1){
    for (int i=(n>>1),j=1;j<n;j++){
        if (i<j) swap(x[i],x[j]);
        int k;
        for (k=(n>>1);i&k;i^=k,k>>=1); i^=k;
    }
    for (int m=2;m<=n;m=(m<<1)){
        atom w=(atom){cos(2*pi*fl/m),sin(2*pi*fl/m)};
        for (int i=0;i<n;i+=m){
            atom cur=(atom){1,0};
            for (int j=i;j<i+(m>>1);j++){
                atom u=x[j],v=x[j+(m>>1)]*cur;
                x[j]=u+v; x[j+(m>>1)]=u-v;
                cur=cur*w;
            }
        }
    }
}
char S[210000],T[210000];
int n,m,K,pd[210000];
void find(char ch){
	memset(A,0x00,sizeof A);
	memset(B,0x00,sizeof B);
	int now=0;
	for (int i=0;i<K;i++) now+=(S[i]==ch);
	for (int i=0;i<n;i++){
		if (i+K<n) now+=(S[i+K]==ch);
		if (now) A[i].x=1;
		if (i>=K) now-=(S[i-K]==ch);
	}
	now=0;
	for (int i=0;i<m;i++) if (T[i]==ch) {B[m-i-1].x=1; now++;}
	int len=1; while ((1<<len)<(n+m)) len++;
	fft(A,1<<len); fft(B,1<<len);
	for (int i=0;i<(1<<len);i++) A[i]=A[i]*B[i];
	fft(A,1<<len,-1);
    for (int i=0;i<n;i++){
		int k1=(int)(A[i+m-1].x/(1<<len)+0.5);
		if (k1!=now) pd[i]=0;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	scanf("%s",S); scanf("%s",T);
	for (int i=0;i<n;i++) pd[i]=1;
	find('A'); find('C'); find('G'); find('T');
	int ans=0;
	for (int i=0;i<n;i++) ans+=pd[i];
	printf("%d",ans);
}