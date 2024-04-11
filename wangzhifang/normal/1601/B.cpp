#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
#define max_n 300000
int a[max_n+1],b[max_n+1],c[max_n+1];
int mn[max_n+1][20];
vector<int> ans;
il int query(int l,int r){
	int k=31-__builtin_clz(r-l+1);
	l=mn[l][k],r=mn[r-(1<<k)+1][k];
	return c[l]<=c[r]?l:r;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	for(int i=1; i<=n; ++i)
		scanf("%d",b+i);
	for(int i=1; i<=n; ++i)
		c[i]=-a[i+b[i]]+i+b[i];
    for(int i=1; i<=n; ++i)
    	mn[i][0]=i;
    for(int j=1,d=2; d<=n; ++j,d<<=1)
		for(int i=1; i+d-1<=n; ++i)
			mn[i][j]=c[mn[i][j-1]]<c[mn[i+(d>>1)][j-1]]?mn[i][j-1]:mn[i+(d>>1)][j-1];
	ans.clear();
    for(int i=query(n-a[n],n),lst=n; i; i=(i==a[i]?0:query(i-a[i],i))){
//    	printf("*%d\n",i);
    	ans.push_back(i);
    	i+=b[i];
    	if(i-a[i]>=lst-a[lst]){
    		puts("-1");
    		return 0;
		}
		lst=i;
//    	printf("&%d\n",i-a[i]);
	}
	printf("%d\n",(int)ans.size()+1);
	for(int i:ans){
		printf("%d ",i);
	}
	puts("0");
    return 0;
}