#include<iostream>
#include<algorithm>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=500007;
int n,m,q;
int C[maxn];
struct arr{
	long long key,pos;
	friend bool operator<(arr x,arr y){
		return x.key <y.key;
	}
}u[maxn],qr[maxn];

int lowbit(int u){
	return u&(-u);
}

int getsum(int x){
	int ans=0;
	for (int i=x;i>0;i-=lowbit(i)){
		ans+=C[i];
	}
	return ans;
}

void add(int x,int y){
	for (int i=x;i<=m;i+=lowbit(i)){
		C[i]+=y;
	}
}

int mid_search(int t){
	int l=1,r=m,mid=(l+r)>>2;
	while(l!=r){
		mid=(l+r)>>1;
		if (getsum(mid)<t){
			l=mid+1; 
		}
		else{
			r=mid;
		}
	}
	return l;
}
long long ret[maxn];
int main(){
	memset(u,0,sizeof(u));
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;++i){
		u[i].pos=i;
	}
	for (int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		u[k].key++;
	}
	sort(u+1,u+m+1);
	for (int i=1;i<=q;++i){
		scanf("%lld",&qr[i].key);
	}
	for (int i=1;i<=q;++i){
		qr[i].pos=i;
	}
	sort(qr+1,qr+q+1);
	int ans[maxn],t=0,cnt=1,i=1,j=1;
	ret[0]=0;
	while(i<=m){
		while(u[i].key<=t&&i<=m){
			add(u[i].pos,1);
			i++;
		}
		t++;
		ret[t]=ret[t-1]+getsum(m);
		while(qr[j].key-n<=ret[t]&&j<=q){
			ans[qr[j].pos]=mid_search(qr[j].key-n-ret[t-1]);
			j++;
		}
	}
	for (int i=j;i<=q;++i){
		ans[qr[i].pos]=(qr[i].key-n-ret[t]-1)%m+1;
	}
	for (int i=1;i<=q;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}