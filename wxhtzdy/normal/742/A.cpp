#include <bits/stdc++.h>
using namespace std;

vector<int> a={6,8,4,2};
int main(){
	int n;
	scanf("%d",&n);
	if(n==0)printf("1");
	else printf("%d",a[n%4]);
	return 0;
}