#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int A[400000],n,t;
int main(){
	scanf("%d%d",&n,&t);
	for (int i=1;i<n;i++) scanf("%d",&A[i]);
	int now=1;
	while (now<t) now+=A[now];
	if (now==t) cout<<"YES"<<endl; else cout<<"NO"<<endl;
	return 0;
}