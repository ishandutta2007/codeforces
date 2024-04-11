#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define getii(x,y) geti(x),geti(y)
#define geti(x) x=getnum()
inline int getnum()
{
    register int r=0;register bool ng=0;register char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')ng=1,c=getchar();
    while(c!=' '&&c!='\n')r=(r<<1)+(r<<3)+c-'0',c=getchar();
    if(ng)r=-r;return r;
}
const int N=100050;
const int M=26*2*N;
const int H=1<<17;
//int root[26],tsz,ls[M],rs[M],sum[M],lzy[M];
int sum[H<<1][26],lzy[H<<1][26];
char s[N];
void Build(int c, int ss, int se, char a, int id)
{
	if(ss==se){ sum[c][id]=s[ss]==a;return;}
	int mid=ss+se>>1;
	Build(c<<1,ss,mid,a,id);
	Build(c<<1|1,mid+1,se,a,id);
	sum[c][id]=sum[c<<1][id]+sum[c<<1|1][id];
}
void Push(int c, int ss, int se, int id)
{
	if(!lzy[c][id]) return;
	if(ss!=se)
	{
		int mid=ss+se>>1;
		lzy[c<<1][id]=lzy[c<<1|1][id]=lzy[c][id];
		if(lzy[c][id]==1) sum[c<<1][id]=mid-ss+1,sum[c<<1|1][id]=se-mid;
		if(lzy[c][id]==2) sum[c<<1][id]=sum[c<<1|1][id]=0;
	}
	lzy[c][id]=0;
}
void Set(int c, int ss, int se, int qs, int qe, int t, int id)
{
	if(qs>qe) return;
	if(qs<=ss && qe>=se)
	{
		lzy[c][id]=t;
		if(t==1) sum[c][id]=se-ss+1;
		if(t==2) sum[c][id]=0;
		return;
	}
	int mid=ss+se>>1;
	Push(c,ss,se,id);
	if(qs<=mid) Set(c<<1,ss,mid,qs,qe,t,id);
	if(qe>mid) Set(c<<1|1,mid+1,se,qs,qe,t,id);
	sum[c][id]=sum[c<<1][id]+sum[c<<1|1][id];
}
int Get(int c, int ss, int se, int qs, int qe, int id)
{
	if(qs<=ss && qe>=se) return sum[c][id];
	int mid=ss+se>>1;
	Push(c,ss,se,id);
	if(qe<=mid) return Get(c<<1,ss,mid,qs,qe,id);
	if(qs>mid) return Get(c<<1|1,mid+1,se,qs,qe,id);
	return Get(c<<1,ss,mid,qs,qe,id)+Get(c<<1|1,mid+1,se,qs,qe,id);
}
int cnt[26];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,q,i,l,r,j;
	scanf("%i %i",&n,&q);
	//getii(n,q);
	scanf("%s",s+1);
	//for(i=1;i<=n;i++) s[i]=getchar();
	for(i=0;i<26;i++) Build(1,0,H-1,'a'+i,i);
	while(q--)
	{
		scanf("%i %i",&l,&r);
		//getii(l,r);
		int L=l,R=r;
		int odd=-1;
		bool ok=1;
		for(i=0;i<26;i++)
		{
			cnt[i]=Get(1,0,H-1,l,r,i);
			if(cnt[i]&1)
			{
				if(~odd) ok=0;
				odd=i;
			}
		}
		if(ok)
		{
			for(i=0;i<26;i++)
			{
				int add=cnt[i]/2;
				Set(1,0,H-1,L,R,2,i);
				Set(1,0,H-1,l,l+add-1,1,i);
				Set(1,0,H-1,r-add+1,r,1,i);
				l+=add;
				r-=add;
			}
			if(~odd) Set(1,0,H-1,l,r,1,odd);
		}
	}
	vector<char> sol;
	int ssz=0;
	for(i=1;i<=n;i++)
	{
		int tmp=0;
		for(j=0;j<26;j++)
		{
			if(Get(1,0,H-1,i,i,j)) s[++ssz]='a'+j/*putchar('a'+j)*/,tmp++;
		}
		if(tmp!=1) printf("???\n");
	}
	s[++ssz]=0;
	printf("%s",s+1);
	//for(i=0;i<sol.size();i++) printf("%c",sol[i]);
	printf("\n");
	return 0;
}