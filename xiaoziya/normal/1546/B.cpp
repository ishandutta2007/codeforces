#include<stdio.h>
#include<iostream>
using namespace std;
const int maxc=27,maxn=100005;
int T,n,m;
int cnt[maxc],tot[maxc];
string s[maxn],t[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			cin>>s[i];
		for(int i=1;i<n;i++)
			cin>>t[i];
		for(int i=0;i<m;i++){
			for(int j=1;j<=26;j++)
				cnt[j]=0;
			for(int j=1;j<=n;j++)
				cnt[s[j][i]-96]++;
			for(int j=1;j<n;j++)
				cnt[t[j][i]-96]--;
			for(int j=1;j<=26;j++)
				if(cnt[j])
					printf("%c",j+96);
		}
		puts("");
	}
	return 0;
}