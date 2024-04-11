#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define mp make_pair
const int N=200050;
const int M=2*N;
int id[M],m,ch[M],nod[M];
pair<pair<int,int> ,int > tmp[M];
void BuildSuffixArray()
{
	int i,j;
	for(i=1;i<=m;i++) id[i]=ch[i];
	for(j=0;j<19;j++)
	{
		for(i=1;i<=m;i++) tmp[i]=mp(mp(id[i],id[i+(1<<j)]),i);
		sort(tmp+1,tmp+1+m);
		int cnt=0;
		for(i=1;i<=m;i++)
		{
			id[tmp[i].second]=cnt;
			cnt+=(tmp[i].first!=tmp[i+1].first);
		}
		if(cnt==m) break;
	}
	for(i=1;i<=m;i++) id[i]++;
	for(i=1;i<=m;i++) nod[id[i]]=i;
}
int BIT[M];
void Set(int i){ for(;i<=m;i+=i&-i) BIT[i]++;}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
char str[N];
int l[N],r[N],b[N],e[N];
vector<pair<int,int> > Q[N];
int sol[M*2];
int main()
{
	int n,q,i,j,k;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%s",&str);
		k=strlen(str);
		l[i]=m+1;
		for(j=0;j<k;j++) ch[++m]=str[j]-'a';
		ch[++m]=25+i;
		r[i]=m-1;
	}
	BuildSuffixArray();
	for(i=1;i<=n;i++)
	{
		int L=1,R=m;
		for(j=l[i];j<=r[i];j++)
		{
			int len=j-l[i]+1;
			int L1=L;
			int top=R,bot=L,mid;
			while(top>=bot)
			{
				mid=top+bot>>1;
				if(ch[j]<=ch[nod[mid]+len-1]) top=mid-1,L1=mid;
				else bot=mid+1;
			}
			int R1=R+1;
			top=R+1;bot=L;
			while(top>=bot)
			{
				mid=top+bot>>1;
				if(ch[j]+1<=ch[nod[mid]+len-1]) top=mid-1,R1=mid;
				else bot=mid+1;
			}
			R1--;
			L=L1;
			R=R1;
		}
		b[i]=L;
		e[i]=R;
	}
	for(i=1;i<=q;i++)
	{
		int L,R;
		scanf("%i %i %i",&L,&R,&k);
		Q[L-1].push_back(mp(k,-i));
		Q[R].push_back(mp(k,i));
	}
	for(i=1;i<=n;i++)
	{
		for(j=l[i];j<=r[i];j++) Set(id[j]);
		for(j=0;j<Q[i].size();j++)
		{
			k=Q[i][j].first;
			int taj=Q[i][j].second;
			if(taj<0) taj=-taj,sol[taj]-=Get(e[k])-Get(b[k]-1);
			else sol[taj]+=Get(e[k])-Get(b[k]-1);
		}
	}
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	return 0;
}