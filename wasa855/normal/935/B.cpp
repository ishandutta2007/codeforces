#include<bits/stdc++.h>
using namespace std;
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
int main()
{
	int tx=1,ty=1;
	int n=read();
	char x;
	int dif=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x=='U')
		{
			tx++;
			if(tx>ty&&dif==2)
			{
				ans++;
				dif=1;
			}
			else if(tx<ty&&dif==1)
			{
				ans++;
				dif=2;
			}
			if(dif==0) dif=1;
		}
		if(x=='R')
		{
			ty++;
			if(tx>ty&&dif==2)
			{
				ans++;
				dif=1;
			}
			else if(tx<ty&&dif==1)
			{
				ans++;
				dif=2;
			}
			if(dif==0) dif=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}