#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=5005;
int n,A[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<=n;i++){
		if (i==A[A[A[i]]]){puts("YES");return 0;}
	}
	puts("NO");
	return 0;
}