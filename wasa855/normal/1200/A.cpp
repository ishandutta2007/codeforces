#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
int a[15];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	string x;
	cin>>x;
	for(int i=0;i<n;i++)
	{
		if(x[i]=='L')
		{
			int j=0;
			while(a[j]!=0) j++;
			a[j]=1;
		}
		else if(x[i]=='R')
		{
			int j=9;
			while(a[j]!=0) j--;
			a[j]=1;
		}
		else
		{
			a[x[i]-'0']=0;
		}
	}
	for(int i=0;i<=9;i++) cout<<a[i];
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
 
 //sac