#include<bits/stdc++.h>
using namespace std;
int n,m,a[5009],s[5009],tot;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		double x;
		scanf("%d%lf",&a[i],&x);
	}
	tot=0;s[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=s[tot]) s[++tot]=a[i];
		else{
			int l=1,r=tot,ans=l;
			while(l<=r){
				int mid=(l+r)/2;
				if(s[mid]>a[i]) r=mid-1,ans=mid;
				else l=mid+1;
			}
			s[ans]=a[i];
		}
	}
	printf("%d\n",n-tot);
	return 0;
}