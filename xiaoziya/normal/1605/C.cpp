#include<stdio.h>
#include<iostream>
#include<map> 
using namespace std;
const int maxn=1000005;
int T,n,flg;
char s[maxn];
map<int,int>mp;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1),flg=0;
		for(int i=1;i<n;i++)
			if(s[i]=='a'&&s[i+1]=='a'){
				puts("2"),flg=1;
				break;
			}
		if(flg)
			continue;
		for(int i=1;i<n-1;i++)
			if(s[i]=='a'&&s[i+2]=='a'){
				puts("3"),flg=1;
				break;
			}
		if(flg)
			continue;
		int tb=0,tc=0,ans=n+1;
		int i=1;
		while(i<=n&&s[i]!='a')
			i++;
		mp.clear(),mp[0]=i;
		while(i<=n){
			int j=i+1,bb=0,cc=0;
			while(j<=n&&s[j]!='a')
				bb+=(s[j]=='b'),cc+=(s[j]=='c'),j++;
			if(j>n)
				break;
			if(j-i>3){
				mp.clear(),mp[0]=j,tb=tc=0,i=j;
				continue;
			}
			if(bb==1&&cc==1){
				puts("4"),flg=1;
				break;
			}
			if(bb==2)
				tb++;
			else tc++;
			if(mp.count(tb-tc)==0)
				mp[tb-tc]=j;
			else{
				ans=min(ans,j-mp[tb-tc]+1);
				mp[tb-tc]=max(mp[tb-tc],j);
			}
			i=j;
		}
		if(ans==n+1&&flg==0)
			puts("-1");
		if(ans<n+1&&flg==0)
			printf("%d\n",ans);
	}
	return 0;
}