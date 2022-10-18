#include<cstdio>
#define N 100005

int n,q,a[N];

int cnt;

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]==1)
			cnt++;
	}
	while(q--){
		int opt,x;
		scanf("%d%d",&opt,&x);
		if(opt==2)
			printf("%d\n",x<=cnt);
		else{
			if(a[x]){
				a[x]=0;
				cnt--;
			}
			else{
				a[x]=1;
				cnt++;
			}
		}
	}
}