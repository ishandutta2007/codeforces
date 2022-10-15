#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn = 300000;
typedef long long LL;

int cnt=0;
bool v[maxn+7];
int p[maxn+7];
bool fl[maxn+7];

void make_list(int n){
	memset(v,1,sizeof(v));
	for (int i=2;i<=n;++i){
		if (!v[i]) continue;
		p[cnt++]=i;
		for (int j=2;i*j<=n;++j){
			v[i*j]=0;
		} 
	}
}

LL numbers(int n){
	LL ans=0;
	for (int i=1;i<=n;++i){
		ans+=n/i;
	}
	return ans-n;
}

int mids(int l,int r,LL gl){
	if (l==r) return l;
	int mid=(l+r)>>1;
	if (numbers(mid)<gl){
		return mids(mid+1,r,gl);
	}
	else{
		return mids(l,mid,gl);
	}
}

int main(){
	int n;
	LL k;
	scanf("%d%lld",&n,&k);
	if (numbers(n)<k){
		printf("No");
		return 0;
	}
	LL ans=mids(1,n,k),num=numbers(ans),tp=ans;
	make_list(ans);
	memset(fl,1,sizeof(fl));
	for (int i=0;i<cnt;++i){
		if (ans/p[i]>num-k) continue;
		fl[p[i]]=0;
		num-=ans/p[i];
		tp--;
	}
	printf("Yes\n%lld\n",tp);
	for (int i=1;i<=ans;++i){
		if(fl[i]){
			printf("%d ",i);
		}
	}
	return 0;
}