#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 1000005
char s[N];
char a[N];
char r;
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%s",s+1);
	int n=strlen(s+1);
	int l=1,r=n;
	int siz=0;
	while(r-l>=3)
	{
		if(s[l]==s[r]) a[++siz]=s[l];
		else if(s[l]==s[r-1]) a[++siz]=s[l];
		else if(s[l+1]==s[r]) a[++siz]=s[l+1];
		else if(s[l+1]==s[r-1]) a[++siz]=s[l+1];
		l+=2;r-=2;
	}
	for(int i=1;i<=siz;i++)
	{
		printf("%c",a[i]);
	}
	if(r>=l) cout<<s[l];
	for(int i=siz;i>0;i--)
	{
		printf("%c",a[i]);
	}
	cout<<"\n";
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}