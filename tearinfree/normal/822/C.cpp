#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>

struct Data {
	int val,idx,type;
	bool operator<(const Data &rhs) const {
		if(val!=rhs.val) return val<rhs.val;
		else return type<rhs.type;
	}
};
int n,x;
int ll[200000],rr[200000],cost[200000];
Data arr[400000];
int cc[400001];

int main() {
	scanf("%d %d",&n,&x);
	for(int i=0;i<n;i++) {
		scanf("%d %d %d",ll+i,rr+i,cost+i);
		arr[i].val=ll[i]; arr[i].type=0; arr[i].idx=i;
		arr[i+n].val=rr[i]; arr[i+n].type=1; arr[i+n].idx=i;
	}
	memset(cc,-1,sizeof(cc));
	int max=2e9+1;
	std::sort(arr, arr+n+n);
	for(int i=0;i<n+n;i++) {
		if(arr[i].type==0) {
			int seg=x-(rr[arr[i].idx]-ll[arr[i].idx]+1);
			if(seg<0) continue;
			if(cc[seg]!=-1&&cost[arr[i].idx]+cc[seg]<max) {
				max=cost[arr[i].idx]+cc[seg];
			}
		}
		else {
			int seg=(rr[arr[i].idx]-ll[arr[i].idx]+1);
			if(cc[seg]==-1||cc[seg]>cost[arr[i].idx]) cc[seg]=cost[arr[i].idx];
		}
	}
	if(max==2e9+1) printf("-1\n");
	else printf("%d\n",max);
	return 0;
}