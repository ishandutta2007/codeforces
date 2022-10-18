#include<bits/stdc++.h>
using namespace std;
#define get wdsaoihfe
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 200005
string a;
string b;
int get[30][N];
int sum[30];
int tmp[30];
int main()
{
	int n;
	cin>>n;
	cin>>a;
	for(int i=0;i<n;i++)
	{
		sum[a[i]-'a'+1]++;
		get[a[i]-'a'+1][sum[a[i]-'a'+1]]=i;
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>b;
		int k=b.length();
		memset(tmp,0,sizeof(tmp));
		int ans=0;
		for(int j=0;j<k;j++)
		{
			tmp[b[j]-'a'+1]++;
		}
//		for(int j=1;j<=26;j++)
//		{
//			printf("%d ",tmp[j]);
//		}
//		cout<<"\n";
		for(int j=1;j<=26;j++)
		{
			ans=max(ans,get[j][tmp[j]]);
		}
		cout<<ans+1<<endl;
	}
	return 0;
}