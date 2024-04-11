#include <cstdio>
#include <algorithm>

typedef long long lli;
const int h=100,w=100;

int n,q,c;
int xx[100000],yy[100000],ss[100000];
struct data{
	int t,x1,y1,x2,y2,idx;
	bool operator<(const data &rhs) const {
		return t<rhs.t;
	}
}arr[100000];

lli sum[101][101];
lli ans[100000];

void init(int t) {
	for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) sum[i][j]=0;
	for(int i=0;i<n;i++) {
		sum[yy[i]][xx[i]]+=(ss[i]+t)%c;
	}
	for(int i=1;i<=h;i++) {
		for(int j=1;j<=w;j++) {
			sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
}
lli find(int x1,int y1,int x2,int y2) {
	return sum[y2][x2]-sum[y2][x1-1]-sum[y1-1][x2]+sum[y1-1][x1-1];
}
int main() {
	scanf("%d%d%d",&n,&q,&c);
	c++;
	for(int i=0;i<n;i++) scanf("%d%d%d",xx+i,yy+i,ss+i);
	
	for(int i=0;i<q;i++)scanf("%d%d%d%d%d",&arr[i].t,&arr[i].x1,&arr[i].y1,&arr[i].x2,&arr[i].y2),arr[i].idx=i;
	for(int i=0;i<q;i++) arr[i].t=arr[i].t%c;
	std::sort(arr,arr+q);
	
	for(int i=0;i<q;i++) {
		if(i==0||arr[i-1].t!=arr[i].t) {
			init(arr[i].t);
		}
		ans[arr[i].idx]=find(arr[i].x1,arr[i].y1,arr[i].x2,arr[i].y2);
	}
	for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
	return 0;
}