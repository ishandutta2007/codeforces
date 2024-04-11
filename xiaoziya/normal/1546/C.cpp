#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=100005;
int T,n;
int a[maxn],b[maxn],cnt[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),b[i]=a[i];
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i+=2)
			cnt[a[i]]++,cnt[b[i]]--;
		int flg=0;
		for(int i=1;i<=100000;i++){
			if(cnt[i])
				flg=1;
			cnt[i]=0;
		}
		puts(flg==0? "YES":"NO");
	}
	return 0;
}