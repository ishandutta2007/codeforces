#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int A[110000],n,K;
char ch[110000];
int main(){
	scanf("%d%d",&n,&K);
	scanf("%s",ch+1);
	for (int i=1;i<=n;i++) A[i]=-ch[i]+'1'+A[i-1];
	int num=n+1;
	for (int i=1;i<=n;i++){
		if (ch[i]=='1') continue;
		int l=0,r=n+1,ans=n;
		while (l<r){
			int mid=l+r>>1;
			int L=max(1,i-mid),R=min(n,i+mid);
			if (A[R]-A[L-1]>=K+1){
				ans=mid; r=mid;
			} else l=mid+1;
		}
		num=min(num,ans);
	}
	cout<<num<<endl;
	return 0;
}