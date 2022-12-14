#include<cstdio>
#include<map>
#include<set>

using namespace std;

struct node{
	int left,right,mid_max;
	node(){}
	node(int a,int b,int c):left(a),right(b),mid_max(c){}
};

struct segtree{
	int N;
	int num;
	node nodes[525000];
	int len[525000];
	int ldis,rdis;
	void init(int N_)
	{
		num=N_;
		ldis=N_,rdis=N_;
		N=1;
		while(N<N_) N*=2;
		for(int i=N;i<N+N_;i++)
		{
			nodes[i]=node(1,1,1);
			len[i]=1;
		}
		for(int i=N+N_;i<=2*N-1;i++)
		{
			nodes[i]=node(0,0,0);
			len[i]=1;
		}
		for(int i=N-1;i>=1;i--)
		{
			len[i]=len[i*2]+len[i*2+1];
		}
		for(int i=N-1;i>=1;i--)
		{
			int l,r,m;
			if(len[i*2]==nodes[i*2].left) l=nodes[i*2].left+nodes[i*2+1].left;
			else l=nodes[i*2].left;
			if(len[i*2+1]==nodes[i*2+1].right) r=nodes[i*2+1].right+nodes[i*2].right;
			else r=nodes[i*2+1].right;
			m=max(max(nodes[i*2].mid_max,nodes[i*2+1].mid_max),nodes[i*2].right+nodes[i*2+1].left);
			nodes[i]=node(l,r,m);
		}
	}
	int getpl(int i,int M,int l,int r)
	{
		//long range is completely in [i]
		//[i]=[l,r)
		if(M==num) return 1;
		if(nodes[i].left>=M) return l;
		if(nodes[i*2].mid_max>=M) return getpl(i*2,M,l,(l+r)/2);
		if(nodes[i*2].right+nodes[i*2+1].left>=M)
		{
			int m=(l+r)/2;
			return m-nodes[i*2].right;
		}
		return getpl(i*2+1,M,(l+r)/2,r);
	}
	int getpl()
	{
		if(nodes[1].mid_max==num) return 1;
		int M=nodes[1].mid_max;
		if(M%2==0) M--;
		return getpl(1,M,0,N);
	}
	int getsz()
	{
		if(nodes[1].mid_max==num) return -1;
		return nodes[1].mid_max;
	}
	void query(int i,bool which)
	{
		//true:occupy,false:unoccupy
		i+=N;
		if(which==true)
		{
			ldis=min(ldis,i-N);
			rdis=min(rdis,N-(i-N)-1);
		}
		if(which==true) nodes[i]=node(0,0,0);
		else nodes[i]=node(1,1,1);
		i/=2;
		while(i>=1)
		{
			int l,r,m;
			if(nodes[i*2].left==len[i*2]) l=nodes[i*2].left+nodes[i*2+1].left;
			else l=nodes[i*2].left;
			if(nodes[i*2+1].right==len[i*2+1]) r=nodes[i*2+1].right+nodes[i*2].right;
			else r=nodes[i*2+1].right;
			m=max(max(nodes[i*2].mid_max,nodes[i*2+1].mid_max),nodes[i*2].right+nodes[i*2+1].left);
			nodes[i]=node(l,r,m);
			i/=2;
		}
	}
	//void print()
	//{
	//	printf("Mlen=%d\n",nodes[1].mid_max);
	//}
};

segtree seg;

map<int,int> pl;

set<int> smallid,largeid;

void decide(int num,int i)
{
	smallid.insert(i);
	largeid.insert(-i);
	pl[num]=i;
	seg.query(i,true);
}

void out(int p)
{
	seg.query(p,false);
	smallid.erase(p);
	largeid.erase(-p);
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	seg.init(N);
	for(int i=0;i<M;i++)
	{
		int type,num;
		scanf("%d%d",&type,&num);
		if(type==1)
		{
			int st=seg.getpl();
			int len=seg.getsz();
			if(len==-1)
			{
				printf("1\n");
				decide(num,0);
				continue;
			}
			int ml=(len-1)/2;
			int sid=*smallid.begin();
			int sl=sid-1;
			int lid=-(*largeid.begin());
			int ll=N-2-lid;
			int plus=(len+1)/2;
			int mres=st+plus-1;
			if(sl>=ml&&sl>=ll)
			{
				decide(num,0);
				printf("1\n");
			}
			else if(ml>=ll)
			{
				decide(num,mres);
				printf("%d\n",mres+1);
			}
			else
			{
				printf("%d\n",N);
				decide(num,N-1);
			}
		}
		else
		{
			int p=pl[num];
			out(p);
		}
	}
	return 0;
}