#include <stdio.h>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define ll long long
set< pair<int,int> > Set;
//vector< pair<int,int> > v;
struct Node
{
	int first,second,index;
	Node(){}
	Node(int a, int b, int c)
	{
		first=a;
		second=b;
		index=c;
	}
	bool operator < (Node b) const
	{
		if(first==b.first && second==b.second) return index<b.index;
		if(first==b.first) return second<b.second;
		return first<b.first;
	}
};
vector<Node> e,v;
const int N=200050;
int BIT[N];
void SetF(int i, int f){ for(;i<N;i+=i&-i) BIT[i]+=f;}
int GetF(int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
ll BIT1[N];
void SetB(int i, ll f)
{
	for(;i<N;i+=i&-i) BIT1[i]+=f;
}
ll GetB(int i){ ll ret=0;for(;i;i-=i&-i) ret+=BIT1[i];return ret;}
int sol=0;
map<pair<int,int> ,int> index;
int main()
{
	int n,t,i,x,y;
	scanf("%i %i",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&x,&y);
		v.push_back(Node(x,y,i));
		e.push_back(Node(y,x,i));
		//index
	}
	for(i=1;i<=n;i++) SetF(i,1);
	sort(v.begin(),v.end());
	sort(e.begin(),e.end());
	for(i=1;i<=n;i++) SetB(i,e[i-1].first);
	int j=0;
	for(i=1;i<=n;i++)
	{
		int top=n;
		int bot=1;
		int ans=0,mid;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(GetF(mid)<=i) ans=mid,bot=mid+1;
			else top=mid-1;
		}
		//printf("%i\n",ans);
		if(GetF(ans)<i) break;
		if(GetB(ans)<=t) sol=i;
		else break;
		for(;v[j].first==i && j<n;j++)
		{
			int id=lower_bound(e.begin(),e.end(),Node(v[j].second,v[j].first,v[j].index))-e.begin();
			SetF(id+1,-1);
			SetB(id+1,-e[id].first);
		}
	}
	printf("%i\n",sol);
	printf("%i\n",sol);
	int cnt=0;
	for(i=0;i<e.size();i++)
	{
		if(cnt==sol) break;
		if(e[i].second>=sol)
		{
			printf("%i ",e[i].index);
			cnt++;
		}
		
	}
	return 0;
}