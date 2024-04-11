#include<bits/stdc++.h>
using namespace std;
int n;
long long a[210000];
set<long long> e;
long long minn;
void cal(long long x){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			cnt+=x-a[i];
			if(cnt>minn) return; 
			continue;
		}
		long long t=a[i]%x;
		if(t<=x/2)cnt+=t;
		else cnt+=x-t;
		if(cnt>minn) return; 
	}
	minn=min(minn,cnt);
}
void fac(long long s){
	for(int i=2;i<=1000000;i++){
		if(s%i) continue;
		e.insert(i);
		for(;;){
			if(s%i) break;
			s/=i;
		}
	}
	if(s>1)e.insert(s);
}
int main(){
	srand(1234252);
	scanf("%d",&n);
	minn=n;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	int o=rand()%n+1;
	for(int i=max(1-a[o],-50ll);i<=50;i++)fac(a[o]+i);
	for(auto it=e.begin();it!=e.end();it++) cal(*it);
	cout<<minn;
	return 0;
}