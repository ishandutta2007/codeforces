#include<cstdio>

int n,a[15];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char c=getchar();
		while(c!='L'&&c!='R'&&(c<'0'||c>'9'))
			c=getchar();
		if(c=='L')
			for(int i=0;i<10;i++)
				if(!a[i]){
					a[i]=1;
					break;
				}
		if(c=='R')
			for(int i=9;i>=0;i--)
				if(!a[i]){
					a[i]=1;
					break;
			}
		if(c>='0'&&c<='9')
			a[c-'0']=0;
	}
	for(int i=0;i<10;i++)
		printf("%d",a[i]);
}