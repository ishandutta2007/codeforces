#include<bits/stdc++.h>
#define N 200005

int T;

int n,k,a[N];

int c[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			c[i]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),c[a[i]]++;
		int tmp=n,x=0,y=0;
		for(int l=1,r=0,s=0;l<=n;l++){
			while(r<n&&s<(n+k+1)/2)
				s+=c[++r];
			if(s>=(n+k+1)/2&&r-l<tmp)
				x=l,y=r,tmp=y-x;
			s-=c[l];
		}
		printf("%d %d\n",x,y);
		for(int i=1,lst=0,s=0,cnt=0;i<=n;i++){
			s+=a[i]>=x&&a[i]<=y?1:-1;
			if(s>=1&&(cnt<k-1||i==n))
				printf("%d %d\n",lst+1,i),lst=i,cnt++,s=0;
		}
	}
}