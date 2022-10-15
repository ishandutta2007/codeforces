#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 200005
using namespace std;
int n,a[N],s[N<<1],F[N<<1],G[N<<1],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1,j;i<=n;i=j){
		for(j=i;j<=n && a[j]==a[i];j++);
		s[j-i]++;
	}
	for(int i=2;i<=n*2;i++) s[i]+=s[i-1];
	for(int i=n;i;i--){
		//if(s[i]) cout<<i<<" "<<s[i]<<endl;
		G[i]=G[i<<1]+s[i*2-1]-s[i-1];
		if(G[i]){
			G[i]--;
			F[i]=F[i<<1]+i;
			ans=max(ans,F[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}