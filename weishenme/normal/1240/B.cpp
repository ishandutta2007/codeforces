#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,T,cnt,a[N],b[N],r[N],l[N];
int ef(int x){
	int l=1,r=cnt;
	while (l<r){
		int mid=(l+r)/2;
		if (b[mid]<x)l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);cnt=0;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]),b[++cnt]=a[i];
		sort(b+1,b+cnt+1);
		int num=1,ans=n;
		for (int i=2;i<=cnt;i++)
			if (b[i]!=b[num])b[++num]=b[i];
		cnt=num;	
		for (int i=1;i<=cnt;i++)l[i]=1e9,r[i]=0;
		for (int i=1;i<=n;i++)a[i]=ef(a[i]);
		for (int i=1;i<=n;i++)l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
		for (int i=1,j=1;i<=cnt;i=j){
			j++;
			while (j<=cnt&&r[j-1]<l[j])j++;
			ans=min(ans,cnt-(j-i));
		}
		printf("%d\n",ans);
	}
}