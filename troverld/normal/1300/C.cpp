#include<bits/stdc++.h>
using namespace std;
int n,num[100100],res,mx,bit[31],pos;
int main(){
	scanf("%d",&n),mx=0,pos=0;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		for(int j=0;j<31;j++)if(num[i]&(1<<j))bit[j]++;
	}
	for(int i=0;i<n;i++){
		res=0;
		for(int j=0;j<31;j++)if((num[i]&(1<<j))&&bit[j]==1)res+=(1<<j);
		if(mx<res)mx=res,pos=i;
	}
	printf("%d ",num[pos]);
	for(int i=0;i<n;i++)if(i!=pos)printf("%d ",num[i]);
//	res=num[0];
//	for(int i=1;i<n;i++)res=(res|num[i])-num[i];
//	printf("%d\n",res);
	return 0;
}