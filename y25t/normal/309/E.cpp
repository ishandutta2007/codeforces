#include<bits/stdc++.h>
#define N 2005

int n,l[N],r[N];

int p[N];

int lst[N],cnt[N];
int ans[N];
inline bool chk(int k){
	for(int i=1;i<=n;i++)
		lst[i]=n;
	int x=p[1];
	for(int i=1;i<=n;i++){
		ans[i]=x,lst[x]=i;
		for(int j=1;j<=n;j++) if(std::max(l[x],l[j])<=std::min(r[x],r[j]))
			lst[j]=std::min(lst[j],i+k);
		for(int j=1;j<=n;j++)
			cnt[j]=0;
		for(int j=1;j<=n;j++)
			cnt[lst[j]]++;
		for(int j=1;j<=n;j++){
			cnt[j]+=cnt[j-1];
			if(cnt[j]>j)
				return 0;
			if(j>i&&cnt[j]==j){
				for(int y=1;y<=n;y++) if(lst[p[y]]>i&&lst[p[y]]<=j){
					x=p[y];
					break;
				}
				break;
			}
		}
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	std::iota(p+1,p+n+1,1),std::sort(p+1,p+n+1,[&](int i,int j){
		return r[i]<r[j];
	});
	int L=1,R=n,res=R+1;
	while(L<=R){
		int mid=(L+R)>>1;
		if(chk(mid))
			res=mid,R=mid-1;
		else
			L=mid+1;
	}
	chk(res);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
}