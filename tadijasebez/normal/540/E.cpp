#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int N=200050;
map<int,int> Map;
map<int,int>::iterator it;
vector<int> Moved,index;
int BIT[2][N];
void Set(int j, int i, int f){ for(;i<N;i+=i&-i) BIT[j][i]+=f;}
int Get(int j, int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[j][i];return ret;}
int main()
{
	int n,a,b,i;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i %i",&a,&b);
		if(!Map[a]) Map[a]=a,Moved.push_back(a);
		if(!Map[b]) Map[b]=b,Moved.push_back(b);
		int tmp=Map[a];
		Map[a]=Map[b];
		Map[b]=tmp;
	}
	sort(Moved.begin(),Moved.end());
	for(it=Map.begin();it!=Map.end();it++)
	{
		index.push_back(it->second);
		//Set(0,lower_bound(Moved.begin(),Moved.end(),it->second)-Moved.begin()+1,1);
	}
	ll sol=0;
	for(i=0;i<Moved.size();i++)
	{
		//Set(0,lower_bound(Moved.begin(),Moved.end(),Map[Moved[i]])-Moved.begin()+1,-1);
		ll ans=0;
		if(Moved[i]>Map[Moved[i]])
		{
			ans=Moved[i]-Map[Moved[i]]-1;
			int l=lower_bound(Moved.begin(),Moved.end(),Map[Moved[i]])-Moved.begin();
			ans-=i-l-1;
			//printf("%i ",i-l-1);
		}
		if(Map[Moved[i]]>Moved[i])
		{
			ans=Map[Moved[i]]-Moved[i]-1;
			int l=lower_bound(Moved.begin(),Moved.end(),Map[Moved[i]])-Moved.begin();
			ans-=l-i-1;
			//printf("%i ",l-i-1);
		}
		ans+=Get(1,Moved.size())-Get(1,lower_bound(Moved.begin(),Moved.end(),Map[Moved[i]])-Moved.begin()+1);
		//printf("%i %i ",Moved.size(),lower_bound(Moved.begin(),Moved.end(),Map[Moved[i]])-Moved.begin()+1);
		//printf("%i ",Get(1,Moved.size())-Get(1,lower_bound(Moved.begin(),Moved.end(),Map[Moved[i]])-Moved.begin()+1));
		//printf("%i %i %i\n",Moved[i],Map[Moved[i]],ans);
		sol+=ans;
		Set(1,lower_bound(Moved.begin(),Moved.end(),Map[Moved[i]])-Moved.begin()+1,1);
	}
	printf("%lld\n",sol);
	return 0;
}