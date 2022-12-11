#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN=1000000+10;
vector <int> Lower[MAXN],Upper[MAXN];
long long ans;
int n,k,m;
struct HSINI
{
	int L,R,c,p;
}A[MAXN];

namespace Istream
{
	char get_char()
	{
		static char *C,*mempool;
		const int L=1<<20;
		static char buffer[L];
		if(C==mempool) mempool=(C=buffer)+fread(buffer,1,L,stdin);
		if(C==mempool) return EOF;
		return *C++;
	}
	int get_int()
	{
		int re=0;
		char c;
		do(c=get_char()); while(c<'0' || c>'9');
		while(c>='0' && c<='9')
		{
			re=(re<<1)+(re<<3)+c-'0';
			c=get_char();
		}
		return re;
	}
}
using namespace Istream;
struct Node
{
    Node *lc,*rc;
    int l,r;
    long long cnt,sum;
    
    void Push_up()
    {
        sum=lc->sum+rc->sum;
        cnt=lc->cnt+rc->cnt;
    } 
    
    void build(int L,int R)
    {
        l=L;r=R;
        if(l==r)
        {
            sum=0;cnt=0;
            return;
        }
        int mid=l+r>>1;
        (lc=new Node)->build(L,mid);
        (rc=new Node)->build(mid+1,R);
        Push_up();
    }
    void add(int pos,long long v)
    {
        if(l==r)
        {
            cnt+=v;
            sum+=l*v;
            return;
        }
        int mid=l+r>>1;
        if(pos<=mid) lc->add(pos,v);
        else if(pos>mid) rc->add(pos,v);
        Push_up();
    }
    long long Query_sum(int L,int R)
    {
        if(l==L && R==r) return sum;
        int mid=l+r>>1;
        long long ans=0;
        if(R<=mid) ans=lc->Query_sum(L,R);
        else if(L>mid) ans=rc->Query_sum(L,R);
        else ans=lc->Query_sum(L,mid)+rc->Query_sum(mid+1,R); 
        Push_up();
        return ans;
    }
    long long Query_cnt(int L,int R)
    {
    	if(L>R) return 0;
        if(l==L && R==r) return cnt;
        int mid=l+r>>1;
        long long ans=0;
        if(R<=mid) ans=lc->Query_cnt(L,R);
        else if(L>mid) ans=rc->Query_cnt(L,R);
        else ans=lc->Query_cnt(L,mid)+rc->Query_cnt(mid+1,R); 
        Push_up();
        return ans;
    }
}*root=new Node;

int Biselect(int L,int R)
{
	if(root->Query_cnt(L,R)<k) return R;
	int re=~0u>>1;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(root->Query_cnt(1,mid)>=k) re=min(re,mid),R=mid-1;
		else L=mid+1;
	}
	return re;
}
int SZ;
main()
{
	//scanf("%d%d%d",&n,&k,&m);
	n=get_int();k=get_int();m=get_int();
	for(int i=1;i<=m;i++)
	{
		//scanf("%d%d%d%d",&A[i].L,&A[i].R,&A[i].c,&A[i].p);
		A[i].L=get_int();A[i].R=get_int();A[i].c=get_int();A[i].p=get_int();
		Lower[A[i].L].push_back(i);
		Upper[A[i].R].push_back(i);
		SZ=max(SZ,A[i].p);
	}
	root->build(1,SZ);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<Lower[i].size();j++)
			root->add(A[Lower[i][j]].p,A[Lower[i][j]].c);
		for(int j=0;j<Upper[i-1].size();j++)
			root->add(A[Upper[i-1][j]].p,-A[Upper[i-1][j]].c);
		int cur=Biselect(1,SZ);
		long long last=0;
		if(root->Query_cnt(1,cur)>k)
		{
			last=k-(cur>1 ? root->Query_cnt(1,cur-1) : 0);
			--cur;
		}
		ans+=(cur ? root->Query_sum(1,cur) : 0)+last*(cur+1);
	}
	printf("%I64d",ans);
	return 0;
}