#include <bits/stdc++.h>
using namespace std;
int n,a[200001];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)	scanf("%d",a+i);
	sort(a,a+n);
	int l=0,r=0,res=0;
	while(r<n){
		while(r<n&&a[r]-a[l]<=5)	r++;
		res=max(res,r-l);
		l++;
	}
	printf("%d\n",res);
}