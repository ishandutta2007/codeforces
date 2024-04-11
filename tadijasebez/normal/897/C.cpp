#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
#define ll long long
const int N=100050;
const ll inf=2e18+69;
ll l1[N],r1[N],l2[N],r2[N],l3[N],r3[N];
string First,Second,Third,World;
void BuildStrings()
{
	First="What are you doing while sending #";
	Second="#? Are you busy? Will you send #";
	Third="#?";
	World="What are you doing at the end of the world? Are you busy? Will you save us?";
}
vector<char> out;
ll min(ll a, ll b){ return a>b?b:a;}
int main()
{
	int q,n,i;
	ll k;
	BuildStrings();
	l1[0]=1;
	r1[0]=World.size();
	l2[0]=World.size();
	r2[0]=World.size();
	l3[0]=World.size();
	r3[0]=World.size();
	for(i=1;i<N;i++)
	{
		l1[i]=1;
		r1[i]=First.size();
		l2[i]=min(inf,r1[i]+r3[i-1]+1);
		r2[i]=min(inf,l2[i]+Second.size()-1);
		l3[i]=min(inf,r2[i]+r3[i-1]+1);
		r3[i]=min(inf,l3[i]+Third.size()-1);
	}
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %lld",&n,&k);
		if(r3[n]<k)
		{
			out.push_back('.');
			continue;
		}
		while(n>0)
		{
			if(k<=r1[n])
			{
				out.push_back(First[k-1]);
				break;
			}
			if(k>=l2[n] && k<=r2[n])
			{
				out.push_back(Second[k-l2[n]]);
				break;
			}
			if(k>=l3[n] && k<=r3[n])
			{
				out.push_back(Third[k-l3[n]]);
				break;
			}
			if(k<l2[n]) k-=r1[n];
			else if(k<l3[n]) k-=r2[n];
			n--;
		}
		if(n>0) continue;
		out.push_back(World[k-1]);
	}
	for(i=0;i<out.size();i++)
	{
		char chh=out[i];
		if(chh=='#') chh='"';
		printf("%c",chh);
	}
	return 0;
}