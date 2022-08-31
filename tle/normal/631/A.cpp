#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[1001],b[1001],B=0,C=0,ans=0;
inline void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) B|=a[i];
	for(int i=1;i<=n;i++) C|=b[i];
	cout<<B+C;
}
int main(){
	init();
	return 0;
}