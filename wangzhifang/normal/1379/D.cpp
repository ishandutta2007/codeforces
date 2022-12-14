#include <cstdio>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
#define max_n 100000
struct node{
	int v,id;
	il friend bool operator<(cs node&x,cs node&y){
		return x.v<y.v;
	}
};
node a[max_n<<1|1];
int main(){
	int n,h,m,k;
	scanf("%d%d%d%d",&n,&h,&m,&k);
	m>>=1;
	for(int i=1,x,y; i<=n; ++i){
		scanf("%d%d",&x,&y);
		a[i].v=y%m,a[i].id=i;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i)
		a[i+n]=a[i],a[i+n].v+=m;
	int ans=n+1,pos=0;
	for(int i=n*2,j=n*2; i>n; --i){
		for(int v=a[i].v-k; a[j].v>v; --j);
		cs int tmp=i-j-1;
		if(tmp<ans)
			ans=tmp,pos=i;
	}
	printf("%d %d\n",ans,a[pos].v-m);
	for(int i=pos-ans; i<pos; ++i)
		printf("%d ",a[i].id);
	return 0;
}