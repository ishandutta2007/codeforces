#include<cstdio>
#include<algorithm>

using namespace std;

struct node{
	int ln44,ln47,ln74,ln77;
	bool flip;
	node(){}
	node(int a,int b,int c,int d,bool e)
	{
		ln44=a;ln47=b;ln74=c;ln77=d;flip=e;
	}
};

char ch[1100100];
int len;

struct segtree{
	node nodes[2100100];
	int N;
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=N;i<=2*N-1;i++)
		{
			if(ch[i-N]=='4')
			{
				nodes[i]=node(1,0,0,0,false);
			}
			else if(i-N<len)
			{
				nodes[i]=node(0,0,0,1,false);
			}
			else
			{
				nodes[i]=node(0,0,0,0,false);
			}
		}
		for(int i=N-1;i>=1;i--)
		{
			int ln44=nodes[i*2].ln44+nodes[i*2+1].ln44;
			int ln47=max(max(nodes[i*2].ln44+nodes[i*2+1].ln47,nodes[i*2].ln47+nodes[i*2+1].ln77),nodes[i*2].ln44+nodes[i*2+1].ln77);
			int ln74=max(max(nodes[i*2].ln77+nodes[i*2+1].ln74,nodes[i*2].ln74+nodes[i*2+1].ln44),nodes[i*2].ln77+nodes[i*2+1].ln44);
			int ln77=nodes[i*2].ln77+nodes[i*2+1].ln77;
			nodes[i]=node(ln44,ln47,ln74,ln77,false);
		}
	}
	void ex(int i)
	{
		swap(nodes[i].ln44,nodes[i].ln77);
		swap(nodes[i].ln47,nodes[i].ln74);
	}
	void print(int i)
	{
		printf("%d %d %d %d\n",nodes[i].ln44,nodes[i].ln47,nodes[i].ln74,nodes[i].ln77);
	}
	void change(int a,int b,int k,int l,int r)
	{
		//change [a,b)
		if(r<=a||b<=l) return;
		if(a<=l&&r<=b)
		{
			nodes[k].flip=!nodes[k].flip;
			swap(nodes[k].ln47,nodes[k].ln74);
			swap(nodes[k].ln44,nodes[k].ln77);
			return;
		}
		if(nodes[k].flip)
		{
			nodes[k].flip=false;
			nodes[k*2].flip=!nodes[k*2].flip;nodes[k*2+1].flip=!nodes[k*2+1].flip;
			ex(k*2);ex(k*2+1);
		}
		change(a,b,k*2,l,(l+r)/2);
		change(a,b,k*2+1,(l+r)/2,r);
		int ln44=nodes[k*2].ln44+nodes[k*2+1].ln44;
		int ln47=max(max(nodes[k*2].ln44+nodes[k*2+1].ln47,nodes[k*2].ln47+nodes[k*2+1].ln77),nodes[k*2].ln44+nodes[k*2+1].ln77);
		int ln74=max(max(nodes[k*2].ln77+nodes[k*2+1].ln74,nodes[k*2].ln74+nodes[k*2+1].ln44),nodes[k*2].ln77+nodes[k*2+1].ln44);
		int ln77=nodes[k*2].ln77+nodes[k*2+1].ln77;
		nodes[k]=node(ln44,ln47,ln74,ln77,false);
	}
	void change(int a,int b)
	{
		change(a,b,1,0,N);
	}
	int get()
	{
		int res=max(max(nodes[1].ln44,nodes[1].ln77),nodes[1].ln47);
		return res;
	}
};

segtree seg;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	scanf("%s",ch);
	len=N;
	seg.init(N);
	//seg.print(1);
	for(int q=0;q<M;q++)
	{
		char in[10];
		scanf("%s",in);
		if(in[0]=='c')
		{
			printf("%d\n",seg.get());
		}
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			seg.change(a,b);
			//seg.print(1);
		}
	}
	return 0;
}