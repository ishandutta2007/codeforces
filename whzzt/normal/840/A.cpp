#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N],b[N],ida[N],idb[N],da[N];

bool cmpa(const int&x,const int&y){
	return a[x]<a[y];
}
bool cmpb(const int&x,const int&y){
	return b[x]>b[y];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),ida[i]=i;
	for(int i=1;i<=n;i++)scanf("%d",b+i),idb[i]=i;
	sort(ida+1,ida+n+1,cmpa);
	sort(idb+1,idb+n+1,cmpb);
	for(int i=1;i<=n;i++)da[idb[i]]=a[ida[i]];
	for(int i=1;i<=n;i++)printf("%d ",da[i]);
	return 0;
}