#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int n1,n2,n3,m1,m2,m3,s1,s2,s3;
map<int,int>M;
int w[110000][3],len,f[110000];
long long ans[110000][110];
void add(int k1,int k2,int k3){
	int where=M[k1];// cout<<"add "<<k1<<" "<<k2<<" "<<k3<<endl;
	if (where==0) M[k1]=++len,where=len,w[len][0]=w[len][1]=w[len][2]=0,f[len]=k1;
	w[where][k3]+=k2;
}
void insert(int k1,int k2){
	for (int i=2;i*i<=k1;i++)
		if (k1%i==0){
			int num=0;
			while (k1%i==0) num++,k1/=i;
			add(i,num,k2);
		}
	if (k1>1) add(k1,1,k2);
}
long long pre[1100000];
long long an,m,n,s;
void calc(int k){
	for (int i=0;i<=w[k][0];i++){
		ans[k][i]=0;
		for (int j=0;j<=min(i,w[k][2]);j++)
			if (i-j==0) ans[k][i]++; else if (i-j==1) ans[k][i]--;
	}
}
void calc(int k1,long long k2,int k3){
	if (k3==0) return;
	if (k1>len){
		an+=(m/k2)*k3; return;
	}
	for (int i=0;i<=w[k1][0];i++){
		calc(k1+1,k2,k3*ans[k1][i]);
		if (i!=w[k1][0]) k2*=f[k1];
	}
}
void calc2(int k1,long long k2){
	if (k2>n) return;
	if (k1>len){
		an++; return;
	}
	for (int i=0;i<=w[k1][2];i++){
		calc2(k1+1,k2);
		if (i!=w[k1][2]) k2*=f[k1];
	}
}
void solve(){
	scanf("%d%d%d",&n1,&n2,&n3); len=0; an=0;
	scanf("%d%d%d",&m1,&m2,&m3); m=1ll*m1*m2*m3;
	scanf("%d%d%d",&s1,&s2,&s3); n=1ll*n1*n2*n3;
	M.clear(); s1*=2; s=1ll*s1*s2*s3;
	insert(n1,0); insert(n2,0); insert(n3,0);
	insert(m1,1); insert(m2,1); insert(m3,1);
	insert(s1,2); insert(s2,2); insert(s3,2);
	for (int i=1;i<=len;i++) calc(i);
	calc(1,1,1); //cout<<an<<endl;
//	int ww=0;
//	for (int i=1;i<=m;i++) if (s%__gcd((int)n,i)==0) ww++;
//	cout<<ww<<endl;
	//for (int i=1;i<=len;i++) cout<<f[i]<<" "<<w[i][0]<<" "<<w[i][1]<<" "<<w[i][2]<<endl; 
	calc2(1,1);
	printf("%I64d\n",an);
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}