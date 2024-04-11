#include <cstdio>
#include <algorithm>
#define cs const
#define max_n 200000
using namespace std;
struct node{
	int a,b,id;
	friend bool operator<(cs node&x,cs node&y){
		if(x.a!=y.a)
			return x.a>y.a;
		return x.b>y.b;
	}
};
node a[max_n+1];
int ans[max_n+1];
int arr[max_n+1];
int prv[max_n+1];
bool pos[max_n+1];//possible
int*sam_ed[max_n+1];
#define addans(nowans,pos) 
int main(){
	int n,*nowans=ans,m=1;
	scanf("%d",&n);
	for(int i=0; ++i<=n; scanf("%d%d",&a[i].a,&a[i].b),a[i].id=i);
	stable_sort(a+1,a+n+1),sam_ed[0]=arr,*(sam_ed[1]=arr+1)=a[1].id;
	for(int i=1; ++i<=n; )
		if(a[i].b>a[m].b){
			a[++m]=a[i];
			*(sam_ed[m]=sam_ed[m-1]+1)=a[i].id;
		}
		else
			a[i].a==a[m].a&&a[i].b==a[m].b&&(*++sam_ed[m]=a[i].id);
	pos[1]=1,prv[1]=0;
	for(int i=1; ++i<=m; pos[i]=1)
		for(int&j=(prv[i]=i-1),k; (k=prv[j])&&(long long)(a[j].a-a[i].a)*(a[j].b-a[k].b)*a[k].a*a[i].b<(long long)(a[k].a-a[j].a)*(a[i].b-a[j].b)*a[i].a*a[k].b; j=prv[j])
			pos[j]=0;
	for(int i=0; ++i<=m; )
		if(pos[i])
			for(int*j=sam_ed[i-1],*ed=sam_ed[i]; ++j<=ed; *++nowans=*j);
	stable_sort(ans+1,nowans+1);
	for(int*i=ans; ++i<nowans; printf("%d ",*i));
	printf("%d\n",*nowans);
	return 0;
}