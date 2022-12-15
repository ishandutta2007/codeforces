#include <bits/stdc++.h>
using namespace std;

const int MN = 1e4+5;
int n, m, k, t, i, x, y, arr[MN];

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&t);
	for(i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		arr[i]=x*m+y;
	}
	sort(arr+1,arr+k+1);
	for(i=1;i<=t;i++){
		scanf("%d%d",&x,&y);
		int p=lower_bound(arr+1,arr+k+1,x*m+y)-arr;
		if(x*m+y==arr[p]) printf("Waste\n");
		else{
			int s=((x-1)*m+y-p+1)%3;
			printf("%s\n",(s==1)?"Carrots":(s==2)?"Kiwis":"Grapes");
		}
	}
	return 0;
}