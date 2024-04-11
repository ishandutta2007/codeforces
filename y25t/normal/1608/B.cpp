#include<bits/stdc++.h>
#define N 100005

int T;

int n,a,b;

int p[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&a,&b);
		if(a+b>n-2||abs(a-b)>1)
			puts("-1");
		else{
			p[0]=0;
			int i=1,tp=a>=b?1:-1;
			for(;i<n&&(a||b);i++,tp*=-1){
				p[i]=p[i-1]+i*tp;
				(tp==1?a:b)--;
			}
			p[i]=p[i-1]+tp*i;
			for(i++;i<n;i++)
				p[i]=p[i-1]+tp;
			int x=*std::min_element(p,p+n);
			for(int j=0;j<n;j++)
				printf("%d ",p[j]-x+1);
			puts("");
		}
	}
}