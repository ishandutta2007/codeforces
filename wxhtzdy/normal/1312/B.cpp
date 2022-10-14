#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
	int tt;
	scanf("%i",&tt);
	while(tt--){
		int n;
		scanf("%i",&n);
		int a[n];
		for(int i=0;i<n;i++)scanf("%i",&a[i]);
		sort(a,a+n);
		reverse(a,a+n);
		for(int i=0;i<n;i++)printf("%i ",a[i]);
		printf("\n");
	}
}