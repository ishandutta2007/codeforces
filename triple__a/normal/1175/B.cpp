#include<iostream>
#include<cstdio>
using namespace std;

const int maxn=100007;
typedef long long ll;
int n,m=0;
ll ans=0,cnt[maxn];
int a[maxn];

int main(){
	scanf("%d",&n);
	cnt[0]=1;
	for (int i=1;i<=n;++i){
		char c[5];
		cin>>c;
		if (c[0]=='a'){
			ans+=cnt[m];
			if (ans>=(1ll<<32)||cnt[m]==0){
				printf("OVERFLOW!!!");
				return 0;
			}
		}
		else{
			if (c[0]=='e'){
				m--;
			}
			else{
				int u;
				scanf("%d",&u);
				a[m++]=u;
				cnt[m]=cnt[m-1]*u;
				if (cnt[m]>=(1ll<<32)){
					cnt[m]=0;
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}