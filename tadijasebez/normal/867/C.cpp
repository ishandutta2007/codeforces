#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> white,black;
const int N=100050;
long long ans,tmp,naj,WDP[N],BDP[N],lose1[N],lose2[N],sum1,sum2,sol,a[N],b[N],s[N],sum,x,i1[2],j1[2],i,j,need,ost;
long long max(long long a, long long b){ return a>b?a:b;}
bool WhiteCompare(int i, int j)
{
	if(a[i]-b[i]<a[j]-b[j]) return true;
	return false;
}
bool BlackCompare(int i, int j)
{
	if(b[i]-a[i]<b[j]-a[j]) return true;
	return false;
}
int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld %lld",&s[i],&a[i],&b[i]);
		sum+=s[i];
		if(a[i]>b[i]) white.push_back(i),naj+=s[i]*a[i];
		if(a[i]<b[i]) black.push_back(i),naj+=s[i]*b[i];
		if(a[i]==b[i]) tmp+=s[i]*a[i];
	}
	sort(white.begin(),white.end(),WhiteCompare);
	if(!white.empty())
	{
		WDP[0]=s[white[0]];
		for(i=1;i<white.size();i++) WDP[i]=WDP[i-1]+s[white[i]];
		lose1[0]=s[white[0]]*(a[white[0]]-b[white[0]]);
		for(i=1;i<white.size();i++) lose1[i]=lose1[i-1]+(s[white[i]]*(a[white[i]]-b[white[i]]));
		sum1=WDP[white.size()-1];
	}
	sort(black.begin(),black.end(),BlackCompare);
	if(!black.empty())
	{
		BDP[0]=s[black[0]];
		for(i=1;i<black.size();i++) BDP[i]=BDP[i-1]+s[black[i]];
		lose2[0]=s[black[0]]*(b[black[0]]-a[black[0]]);
		for(i=1;i<black.size();i++) lose2[i]=lose2[i-1]+(s[black[i]]*(b[black[i]]-a[black[i]]));
		sum2=BDP[black.size()-1];
	}
	x=(sum+k-1)/k;
	int top,bot,mid;
	i1[0]=(sum1+k-1)/k;
	j1[0]=x-i1[0];
	j1[1]=(sum2+k-1)/k;
	i1[1]=x-j1[1];
	int loop;
	for(loop=0;loop<2;loop++)
	{
		ans=naj;
		i=i1[loop];
		j=j1[loop];
		//j=x-i;
		if(i*k>=sum1 && j*k<sum2)
		{
			need=sum2-j*k;
			top=black.size()-1;
			bot=0;
			while(top>bot)
			{
				mid=top+bot>>1;
				if(BDP[mid]<need) bot=mid+1;
				else top=mid;
			}
			ans-=lose2[top];
			ost=BDP[top]-need;
			ans+=ost*(b[black[top]]-a[black[top]]);
		}
		else if(i*k<sum1 && j*k>=sum2)
		{
			need=sum1-i*k;
			top=white.size()-1;
			bot=0;
			while(top>bot)
			{
				mid=top+bot>>1;
				if(WDP[mid]<need) bot=mid+1;
				else top=mid;
			}
			ans-=lose1[top];
			ost=WDP[top]-need;
			ans+=ost*(a[white[top]]-b[white[top]]);
		}
		sol=max(sol,ans);
	}
	printf("%lld\n",sol+tmp);
	return 0;
}