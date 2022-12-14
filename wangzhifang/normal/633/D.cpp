#include <cstdio>
#include <unordered_map>
#include <algorithm>
#define max_n 1000
#define INF 2147483647
using namespace std;
int a[max_n+1]={-INF};
unordered_map<int,int> ton;
int b[max_n+1];
int main(){
	int n,i,j,ans=2,sum;
	scanf("%d",&n);
	sum=0;
	for(i = 1; i <= n; i ++)
		scanf("%d",a+i),++ton[a[i]],sum+=(a[i]==0);
	if(sum>ans)
		ans=sum;
	stable_sort(a+1,a+n+1);
	for(i = 1; i <= n; i ++)
		if(i==1||a[i]!=a[i-1]){
			--ton[a[i]];
			for(j = 1; j <= n; j ++){
				if(j==i&&!ton[a[i]])
					continue;
				if(j>1&&a[j]==a[j-1])
					continue;
				if(a[i]==a[j]&&a[i]==0)
					continue;
				--ton[a[j]];
				sum=2;
				int tmp=a[i],temp=a[j];
				b[1]=a[i],b[2]=a[j];
				while(ton.count(tmp+=temp)&&ton[tmp]){
					--ton[tmp];
					swap(tmp,temp);
					b[++sum]=temp;
				}
				if(sum>ans)
					ans=sum;
				ton[b[sum]]++;
				while(--sum>1)
					ton[b[sum]]++;
			}
			++ton[a[i]];
		} 
	printf("%d\n",ans);
	return 0;
}