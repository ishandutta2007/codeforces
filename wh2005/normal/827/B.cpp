#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
#define ll long long
int n,k,f[200009];
int judge(int len){
	if(len==2) return 0;
	if(len==3) return k==(n-1)?1:0;
	if((long long)(k-2)*((len-1)/2-1)<n-len-k+2) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&k);
	int l=2,r=n-k+2,len=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(judge(mid)) r=mid-1,len=mid;
		else l=mid+1;
	}
	printf("%d\n",len-1);
	for(int i=1;i<len;i++) printf("%d %d\n",i,i+1);
	int lf=k-2,ilf=n-len-k+2,t=len+1;
	for(int i=1;i<=lf;i++){
		printf("%d %d\n",(len+1)/2,t);f[i]=t,t++;
	}
	int x=1;
	while(ilf>0){
		printf("%d %d\n",f[x],t);f[x]=t;t++;
		x=x%lf+1;
		ilf--;
	}
	return 0;
}