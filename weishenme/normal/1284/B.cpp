#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int num[N],n,l,x,a[N],b[N];
void insert(int x){
	for (;x;x-=x&-x)num[x]++;
}
int find(int x){
	int ans=0;
	for (;x<N;x+=x&-x)ans+=num[x];
	return ans;
}
int main(){
	scanf("%d",&n);
	int m=0,cnt=0;
	long long ans=0;
	while (n--){
		scanf("%d",&l);
		int Min,Max;
		scanf("%d",&Min);
		Max=Min;
		int flag=0;
		for (int i=2;i<=l;i++){
			scanf("%d",&x);
			if (x>Min)flag=1;
			Max=max(Max,x);
			Min=min(Min,x);
		}
		if (flag==1)ans+=2*(cnt+m)+1,cnt++;
		else a[++m]=Min,b[m]=Max,ans+=cnt*2;
	}
	for (int i=1;i<=m;i++)insert(b[i]);
	for (int i=1;i<=m;i++)ans+=find(a[i]+1);
	printf("%lld\n",ans);
}