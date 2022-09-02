#include<cstdio>
#include<algorithm>
const int N=1000005;
int x,tot,ans[N],res;
int main(){
	scanf("%d",&x);
	while(1){
		int pos=-1;
		for(int i=29;i>=0;--i)if((x>>i+1&1)&&!(x>>i&1)){
			pos=i;break;
		}
		if(pos==-1)break;
		ans[++ans[0]]=pos+1;
		++res;
		x^=(1<<pos+1)-1;
		if((x&x+1)==0){
			break;
		}
		++res;
		++x;
	}
	printf("%d\n",res);
	for(int i=1;i<=ans[0];++i)printf("%d ",ans[i]);
	return 0;
}