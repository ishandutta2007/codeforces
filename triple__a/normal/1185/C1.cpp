#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int maxn=2000007;
int n,M;
int a[maxn];
int s[107];

int main(){
	memset(s,0,sizeof(s));
	scanf("%d%d",&n,&M);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		int j=0,ans=M-a[i],t=0;
		while(j<100){
			if (ans-s[j+1]*(j+1)<0){
				break;
			}
			j++;
			t+=s[j];
			ans-=s[j]*j;
		}
		t+=ans/(j+1);
		printf("%d ",max(0,i-1-t));
		s[a[i]]++;
	}
	return 0;
}