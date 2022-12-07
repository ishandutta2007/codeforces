#include<bits/stdc++.h>
using namespace std;

bitset<200005> f;
int n,a[105],s;
int main(){
	scanf("%d",&n);
	f[0]=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f|=f<<a[i];
		s+=a[i];
	}
	if (s%2==1||!f[s/2])
		puts("0");
	else{
		for (;;){
			for (int i=1;i<=n;i++)
				if (a[i]%2==1){
					printf("1\n%d",i);
					return 0;
				}
				else a[i]/=2;
		}
	}
}