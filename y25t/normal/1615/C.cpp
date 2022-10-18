#include<bits/stdc++.h>
#define N 100005

int T;

int n;
char a[N],b[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,a+1,b+1);
		int A=0,B=0,C=0,D=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i])
				(a[i]=='0'?A:B)++;
			else
				(a[i]=='0'?C:D)++;
		int ans=N;
		if((A+B)%2==0&&A==B)
			ans=std::min(ans,A+B);
		if((C+D)%2==1&&D==C+1)
			ans=std::min(ans,C+D);
		printf("%d\n",ans==N?-1:ans);
	}
}