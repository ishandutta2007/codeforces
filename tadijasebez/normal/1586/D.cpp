#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N];
int Ask(int n){
	printf("?");
	for(int i=1;i<=n;i++){
		printf(" %i",a[i]);
	}
	printf("\n");
	fflush(stdout);
	int b;
	scanf("%i",&b);
	return b;
}
int ans[N];
int main(){
	int n;
	scanf("%i",&n);
	bool ok=false;
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++)a[j]=i+1;
		a[n]=1;
		int idx=Ask(n);
		if(!idx){
			ans[n]=i;
			for(int j=1;j<n;j++){
				if(ans[j])ans[j]=i-ans[j];
			}
			ok=true;
			break;
		}
		ans[idx]=i;
	}
	if(!ok){
		ans[n]=n;
		for(int j=1;j<n;j++){
			if(ans[j])ans[j]=n-ans[j];
		}
	}
	for(int i=ans[n]+1;i<=n;i++){
		for(int j=1;j<n;j++)a[j]=1;
		a[n]=i-ans[n]+1;
		int idx=Ask(n);
		ans[idx]=i;
	}
	printf("!");
	for(int i=1;i<=n;i++){
		printf(" %i",ans[i]);
	}
	printf("\n");
	fflush(stdout);
	return 0;
}