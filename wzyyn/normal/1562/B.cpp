#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int n,cnt[12];
char s[55];
int fl[1005];
void init(){
	for (int i=2;i<1005;i++)
		for (int j=2;j*i<1005;j++)
			fl[i*j]=1;
}
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=n;i++) s[i]-='0';
	for (int i=1;i<=n;i++)
		if (s[i]==1||s[i]==4||s[i]==6||s[i]==8||s[i]==9)
			return printf("1\n%d\n",(int)s[i]),void(0);
	for (int i=1;i<=n;i++) ++cnt[s[i]];
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (fl[s[i]*10+s[j]])
				return printf("2\n%d%d\n",(int)s[i],(int)s[j]),void(0);
	for (int i=1;i<=9;i++)
		if (cnt[i]>=3)
			return printf("3\n%d%d%d\n",i,i,i),void(0);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			for (int k=j+1;k<=n;j++)
				if (fl[s[i]*100+s[j]*10+s[k]])
					return printf("3\n%d%d%d\n",(int)s[i],(int)s[j],(int)s[k]),void(0);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
4689
12357
1&2
*/