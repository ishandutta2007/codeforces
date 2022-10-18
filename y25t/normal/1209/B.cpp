#include<cstdio>
#include<algorithm>
#define N 105

int n,a[N],b[N];
char s[N];

int st[N];

int ans;

int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		st[i]=s[i]=='1';
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=0;i<=100000;i++){
		int tmp=0;
		for(int j=1;j<=n;j++){
			if(i>=b[j]&&(i-b[j])%a[j]==0)
				st[j]^=1;
			if(st[j])
				tmp++;
		}
		ans=std::max(ans,tmp);
	}
	printf("%d",ans);
}