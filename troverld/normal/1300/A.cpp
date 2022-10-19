#include<bits/stdc++.h>
using namespace std;
int T,n,sum,x,num[110],cnt;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),sum=cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			if(num[i]==0)num[i]=1,cnt++;
			sum+=num[i];
		}
		if(sum==0)cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}