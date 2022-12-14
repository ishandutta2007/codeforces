#include<cstdio>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

map<int,vector<P> > vert,horz;

map<int,int> vcut,hcut;

vector<int> cs;

int main()
{
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<K;i++)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2)
		{
			if(y1>y2) swap(y1,y2);
			vert[x1].push_back(P(y1,1));
			vert[x1].push_back(P(y2,-1));
		}
		else
		{
			if(x1>x2) swap(x1,x2);
			horz[y1].push_back(P(x1,1));
			horz[y2].push_back(P(x2,-1));
		}
	}
	map<int,vector<P> >::iterator it;
	for(it=vert.begin();it!=vert.end();it++)
	{
		vector<P> &vec=it->second;
		sort(vec.begin(),vec.end());
		int in=0,a=0,prev=0;
		for(int i=0;i<vec.size();i++)
		{
			int c=vec[i].first,which=vec[i].second;
			if(in>0) a+=(c-prev);
			prev=c;
			in+=which;
		}
		vcut[it->first]=a;
	}
	for(it=horz.begin();it!=horz.end();it++)
	{
		vector<P> &vec=it->second;
		sort(vec.begin(),vec.end());
		int in=0,a=0,prev=0;
		for(int i=0;i<vec.size();i++)
		{
			int c=vec[i].first,which=vec[i].second;
			if(in>0) a+=(c-prev);
			prev=c;
			in+=which;
		}
		hcut[it->first]=a;
	}
	int gr=0;
	map<int,int>::iterator it2;
	for(it2=vcut.begin();it2!=vcut.end();it2++)
	{
		gr^=(M-(it2->second));
	}
	for(it2=hcut.begin();it2!=hcut.end();it2++)
	{
		gr^=(N-(it2->second));
	}
	if(((N-1)-vcut.size())%2==1) gr^=M;
	if(((M-1)-hcut.size())%2==1) gr^=N;
	if(gr==0)
	{
		printf("SECOND\n");
		return 0;
	}
	printf("FIRST\n");
	for(it2=vcut.begin();it2!=vcut.end();it2++)
	{
		int tmp=gr^(M-(it2->second));
		if(tmp<=(M-(it2->second)))
		{
			int req=M-(it2->second)-tmp;
			vector<P> &vec=vert[it2->first];
			int a=0,prev=0,in=0;
			int ans=-1;
			for(int i=0;i<vec.size();i++)
			{
				int c=vec[i].first,which=vec[i].second;
				if(in>0) a+=(c-prev);
				prev=c;
				in+=which;
				int aa=c-a;
				if(aa>=req)
				{
					ans=c-(aa-req);
					break;
				}
			}
			if(ans==-1) ans=M-tmp;
			printf("%d %d %d %d\n",it2->first,0,it2->first,ans);
			return 0;
		}
	}
	for(it2=hcut.begin();it2!=hcut.end();it2++)
	{
		int tmp=gr^(N-(it2->second));
		if(tmp<=(N-(it2->second)))
		{
			int req=N-(it2->second)-tmp;
			vector<P> &vec=horz[it2->first];
			int a=0,prev=0,in=0;
			int ans=-1;
			for(int i=0;i<vec.size();i++)
			{
				int c=vec[i].first,which=vec[i].second;
				if(in>0) a+=(c-prev);
				prev=c;
				in+=which;
				int aa=c-a;
				if(aa>=req)
				{
					ans=c-(aa-req);
					break;
				}
			}
			if(ans==-1) ans=N-tmp;
			printf("%d %d %d %d\n",0,it2->first,ans,it2->first);
			return 0;
		}
	}
	if(vcut.size()<N-1)
	{
		int tmp=gr^M;
		int tocut=M-tmp;
		if(tmp>M) goto nxt;
		for(it2=vcut.begin();it2!=vcut.end();it2++)
		{
			cs.push_back(it2->first);
		}
		int x=-1;
		if(cs.size()==0)
		{
			x=1;
			goto output;
		}
		if(cs[0]>1)
		{
			x=1;
			goto output;
		}
		for(int i=1;i<cs.size();i++)
		{
			if(cs[i-1]!=cs[i]-1)
			{
				x=cs[i]-1;
				break;
			}
		}
		if(x==-1)
		{
			x=N-1;
		}
		output:;
		printf("%d %d %d %d\n",x,0,x,tocut);
		return 0;
	}
	nxt:;
	if(hcut.size()<M-1)
	{
		cs.clear();
		int tmp=gr^N;
		int tocut=N-tmp;
		for(it2=hcut.begin();it2!=hcut.end();it2++)
		{
			cs.push_back(it2->first);
		}
		int y=-1;
		if(cs.size()==0)
		{
			y=1;
			goto output2;
		}
		if(cs[0]>1)
		{
			y=1;
			goto output2;
		}
		for(int i=0;i<cs.size();i++)
		{
			if(cs[i-1]!=cs[i]-1)
			{
				y=cs[i]-1;
				break;
			}
		}
		if(y==-1) y=M-1;
		output2:;
		printf("%d %d %d %d\n",0,y,tocut,y);
	}
	return 0;
}