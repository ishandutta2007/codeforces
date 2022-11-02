#include<bits/stdc++.h>
using namespace std;
long long a[15],ans;
int n,flag[15],f[15];
char s[15];
int cmp(int x,int y){return a[x]>a[y];}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<10;i++)f[i]=i;
	for (int i=1;i<=n;i++)
	 {
	 	scanf("%s",&s);
	 	int k=1;
	 	for (int j=strlen(s)-1;j>=0;j--)a[s[j]-97]+=k,k*=10;
	 	flag[s[0]-97]=1;
	 }
	sort(f,f+10,cmp);
	ans=1000000000000000;
	for (int i=0;i<=9;i++)
	 if (!flag[i])
	  {
	  	int k=1;long long sum=0;
	  	for (int j=0;j<=9;j++)
	  	 if (i!=f[j])sum+=k*a[f[j]],k++;
	  	ans=min(sum,ans); 
	  }
	printf("%lld",ans);
}