#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],cz[5],b[1000005];
string s;
char sa[1000005];
void solve(int l,int r){
	if(l>=r)return ;
	long long sum=1;
	for(;l<=r;l++){
		if(a[l]!=1)break;
		sa[l-1]='+';
	}
	for(;r>=l;r--){
		if(a[r]!=1)break;
		sa[r-2]='+';
	}
	for(int i=l;i<=r;i++){
		sum*=a[i];
		if(sum>1e5){
			for(int i=l;i<r;i++){
				sa[i-1]='*';
			}
			return;
		}
	}
	int dp[1000005],cl[1000005];
	dp[l-1]=0;
	for(int i=l;i<=r;i++){
		dp[i]=dp[i-1]+a[i];
		cl[i]=i;
		if(a[i]!=1){
			long long num=a[i];
			for(int j=i-1;j>=l;j--){
				num*=a[j];
				if(dp[i]<=dp[j-1]+num){
					dp[i]=dp[j-1]+num;
					cl[i]=j;
				}
			}
		}
	}
	int xp=r;
	while(xp>=l){
		for(int i=cl[xp];i<xp;i++){
			sa[i-1]='*';
		}
		sa[cl[xp]-2]='+';
		xp=cl[xp]-1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	cin>>s;
	for(int i=0;i<(int)s.length();i++){
		if(s[i]=='+')cz[1]=1;
		if(s[i]=='-')cz[2]=1;
		if(s[i]=='*')cz[3]=1;
	}
	if((int)s.length()==1){
		for(int i=1;i<=n;i++){
			printf("%d%c",a[i],i!=n?s[0]:'\n');
		}
		return 0;
	}
	if(!cz[3]){
		for(int i=1;i<=n;i++){
			printf("%d%c",a[i],i!=n?'+':'\n');
		}
		return 0;
	}
	if(!cz[1]){
		for(int i=1;i<=n;i++){
			if(a[i+1]!=0)printf("%d%c",a[i],i!=n?'*':'\n');
			else printf("%d%c",a[i],i!=n?'-':'\n');
		}
		return 0;
	}
	int l=1,r=0;
	for(r=1;r<=n+1;r++){
		if(a[r]==0){
			solve(l,r-1);
			l=r+1;
			sa[r-1]='+';
			sa[r-2]='+';
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d%c",b[i],i!=n?sa[i-1]:'\n');
	}
	return 0;
}