#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg,A,B;
int cnt[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		cin>>s;
		for(int i=0;i<n;i++)
			cnt[s[i]-96]++;
		for(int i=1;i<=m;i++){
			int j=1;
			while(cnt[j]&&j<=n/m)
				j++;
			putchar(j+96);
			for(int k=1;k<j;k++)
				cnt[k]--;
		}
		puts("");
		for(int i=1;i<=26;i++)
			cnt[i]=0;
	}
	return 0;
}