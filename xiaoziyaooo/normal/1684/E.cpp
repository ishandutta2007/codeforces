#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,k,T,ans,rm;
int a[maxn],b[maxn];
map<int,int>mp;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),rm=m;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),mp[a[i]]++;
		sort(a+1,a+1+n);
		int MEX=n;
		for(int i=0;i<=n;i++)
			if(mp[i]==0){
				if(m==0){
					MEX=i;
					break;
				}
				m--;
			}
		for(int i=1;i<=n;i++)
			if(a[i]<MEX)
				mp[a[i]]--;
		int tot=0;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
			if(it->second>0)
				tot++,b[++k]=it->second;
		sort(b+1,b+1+k);
		for(int i=1;i<=k;i++){
			if(rm>=b[i])
				rm-=b[i],tot--;
			else break;
		}
		printf("%d\n",tot);
		mp.clear(),k=0;
	}
	return 0;
}