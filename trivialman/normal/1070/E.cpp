#include<iostream>
#include<cstdio> 
#include<cstring> 
#include<algorithm>
#include<string>
using namespace std;
#define N 200010
#define LL long long

int p[N],sortedp[N];
int n,m,cases;
LL t;

void solve(){
	scanf("%d%d%lld",&n,&m,&t);
	for(int i=1;i<=n;i++){
		scanf("%d",p+i);
		sortedp[i]=p[i];
	}
	sort(sortedp+1, sortedp+n+1);
	sortedp[0]=1;
	int l=1, r=n, mid, maxnum=0;
	while(l<=r){
		mid=(l+r)/2;
		LL d=sortedp[mid], cnt=0, sumtime=0, temptime=0;
		for(int i=1;i<=n && sumtime<=t;i++){
			if(p[i]<=d){
				sumtime += p[i];
				temptime += p[i];
				++cnt;
				if(cnt>=mid)break;
				if(cnt%m==0){
					sumtime+=temptime;
					temptime=0;
				}
			}
		}
		if(sumtime<=t){
			l = mid+1;
			maxnum = mid;
		}else{
			r = mid-1;
		}
	}
	printf("%d %d\n",maxnum,sortedp[maxnum]); 
}

int main(){
	scanf("%d",&cases);
	while(cases--)solve();
	return 0;
}