#include<bits/stdc++.h>
using namespace std;
const int N=100005;
inline int read()
{
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=(s<<1)+(s<<3)+ch-'0',ch=getchar();
   return s*w;
}
map<long long,int>s;
long long a[N];
int main()
{
	int n,k;
	long long sum=0,ans=0;
	s[0]=1;
	n=read(),k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		s[sum]++;
		long long kk=1;
		do
		{
			if(s.find(sum-kk)!=s.end())
				ans+=s[sum-kk];
			if(k==1||kk==-1)
				break;
			kk*=k; 
		}while(kk<=1e14);
	}
	cout<<ans<<endl;
	return 0;
}