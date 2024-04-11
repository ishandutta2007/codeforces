#include<bits/stdc++.h>
using namespace std;
int T,a,b,m;
bool ok[200100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		int tmp=(a+b)>>1;
		for(int i=0;i<=min(a,tmp);i++)if(a-i<=a+b-tmp)ok[(tmp-i)+(a-i)]=true;
		tmp=a+b-tmp;
		for(int i=0;i<=min(a,tmp);i++)if(a-i<=a+b-tmp)ok[(tmp-i)+(a-i)]=true;
		for(int i=0;i<=a+b;i++)if(ok[i])m++;
		printf("%d\n",m);
		for(int i=0;i<=a+b;i++)if(ok[i])printf("%d ",i),ok[i]=false;puts("");
		m=0;
	}
	return 0;
}