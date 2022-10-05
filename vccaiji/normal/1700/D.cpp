#include<bits/stdc++.h>
using namespace std;
long long a[1100000],b[1100000];
long long t[1100000];
char s[1100000];
int main(){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<n;i++)a[i+1]+=a[i];
		long long now=a[1];
		for(int i=1;i<=n;i++){
			t[i]=max(now,(a[n]+i-1)/i);
			now=max(now,(a[i]+i-1)/i);
		}
		int q;
		scanf("%d",&q);
		while(q--){
			int tt;
			scanf("%d",&tt);
			if(tt<t[n]){
				printf("-1\n");
				continue;
			}
			int l=1,r=n;
			for(;l<r;){
				int md=(l+r)/2;
				if(t[md]<=tt)r=md;
				else l=md+1;
			}
			printf("%d\n",l);
		}
	return 0;
}