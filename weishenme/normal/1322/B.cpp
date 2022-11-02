#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],num[80000005],ans,n,now;
inline void insert(int x){
	for (;x<=1<<now;x+=x&-x)num[x]^=1;
}
inline int find(int x){
	x=min(x,1<<now);
	int ans=0;
	for (;x;x-=x&-x)ans^=num[x];
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (now=1;now<27;now++){
		int v=0;
		for (int i=1;i<=n;i++){
			int t=a[i]%(1<<now);
			int l=max(-1,(1<<(now-1))-t),r=(1<<now)-t-1;
			v^=(l>0?find(l):0)^find(r+1);
			l=(3<<(now-1))-t,r=(2<<now)-t-1;
			v^=find(l)^find(r+1);
			insert(t+1);
		}
		for (int i=0;i<=1<<now;i++)num[i]=0;
		ans+=v<<now-1;
	}
	printf("%d\n",ans);
}