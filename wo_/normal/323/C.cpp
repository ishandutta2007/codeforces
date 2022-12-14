#include<cstdio>
#include<algorithm>

using namespace std;

int p[1100100],q[1100100];
int rp[1100100],rq[1100100];

int a[1100100];

struct segtree{
	int N;
	int dat[21][1048576];
	void init(int N_,int *a)
	{
		N=1;
		int dep=1;
		while(N<N_)
		{
			N*=2;
			dep++;
		}
		for(int i=0;i<N_;i++) dat[dep-1][i]=a[i];
		for(int i=N_;i<N;i++) dat[dep-1][i]=i;
		int ln=1;
		//printf("dep=%d\n",dep);
		for(int d=dep-2;d>=0;d--)
		{
			ln*=2;
			for(int l=0;l<N;l+=ln)
			{
				int r=l+ln;
				int lid=l,rid=l+ln/2;
				int id=l;
				//printf("c%d %d %d %d\n",l,r,lid,rid);
				while(lid<l+ln/2||rid<r)
				{
					if(lid==l+ln/2){
						//printf("a\n");
						dat[d][id]=dat[d+1][rid];
						rid++;
						id++;
					}else if(rid==r){
						//printf("b\n");
						dat[d][id]=dat[d+1][lid];
						lid++;id++;
					}else{
						if(dat[d+1][lid]<dat[d+1][rid]){
							//printf("c\n");
							dat[d][id]=dat[d+1][lid];
							lid++;id++;
						}else{
							//printf("d\n");
							dat[d][id]=dat[d+1][rid];
							rid++;id++;
						}
					}
				}
			}
		}
	}
	int query(int l,int r,int x,int d,int a,int b)
	{
		if(l<=a&&b<=r) return upper_bound(&dat[d][a],&dat[d][b],x)-(&dat[d][a]);
		else if(r<=a||b<=l) return 0;
		else return query(l,r,x,d+1,a,(a+b)/2)+query(l,r,x,d+1,(a+b)/2,b);
	}
	int query(int l,int r,int x)
	{
		if(x<0) return 0;
		return query(l,r,x,0,0,N);
	}
	void output()
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<4;j++) printf("%d ",dat[i][j]);
			printf("\n");
		}
	}
};

segtree seg;

int N;

int f(int x,int z)
{
	int res=z-1+x;
	return (res%N)+1;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",p+i);
		p[i]--;
		rp[p[i]]=i;
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",q+i);
		q[i]--;
		rq[q[i]]=i;
	}
	for(int i=0;i<N;i++)
	{
		int pos=rq[p[i]];
		a[i]=pos;
	}
	seg.init(N,a);
	//seg.output();
	int M;
	scanf("%d",&M);
	int x=0;
//	for(int i=0;i<N;i++) printf("%d ",a[i]);
//	printf("\n");
	for(int i=0;i<M;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int l1,r1,l2,r2;
		l1=min(f(x,a),f(x,b));r1=max(f(x,a),f(x,b));
		l2=min(f(x,c),f(x,d));r2=max(f(x,c),f(x,d));
		l1--;l2--;r1--;r2--;
		//int ll=seg.query(l2,r2+1,l1-1);
		//int rr=seg.query(l2,r2+1,r1);
		int ll=seg.query(l1,r1+1,l2-1);
		int rr=seg.query(l1,r1+1,r2);
		//printf("%d %d %d %d::",l1,r1,l2,r2);
		//printf("%d-%d= %d\n",rr,ll,rr-ll);
		printf("%d\n",rr-ll);
		x=rr-ll+1;
	}
	return 0;
}