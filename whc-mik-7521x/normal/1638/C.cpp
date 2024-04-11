#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,p[N],a[N];
int l[N],fat[N];
int find(int x){return fat[x]==x?fat[x]:fat[x]=find(fat[x]);}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&p[i]),a[p[i]]=i;
		l[n+1]=n+1;
		for(int i=n;i;i--)l[i]=min(l[i+1],p[i]),fat[i]=i;
		int id=a[n];
		for(int i=n-1;i;i--){
			if(l[id]<=i)fat[find(i)]=find(i+1);
			id=min(id,a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++)ans+=(find(i)==i);
		printf("%d\n",ans);
	}
	return 0;
}