#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 LL;
const LL MX=100;
// max ans 50
struct Edge
{
	LL st;
	int ne;
}e[10000000];
const int KA=69;
const int mod=1000007;
int has[mod+10],p[mod+10],K;
int top,tail;
LL q[2100000];
const int V=2000000;
int L,E,F,walk,reng,be;
void decode(LL st)
{
	be=(int)(st%MX);
	st/=MX;
	reng=(int)(st%MX);
	st/=MX;
	walk=(int)(st%MX);
	st/=MX;
	F=(int)(st%MX);
	st/=MX;
	E=(int)(st%MX);
	st/=MX;
	L=(int)(st%MX);
	st/=MX;
}
bool find(LL st)
{
	int re=(int)(st%(LL)mod);
	if(has[re])
	{
		for(int i=p[re];i!=-1;i=e[i].ne)
		{
			if(e[i].st==st)return true;
		}
	}
	has[re]=1;
	e[K].st=st;e[K].ne=p[re];p[re]=K++;
	return false;
}
void init()
{
	memset(has,0,sizeof(has));
	memset(p,-1,sizeof(p));K=0;
}
LL code(int L,int E,int F,int walk,int reng,int be)
{
	LL ret=0;
	ret+=L;
	ret*=MX;
	ret+=E;
	ret*=MX;
	ret+=F;
	ret*=MX;
	ret+=walk;
	ret*=MX;
	ret+=reng;
	ret*=MX;
	ret+=be;
	return ret;
}
int AB(int x){if(x<0)return -x;return x;}
int po[120],d[120],t[120];
LL st;
int ans,i,TL,TE,TF;
int main()
{
	while(~scanf("%d%d%d",&po[0],&d[0],&t[0]))
	{
		init();
		for(i=1;i<3;i++)
		scanf("%d%d%d",&po[i],&d[i],&t[i]);
		for(i=0;i<3;i++)po[i]+=50;
		st=code(po[0],po[1],po[2],0,0,0);
		top=0;tail=1;q[1]=st;
		if(find(st))break;
		ans=-1;
		while(top<tail)
		{
			top=(top+1)%V;
			decode(q[top]);
			ans=max(ans,L);
			ans=max(ans,E);
			ans=max(ans,F);
			TL=reng%3;
			TE=reng/3%3;
			TF=reng/9%3;
			if(TL!=1&&!(walk&1)&&!(be&1))
			{
				for(i=-d[0];i<=d[0];i++)
				{
					if(L+i==E||L+i==F)continue;
					st=code(L+i,E,F,walk|1,reng,be);
					if(!find(st))q[(++tail)%V]=st;
				}
			}
			if(TE!=1&&!(walk&2)&&!(be&2))
			{
				for(i=-d[1];i<=d[1];i++)
				{
					if(E+i==L||E+i==F)continue;
					st=code(L,E+i,F,walk|2,reng,be);
				//	if(top==KA)printf("%d %d %d   ",i,E+i,tail);
					if(!find(st))q[(++tail)%V]=st;
				}
			}		
			if(TF!=1&&!(walk&4)&&!(be&4))
			{
				for(i=-d[2];i<=d[2];i++)
				{
					if(F+i==L||F+i==E)continue;
					st=code(L,E,F+i,walk|4,reng,be);
					if(!find(st))q[(++tail)%V]=st;
				}
			}
			if(!(be&1))
			{
				if(TL==0)
				{
					if(AB(L-E)==1&&!(be&2))
					{
						if(E==F)st=code(L,L,L,walk,reng+1,be|2);
						else st=code(L,L,F,walk,reng+1,be|2);
						if(!find(st))q[(++tail)%V]=st;
					}
					if(AB(L-F)==1&&!(be&4))
					{
						if(E==F)st=code(L,L,L,walk,reng+1,be|4);
						else st=code(L,E,L,walk,reng+1,be|4);
						if(!find(st))q[(++tail)%V]=st;
					}
				}
				if(TL==1)
				{
					for(i=-t[0];i<=t[0];i++)
					{
						if(i==0)continue;
						if(E==L&&F==L)
						{
							if(TE==1)st=code(L,L+i,L+i,walk,reng+1,be^2);
							else st=code(L,L+i,L+i,walk,reng+1,be^4);
							if(!find(st))q[(++tail)%V]=st;
						}
						else if(E==L)
						{
							if(L+i!=F)
							{
								st=code(L,L+i,F,walk,reng+1,be^2);
								if(!find(st))q[(++tail)%V]=st;
							}
						}
						else
						{
							if(L+i!=E)
							{
								st=code(L,E,L+i,walk,reng+1,be^4);
								if(!find(st))q[(++tail)%V]=st;
							}
						}
					}
				}
			}
			if(!(be&2))
			{
				if(TE==0)
				{
					if(AB(L-E)==1&&!(be&1))
					{
						if(L==F)st=code(E,E,E,walk,reng+3,be|1);
						else st=code(E,E,F,walk,reng+3,be|1);
						if(!find(st))q[(++tail)%V]=st;
					}
					if(AB(E-F)==1&&!(be&4))
					{
						if(L==F)st=code(E,E,E,walk,reng+3,be|4);
						else st=code(L,E,E,walk,reng+3,be|4);
						if(!find(st))q[(++tail)%V]=st;
					}
				}
				if(TE==1)
				{
					for(i=-t[1];i<=t[1];i++)
					{
						if(i==0)continue;
						if(E==L&&F==L)
						{
							if(TL==1)st=code(E+i,E,E+i,walk,reng+3,be^1);
							else st=code(E+i,E,E+i,walk,reng+3,be^4);
							if(!find(st))q[(++tail)%V]=st;
						}
						else if(E==L)
						{
							if(E+i!=F)
							{
								st=code(E+i,E,F,walk,reng+3,be^1);
								if(!find(st))q[(++tail)%V]=st;
							}
						}
						else
						{
							if(E+i!=L)
							{
								st=code(L,E,E+i,walk,reng+3,be^4);
								if(!find(st))q[(++tail)%V]=st;
							}
						}
					}
				}
			}
			if(!(be&4))
			{
				if(TF==0)
				{
					if(AB(L-F)==1&&!(be&1))
					{
						if(L==E)st=code(E,E,F,walk,reng+9,be|1);
						else st=code(F,E,F,walk,reng+9,be|1);
						if(!find(st))q[(++tail)%V]=st;
					}
					if(AB(E-F)==1&&!(be&2))
					{
						if(L==E)st=code(F,F,F,walk,reng+9,be|2);
						else st=code(L,F,F,walk,reng+9,be|2);
						if(!find(st))q[(++tail)%V]=st;
					}
				}
				if(TF==1)
				{
					for(i=-t[2];i<=t[2];i++)
					{
						if(i==0)continue;
						if(E==L&&F==L)
						{
							if(TL==1)st=code(F+i,F+i,F,walk,reng+9,be^1);
							else st=code(F+i,F+i,F,walk,reng+9,be^2);
							if(!find(st))q[(++tail)%V]=st;
						}
						else if(F==L)
						{
							if(F+i!=E)
							{
								st=code(F+i,E,F,walk,reng+9,be^1);
								if(!find(st))q[(++tail)%V]=st;
							}
						}
						else
						{
							if(F+i!=L)
							{
								st=code(L,F+i,F,walk,reng+9,be^2);
								if(!find(st))q[(++tail)%V]=st;
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans-50);
	}
}