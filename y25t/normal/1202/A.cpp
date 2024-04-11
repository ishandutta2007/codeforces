#include<cstdio>
#include<cstring>
#define N 100005

int T;

char x[N],y[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",x+1,y+1);
		int tmp;
		for(tmp=strlen(y+1);tmp;tmp--)
			if(y[tmp]=='1')
				break;
		int ans=0;
		for(int i=strlen(x+1)-(strlen(y+1)-tmp);i;i--,ans++)
			if(x[i]=='1')
				break;
		printf("%d\n",ans);
	}
}