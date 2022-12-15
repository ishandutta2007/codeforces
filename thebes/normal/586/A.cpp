#include <bits/stdc++.h>
using namespace std;

int n, i, x, ans, p, arr[101];

int main(){
	for(scanf("%d",&n),i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;arr[i]!=1;i++){}
	p = i;
	for(i=n-1;arr[i]!=1;i--){}
	x=i; arr[n]=1;
	for(i=p;i<=x;i++){
		p = arr[i-1];
		if(arr[i] == 1) ans++;
		else if(arr[i]==0){
			if(arr[i+1]==0) ans=ans;
			else if(p!=0) ans++; 
		}
	}
	printf("%d\n",ans);
	return 0;
}