#include<bits/stdc++.h>
using namespace std;
const long long N=1000006;
long long ct[N],pd[N];
bool num[N<<5];
long long n,m;
int main(){
    scanf("%d%d",&n,&m);
	long long cnt=0;
	for(long long i=1;i<=21;i++){
		for(long long j=1;j<=m;j++){
			if(!num[i*j]){
				num[i*j]=1;
				cnt++;
			}
		}
		ct[i]=cnt;
	}
	long long ans=1;
	for(long long i=2;i<=n;i++){
		if(pd[i])continue;
		long long ccnt=0;
		for(long long now=i;now<=n;now*=i){
			pd[now]=1;
			ccnt++;
		}
		ans+=ct[ccnt];
	}
    printf("%lld",ans);
	return 0;
}