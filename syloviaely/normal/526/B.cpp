#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[5000],ans=0,f[5000],n;
void findans(int k1,int k2){
	if (k2==n) return;
	findans(k1*2,k2+1); findans(k1*2+1,k2+1);
	ans+=abs(f[k1*2]+a[k1*2]-f[k1*2+1]-a[k1*2+1]);
	f[k1]=max(f[k1*2]+a[k1*2],f[k1*2+1]+a[k1*2+1]);
}
int main(){
	scanf("%d",&n);
	for (int i=2;i<(1<<n+1);i++) scanf("%d",&a[i]);
	findans(1,0);
	cout<<ans<<endl;
}