#include<cstdio>
#define N 200005

int T;

int n;
char a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,a+1);
		int ans=0,tmp=0,t=0;
		for(int i=1;i<=n;i++)
			if(a[i]==a[i-1])
				tmp++;
			else if(tmp!=i-1){
				ans+=tmp/3;
				tmp=1;
			}
			else{
				t=tmp;
				tmp=1;
			}
		if(tmp==n)
			ans+=(n-1)/3+1;
		else if(a[1]==a[n])
			ans+=(tmp+t)/3;
		else
			ans+=tmp/3+t/3;
		printf("%d\n",ans);
	}
}