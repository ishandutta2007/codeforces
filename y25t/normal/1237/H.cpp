#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define N 4005

int T;

char A[N],B[N];
int n,a[N],b[N];

inline int r(int x){
	if(x==0||x==3)
		return x;
	return x^1^2;
}
std::vector<int> ans;
inline void rev(int x){
	std::reverse(a+1,a+x+1);
	for(int i=1;i<=x;i++)
		a[i]=r(a[i]);
	if(ans.size()&&ans.back()==(x<<1))
		ans.pop_back();
	else
		ans.push_back(x<<1);
//	printf("#%d\n",x);
//	for(int i=1;i<=n/2;i++)
//		printf("%d ",a[i]);
//	puts("");
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",A+1,B+1);
		n=strlen(A+1);
		for(int i=1;i<=n;i+=2)
			a[(i-1)/2+1]=(A[i]=='1')+2*(A[i+1]=='1');
		for(int i=1;i<=n;i+=2)
			b[(i-1)/2+1]=(B[i]=='1')+2*(B[i+1]=='1');
//		for(int i=1;i<=n/2;i++)
//			printf("%d ",a[i]);
//		puts("");
//		for(int i=1;i<=n/2;i++)
//			printf("%d ",b[i]);
//		puts("");
		int c0=0,c3=0;
		for(int i=1;i<=n/2;i++){
			c0+=(a[i]==0)-(b[i]==0);
			c3+=(a[i]==3)-(b[i]==3);
		}
		if(c0||c3){
			puts("-1");
			continue;
		}
		ans.clear();
		int fa=0,fb=0;
		for(int i=1;i<=n/2;i++){
			fa+=(a[i]==1)-(a[i]==2);
			fb+=(b[i]==1)-(b[i]==2);
		}
//		printf("&%d %d\n",fa,fb);
		int tmp=0,x1=fa,x2=fb;
		int flg=0;
		if(std::abs(fa)<std::abs(fb))
			for(int i=1,f=0;i<=n/2;i++){
				f+=(b[i]==1)-(b[i]==2);
				if(f==(fa+fb)/2){
					std::reverse(b+1,b+i+1);
					for(int j=1;j<=i;j++)
						b[j]=r(b[j]);
					flg=i;
					break;
				}
			}
		else
			for(int i=1,f=0;i<=n/2;i++){
				f+=(a[i]==1)-(a[i]==2);
//				printf("*%d %d\n",i,f);
				if(f==(fa+fb)/2){
					rev(i);
					tmp=i;
					break;
				}
			}
//		for(int i=1;i<=n/2;i++)
//			printf("%d ",a[i]);
//		puts("");
//		for(int i=1;i<=n/2;i++)
//			printf("%d ",b[i]);
//		puts("");
		fa=fb=0;
		for(int i=1;i<=n/2;i++){
			fa+=(a[i]==1)-(a[i]==2);
			fb+=(b[i]==1)-(b[i]==2);
		}
		if(fa!=-fb)
			printf("A&%d&%d^%d^%d*%d*%d\n",flg,tmp,x1,x2,fa,fb);
		for(int i=1;i<=n/2;i++)
			for(int j=i;j<=n/2;j++)
				if(a[j]==r(b[n/2-i+1])){
					if(j>1)
						rev(j-1);
					rev(j);
					break;
				}
//		for(int i=1;i<=n/2;i++)
//			printf("%d ",a[i]);
//		puts("");
//		for(int i=1;i<=n/2;i++)
//			printf("%d ",b[i]);
//		puts("");
		if(flg)
			rev(flg);
//		for(int i=1;i<=n/2;i++)
//			if(a[i]!=b[i])
//				puts("A");
		printf("%d\n",ans.size());
		for(auto it=ans.begin();it!=ans.end();it++)
			printf("%d ",*it);
		puts("");
	}
}