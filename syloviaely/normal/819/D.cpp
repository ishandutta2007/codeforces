#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int aa[210000],T,n,step;
long long pre[210000],L;
map<int,int>M;
vector<int>A[2100000];
int B[210000],C[210000];
int len=0,ans[210000],t[210000],fir[210000],c[210000];
long long a,b;
long long exgcd(long long k1,long long k2)
{
	if (k2==0) {a=1; b=0; return k1;}
	long long k3=exgcd(k2,k1%k2),k4=a;
	a=b; b=k4-(k1/k2)*b; return k3;
}
int compare(int k1,int k2){
	return fir[k1]<fir[k2];
}
void solve(vector<int>&A){
	int n=0;
	M.clear(); 
	for (int i=0;i<A.size();i++){
		int k=pre[A[i]]%T;
		if (M[k]) continue;
		n++; B[n]=A[i],C[n]=pre[A[i]]%T; M[k]=1;
	}
	for (int i=1;i<=n;i++){
		long long d=exgcd(step,T);
		int c=C[i]-C[1];
		long long inc=T/d;
		a%=inc;
		while (a>=0) a-=inc;
		while (a<0) a+=inc;
		a*=c/d; a%=inc;
		while (a>=0) a-=inc;
		while (a<0) a+=inc;
		fir[i]=a;
	}
//	cout<<"solve"<<endl;
//	for (int i=1;i<=n;i++) cout<<B[i]<<" "<<C[i]<<" "<<fir[i]<<endl;
	for (int i=1;i<=n;i++) c[i]=i;
	sort(c+1,c+n+1,compare);
	c[n+1]=0; fir[0]=T/__gcd(L,(long long)T);
	for (int i=1;i<=n;i++) ans[B[c[i]]]=fir[c[i+1]]-fir[c[i]];
}
int main(){
	scanf("%d%d",&T,&n);
	for (int i=1;i<=n;i++) scanf("%d",&aa[i]); aa[n+1]=aa[1];
	for (int i=1;i<=n;i++) pre[i+1]=pre[i]+aa[i+1];
	L=pre[n+1];
	int w=__gcd(L,(long long)T);
	step=L%T;
	for (int i=1;i<=n;i++){
		int where=pre[i]%w;
		if (M[where]==0){
			M[where]=++len; 
		}
		where=M[where];
		A[where].push_back(i);
	}
	for (int i=1;i<=len;i++) solve(A[i]);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]); printf("\n");
}