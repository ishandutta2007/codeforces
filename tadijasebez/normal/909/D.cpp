#include <stdio.h>
#include <set>
#include <cstring>
using namespace std;
struct Seg
{
	int l,r,sz;
	char t;
	Seg(){}
	Seg(int a, int b, int c, char d){ l=a,r=b,sz=c,t=d;}
	bool operator < (Seg b) const
	{
		return l<b.l;
	}
};
set<Seg> Set;
set<Seg>::iterator it,it1;
const int N=1000050;
char ch[N],taj;
int sz;
int main()
{
	scanf("%s",ch);
	int n=strlen(ch);
	int i;
	sz=0;taj='$';
	for(i=0;i<n;i++)
	{
		if(ch[i]==taj)
		{
			sz++;
		}
		else
		{
			if(sz) Set.insert(Seg(i-sz,i-1,sz,taj));
			sz=1;
			taj=ch[i];
		}
	}
	if(sz) Set.insert(Seg(i-sz,i-1,sz,taj));
	int sol=0;
	while(Set.size()>1)
	{
		sol++;
		//printf("%i\n",Set.size());
		bool first=1;
		for(it=Set.begin();it!=Set.end();)
		{
			Seg tmp=*it; it1=it; it1++;
			if((it==Set.begin() && first) || it1==Set.end())
			{
				it++;
				Set.erase(tmp);
				tmp.sz--;
				if(tmp.sz>0) Set.insert(tmp);
				first=0;
			}
			else
			{
				it++;
				Set.erase(tmp);
				tmp.sz-=2;
				if(tmp.sz>0) Set.insert(tmp);
			}
		}
		//printf(":D");
		for(it=Set.begin();it!=Set.end();)
		{
			Seg tmp=*it; it1=it; it1++; it++;
			if(it1!=Set.end())
			{
				it++;
				Seg tmp1=*it1;
				if(tmp.t==tmp1.t)
				{
					Set.erase(tmp);
					Set.erase(tmp1);
					Set.insert(Seg(tmp.l,tmp1.r,tmp.sz+tmp1.sz,tmp.t));
				}
				it--;
			}
		}
	}
	printf("%i\n",sol);
	return 0;
}