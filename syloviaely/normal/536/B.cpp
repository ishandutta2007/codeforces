#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int A[1100000],n,m,x[1100000],next[1100000],mo=1e9+7,pd[1100000];
char ch[1100000];
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo; k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",ch+1);
	for (int i=1;i<=m;i++) scanf("%d",&x[i]);
	int len=strlen(ch+1);
	for (int i=2;i<=len;i++){
		int pre=next[i-1];
		while (ch[pre+1]!=ch[i]&&pre) pre=next[pre];
		if (ch[pre+1]==ch[i]) next[i]=pre+1; else next[i]=pre;
	}
//	for (int i=1;i<=len;i++) cout<<next[i]<<" "; cout<<endl;
	int pre=0,num=0;
	for (int i=len;i;i=next[i]) pd[i]=1;
//	for (int i=1;i<=len;i++) cout<<pd[i]<<" "; cout<<endl;
	for (int i=1;i<=m;i++) A[x[i]]=1;
	for (int i=1;i<=n;i++)
		if ((i>=pre+len||pre==0)&&A[i]==0) num++;
		else if (A[i]==1){
			if (pre==0||i>=pre+len){
				pre=i; continue;
			}
			int k1=pre+len-i;// cout<<pre<<" "<<i<<" "<<k1<<endl;
			if (pd[k1]==0){
				cout<<0<<endl; return 0;
			}
			pre=i;
		}
//	cout<<num<<endl;
	cout<<quick(26,num)<<endl; return 0;
}