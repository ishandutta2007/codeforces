#include<bits/stdc++.h>
#define N 105

int a[N],b[N],c[N<<1];

int n,p[N];

int T;
inline int qry(int x,int y){
	assert(++T<=2*n);
	printf("? ");
	for(int i=1;i<=n;i++)
		printf("%d ",(i==x?y+1:1));
	puts("");
	fflush(stdout);
	static int res;
	scanf("%d",&res);
	return res;
}

int main(){
	scanf("%d",&n);
//	srand(time(0));
//	std::iota(a+1,a+n+1,1);
//	std::random_shuffle(a+1,a+n+1);
//	for(int i=1;i<=n;i++)
//		printf("%d ",a[i]);
//	puts("");
//	for(int i=1;i<=n;i++)
//		scanf("%d",&a[i]);
	int o=0,x=1;
	while(x<n){
		while(o<n)
			if(qry(++o,n-x))
				break;
		p[o]=x;
		while(x<n){
			x++;
			int tmp=qry(o,x-p[o]);
			if(tmp<o)
				p[tmp]=x;
			else
				break;
		}
	}
	if(!p[n])
		p[n]=n;
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
	puts("");
	fflush(stdout);
//	for(int i=1;i<=n;i++)
//		assert(a[i]==p[i]);
}