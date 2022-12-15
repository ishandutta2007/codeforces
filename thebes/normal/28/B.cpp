#include <bits/stdc++.h>
using namespace std;

const int MN = 105;
int ds[MN], i, n, arr[MN], x;
int ld(int x){return ds[x]=(x==ds[x]?x:ld(ds[x]));}

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		ds[i]=i, scanf("%d",&arr[i]);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		if(i+x<=n) ds[ld(i)]=ld(i+x);
		if(i-x>=1) ds[ld(i)]=ld(i-x);
	}
	bool flag = 1;
	for(i=1;i<=n;i++){
		if(ld(i)!=ld(arr[i]))
			flag = 0;
	}
	printf("%s\n",(flag)?"YES":"NO");
	return 0;
}