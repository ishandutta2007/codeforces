#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		long long hc,dc,hm,dm,k,w,a;
		scanf("%lld%lld%lld%lld%lld%lld%lld",&hc,&dc,&hm,&dm,&k,&w,&a);
		int flg=0;
		for(int i=0;i<=k;i++){
			hc+=1ll*i*a,dc+=1ll*(k-i)*w;
			long long A=(hm+dc-1)/dc,B=(hc+dm-1)/dm;
			if(A<=B){
				flg=1;
				break;
			}
			hc-=1ll*i*a,dc-=1ll*(k-i)*w;
		}
		puts(flg==0? "NO":"YES");
	}
	return 0;
}