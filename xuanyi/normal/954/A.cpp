#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 105
using namespace std;
int n,ans; char s[MAXN];
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i+1<n;)
		if (s[i]^s[i+1]) i=i+2,ans++; else i++;
	printf("%d\n",n-ans);
	return 0;
}