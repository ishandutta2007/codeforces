#include <bits/stdc++.h>
using namespace std;
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n,k,a[100005],cnt[100005];
signed main(){
	n=read();k=read();
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	int num=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			for(int j=i-num+1;j<=i;j++){
				cnt[j]=num;
			}
			num=1;
		}
		else
			num++;
	}
	int curl=1,curr=n;
//	for(int i=1;i<=n;i++)	cout<<cnt[i]<<" ";
//	puts("");
	while(k>=0&&curl+cnt[curl]<=curr){
		int nxtl=curl+cnt[curl]-1,nxtr=curr-cnt[curr]+1;
		if(nxtl<=n-nxtr+1){
			int add=(a[curl+cnt[curl]]-a[curl])*nxtl;
			if(k-add>=0){
				curl+=cnt[curl];
				k-=add;
			}
			else{
				print(a[curr]-a[curl]-(k/nxtl));
				return 0;
			}
		}
		else{
			int add=(a[curr]-a[curr-cnt[curr]])*(n-nxtr+1);
			if(k-add>=0){
				curr-=cnt[curr];
				k-=add;
			}
			else{
				print(a[curr]-a[curl]-(k/(n-nxtr+1)));
				return 0;
			}
		}
	}
	puts("0");
    return 0;
}