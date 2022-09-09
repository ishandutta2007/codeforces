#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
struct seg
{
	int l,r;
	char c;
	seg(){}
	seg(int _l, int _r, char _c):l(_l),r(_r),c(_c){}
	bool operator < (seg b) const { return mp(l,r)<mp(b.l,b.r);}
};
set<seg> all;
void Split(int x)
{
	auto it=all.lower_bound(seg(x,0,0));
	if(it==all.begin()) return;
	it--;
	if(it->r<x) return;
	int l=it->l,r=it->r;
	char c=it->c;
	all.erase(it);
	all.insert(seg(l,x-1,c));
	all.insert(seg(x,r,c));
}
const int K=10;
const int N=200050;
int cnt[K][K];
void modify(seg x, bool del)
{
	if(!del) all.insert(x);
	auto it=all.find(x);
	char c1=it->c;
	int l=it->l,r=it->r;
	cnt[c1-'a'][c1-'a']+=(r-l)*(del?-1:1);
	if(it!=all.begin()) it--,cnt[it->c-'a'][c1-'a']+=(del?-1:1)*(it->r==l-1),it++;
	it++;if(it!=all.end()) cnt[c1-'a'][it->c-'a']+=(del?-1:1)*(it->l==r+1);it--;
	if(del) all.erase(x);
}
char s[N],tmp[20];
int id[K];
int main()
{
	int n,m,k,i,j;
	scanf("%i %i %i",&n,&m,&k);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) modify(seg(i,i,s[i]),0);
	//for(i=0;i<k;i++) for(j=0;j<k;j++) printf("(%c %c) %i\n",'a'+i,'a'+j,cnt[i][j]);
	while(m--)
	{
		int t;
		scanf("%i",&t);
		if(t==1)
		{
			int l,r;char c;
			scanf("%i %i %c",&l,&r,&c);
			Split(l);Split(r+1);
			auto itl=all.lower_bound(seg(l,0,0));
			auto itr=all.lower_bound(seg(r+1,0,0));
			for(auto it=itl;it!=itr;)
			{
				seg tmp=*it;it++;
				modify(tmp,1);
				//printf("seg %i %i %c\n",tmp.l,tmp.r,tmp.c);
			}
			modify(seg(l,r,c),0);
		}
		else
		{
			scanf("%s",tmp);
			for(i=0;i<k;i++) id[tmp[i]-'a']=i;
			int ans=1;
			for(i=0;i<k;i++) for(j=0;j<k;j++) if(id[i]>=id[j]) ans+=cnt[i][j];
			printf("%i\n",ans);
		}
		//for(i=0;i<k;i++) for(j=0;j<k;j++) printf("(%c %c) %i\n",'a'+i,'a'+j,cnt[i][j]);
	}
	return 0;
}