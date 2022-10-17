#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=(1<<20)+5;
int n,k,S=1<<20;
int b[maxn],ans[maxn],len0[maxn],len1[maxn];
inline int C(int a,int b){
	return (a&b)==b;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=n;i>=n-25&&i>=0;i--){
		for(int j=max(0,k-2);j<=i;j++)
			len0[i]^=C(i,j);
		len1[i]=len0[i];
		if(k-2>=0)
			len1[i]^=C(i,k-2);
	}
	for(int i=1;i<=n;i++){
		long long v=b[i];
		for(int j=i;j<=n;j++){
			if(j>i){
				if(b[j]>30||v>=(S>>b[j]))
					break;
				v<<=b[j];
			}
			if(i==1&&j==n&&k==0)
				ans[v]^=1;
			if((i==1)+(j==n)==1&&len1[max(0,i-2)+max(0,n-j-1)])
				ans[v]^=1;
			if(i>1&&j<n&&len0[i-2+n-j-1])
				ans[v]^=1;
		}
	}
	int flg=0;
	for(int i=(1<<20)-1;i>=0;i--){
		if(ans[i])
			flg=1;
		if(flg)
			printf("%d",ans[i]);
	}
	if(flg==0)
		putchar('0');
	puts("");
	return 0;
}