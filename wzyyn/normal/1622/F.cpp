#include<bits/stdc++.h>

using namespace std;

const int N=1000005;

int mn[N],n;
long long hsh[N],v[N];
map<long long,int> mp;
mt19937 rng(time(0));

long long rnd(){
	long long v=0;
	for (int i=1;i<=8;i++)
		v=(v<<8)+(rng()&255);
	return v;
}
void init(){
	for (int i=2;i<N;i++) if (!mn[i]){
		hsh[i]=rnd();
		for (int j=i;j<N;j+=i)
			if (!mn[j]) mn[j]=i;
	}
	v[1]=0;
	for (int i=2;i<N;i++)
		v[i]=v[i/mn[i]]^hsh[mn[i]];
	for (int i=2;i<N;i++)
		v[i]^=v[i-1];
}
void print(int ban1,int ban2,int ban3){
	long long sum=0;
	printf("%d\n",n-(ban1!=-1)-(ban2!=-1)-(ban3!=-1));
	for (int i=1;i<=n;i++)
		if (i!=ban1&&i!=ban2&&i!=ban3)
			printf("%d ",i),sum^=v[i];
	assert(sum==0);
	exit(0);
}
int main(){
	init();
	scanf("%d",&n);
	long long sum=0;
	for (int i=1;i<=n;i++) sum^=v[i];
	if (sum==0) print(-1,-1,-1);
	else if (n%4==0) print(n/2,-1,-1);
	else{
		for (int i=1;i<=n;i++)
			if (sum==v[i])
				print(i,-1,-1);
		if (n%4==2) print(2,n/2,-1);
		if (n%4==1) print(n,(n-1)/2,-1);
		else{
			for (int i=1;i<=n;i++)
				mp[v[i]]=i;
			for (int i=1;i<=n;i++)
				if (mp.count(sum^v[i]))
					print(i,mp[sum^v[i]],-1);
			if (n%4==3) print(n,(n-1)/2,2);
		}
 	}
}