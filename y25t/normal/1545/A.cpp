#include<bits/stdc++.h>
#define N 100005

int T;

int n,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		std::vector<int> b,c;
		for(int i=1;i<=n;i+=2)
			b.push_back(a[i]);
		for(int i=2;i<=n;i+=2)
			c.push_back(a[i]);
		std::sort(b.begin(),b.end());
		std::sort(c.begin(),c.end());
		bool flg=1;
		for(int i=1,j=0,k=0;i<=n;i++){
			if(i&1)
				a[i]=b[j++];
			else
				a[i]=c[k++];
			if(i>1&&a[i]<a[i-1])
				flg=0;
		}
		puts(flg?"YES":"NO");
	}
}