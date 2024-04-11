#include <bits/stdc++.h>
using namespace std;
int n,k,t,need,A[200005],h[200005];
unsigned long long cn,mult;
map<int,int> m[11];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%d",&A[i]);
		t=A[i];
		while(t)t/=10,h[i]++;
		m[h[i]][A[i]%k]++;
	}
	for(int i=0;i<n;++i){
		m[h[i]][A[i]%k]--;
		mult=10;
		for(int z=1;z<11;++z){
			need=(k-(mult*A[i])%k);
			auto it=m[z].find((need==k?0:need));
			if(it!=m[z].end())cn+=it->second;
			mult*=10;
		}
		m[h[i]][A[i]%k]++;
	}
	std::printf("%lld",cn);
	return 0;
}