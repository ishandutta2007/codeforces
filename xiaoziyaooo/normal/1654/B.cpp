#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn],cnt[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		cin>>s,n=s.size(),s=" "+s;
		for(int i=1;i<=n;i++)
			cnt[s[i]-96]++;
		for(int i=1;i<=n;i++){
			if(cnt[s[i]-96]>1)
				cnt[s[i]-96]--;
			else{
				for(int j=i;j<=n;j++)
					printf("%c",s[j]);
				puts("");
				break;
			}
		}
		for(int i=1;i<=26;i++)
			cnt[i]=0;
	}
	return 0;
}