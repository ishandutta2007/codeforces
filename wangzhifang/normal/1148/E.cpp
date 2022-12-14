#include <cstdio>
#include <algorithm>
#define max_n 300000
using namespace std;
typedef const int& ci;
struct node{
	int s,id;
	friend bool operator<(const node&x,const node&y){
		return x.s<y.s;
	}
};
node a[max_n+1];
int t[max_n+1];
struct oper{
	int i,j,d;
	oper(){}
	oper(ci _i,ci _j,ci _d):i(_i),j(_j),d(_d){}
};
oper op[max_n];
int main(){
	int n,m;
	long long sum=0;
	scanf("%d",&n),m=0;
	for(int i=0; ++i<=n; a[i].id=i,sum+=a[i].s)
		scanf("%d",&a[i].s);
	for(int i=0; ++i<=n; sum-=t[i])
		scanf("%d",t+i);
	if(sum){
		puts("NO");
		return 0;
	}
	stable_sort(a+1,a+n+1),stable_sort(t+1,t+n+1);
	for(int i=0; ++i<=n; a[i].s-=t[i]);
	int j=0;
	while(a[++j].s<=0);
	for(int i=0; ++i<n; ){
		if(a[i].s>0){
			puts("NO");
			return 0;
		}
		while(a[i].s){
			if(a[j].s+a[i].s>0){
				op[++m]=oper(a[i].id,a[j].id,-a[i].s);
				a[j].s+=a[i].s;
				a[i].s=0;
				break;
			}
			op[++m]=oper(a[i].id,a[j].id,a[j].s);
			a[i].s+=a[j].s;
			a[j].s=0;
			while(a[++j].s<=0);
		}
	}
	puts("YES");
	printf("%d\n",m);
	for(int i=0; ++i<=m; printf("%d %d %d\n",op[i].i,op[i].j,op[i].d));
	return 0;
}