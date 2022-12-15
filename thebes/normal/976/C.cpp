#include <bits/stdc++.h>
using namespace std;

const int MN=3e5+5;
struct st{int s,e,id;}arr[MN];
int n, i, mx, id;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d%d",&arr[i].s,&arr[i].e),arr[i].id=i;
	sort(arr+1,arr+n+1,[](st i,st j){
		if(i.s==j.s) return i.e>j.e;
		else return i.s<j.s;
	});
	for(i=1;i<=n;i++){
		if(arr[i].e<=mx){
			printf("%d %d\n",arr[i].id,id);
			return 0;
		}
		mx = arr[i].e;
		id = arr[i].id;
	}
	printf("-1 -1\n");
	return 0;
}