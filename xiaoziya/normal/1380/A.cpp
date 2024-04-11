#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn],f[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),flg=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			f[i]=0;
			for(int j=1;j<i;j++)
				if(a[j]<a[i])
					f[i]|=1;
			for(int j=i+1;j<=n;j++)
				if(a[j]<a[i])
					f[i]|=2;
			if(f[i]==3){
				puts("YES");
				for(int j=1;j<i;j++)
					if(a[j]<a[i]){
						printf("%d ",j);
						break;
					}
				printf("%d ",i);
				for(int j=i+1;j<=n;j++)
					if(a[j]<a[i]){
						printf("%d\n",j);
						break;
					}
				flg=1;
				break;
			}
		}
		if(flg==0)
			puts("NO");
	}
	return 0;
}