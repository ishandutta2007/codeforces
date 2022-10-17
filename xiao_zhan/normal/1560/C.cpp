#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sb,ans;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&sb);
		if(sb==1){puts("1 1");continue;}
		
		k=0;
		for(i=1;;i++){
			k+=i*2-1;
			if(k>=sb){k-=(i*2-1);ans=i-1;break;}
		}
		//printf("a%d %d\n",ans,k);
		sb-=k;
		if(sb<=ans){
			printf("%d %d\n",sb,ans+1);
		}
		else{
			sb-=ans+1;
			printf("%d %d\n",ans+1,ans+1-sb);
		}
	}
}