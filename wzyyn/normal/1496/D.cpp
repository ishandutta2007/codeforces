#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
int n,a[100005];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int l=2,mx=2,c=1,p=2;
	For(i,3,n){
		if ((a[i]<a[i-1])^(a[i-1]<a[i-2])) l=2;
		else l++;
		if (l>mx) mx=l,c=0,p=i;
		if (l==mx) ++c;
	}
	if (c>2) puts("0");
	else if (c==1) puts("0");
	else if (p!=1&&p!=n&&a[p]>a[p-1]&&a[p]>a[p+1]){
		int l1=1;
		for (;p+l1-1!=n&&a[p+l1-1]>a[p+l1];++l1);
		if (l1!=mx) puts("0");
		else puts(mx%2==1?"1":"0");
	}
	else puts("0");
}
/*
13
3 2 1 6 7 12 14 13 11 5 4 8 9
*/