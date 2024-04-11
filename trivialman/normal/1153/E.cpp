#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 300010;

int n,x,sum=0,i1,i2,j1,j2;

int queryi(int i){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		printf("? %d %d %d %d\n",i,l,i,mid);
		fflush(stdout);
		scanf("%d",&x);
		if(x%2==1) r=mid; else l=mid+1;
	}
	return l;
}

int queryj(int j){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		printf("? %d %d %d %d\n",l,j,mid,j);
		fflush(stdout);
		scanf("%d",&x);
		if(x%2==1) r=mid; else l=mid+1;
	}
	return l;
}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
	//ios::sync_with_stdio(false);cin.tie(0);
	scanf("%d",&n);
	rep(i,1,n-1){
		printf("? %d %d %d %d\n",i,1,i,n);
		fflush(stdout);
		scanf("%d",&x);
		if(x%2==1){
			++sum;
			if(sum==1)i1=i;else i2=i;
		}
	}
	if(sum>0){
		if(sum==1)i2=n;
		j1 = queryi(i1);
		j2 = queryi(i2);
		printf("! %d %d %d %d\n",i1,j1,i2,j2);
		fflush(stdout);
		return 0;
	}
	sum=0;
	rep(j,1,n-1){
		printf("? %d %d %d %d\n",1,j,n,j);
		fflush(stdout);
		scanf("%d",&x);
		if(x%2==1){
			++sum;
			if(sum==1)j1=j;else j2=j;
		}
	}
	if(sum==1)j2=n;
	i1 = queryj(j1);
	i2 = queryj(j2);
	printf("! %d %d %d %d\n",i1,j1,i2,j2);
	fflush(stdout);
	return 0;
}