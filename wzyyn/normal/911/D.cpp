#include<bits/stdc++.h>
#define M 450
using namespace std;
int a[1005],n,m,l,r,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i]>a[j]) ans^=1;
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		if (((r-l)*(r-l+1)/2)&1) ans^=1;
		puts(ans?"odd":"even");
	}
}