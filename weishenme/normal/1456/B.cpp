#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]^=a[i-1];
	int ans=1e9;
	for (int i=1;i<n;i++)
		for (int j=i;j<n&&j<=i+60;j++)
			for (int k=j+1;k<=j+60&&k<=n;k++)
				if ((a[j]^a[i-1])>(a[k]^a[j]))ans=min(ans,k-i-1);
	if (ans==1e9)puts("-1");
	else printf("%d\n",ans);
}