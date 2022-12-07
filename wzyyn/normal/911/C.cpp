#include<bits/stdc++.h>
#define M 450
using namespace std;
int k1,k2,k3,a[3000005];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%d%d",&k1,&k2,&k3);
	if (1.0/k1+1.0/k2+1.0/k3<0.98)
		return puts("NO"),0;
	int p=k1*k2/gcd(k1,k2);
	int q=p*k3/gcd(k2,k3);
	for (int i=1;i<=k1;i++)
		for (int j=1;j<=k2;j++)
			for (int k=1;k<=k3;k++){
				for (int l=1;l<=q;l++) a[l]=0;
				for (int l=i;l<=q;l+=k1) a[l]=1;
				for (int l=j;l<=q;l+=k2) a[l]=1;
				for (int l=k;l<=q;l+=k3) a[l]=1;
				int sum=0;
				for (int l=1;l<=q;l++)
					if (sum+=a[l]);
				if (sum==q) return puts("YES"),0;
			}
	puts("NO");
}