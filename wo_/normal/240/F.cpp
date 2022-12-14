#include<cstdio>
#include<algorithm>

using namespace std;

struct segtree{
	int N;
	int dat[270270];
	bool same[270270];
	void init(int N_)
	{
		N=1;
		while(N<N_) N*=2;
		for(int i=0;i<=2*N-1;i++)
		{
			dat[i]=0;
			same[i]=true;
		}
	}
	void addone(int l,int r,int k,int a,int b)
	{
		if(l<=a&&b<=r)
		{
			dat[k]=b-a;
			same[k]=true;
			return;
		}
		if(r<=a||b<=l) return;
		if(same[k]==true)
		{
			dat[k*2]=dat[k]/2;
			dat[k*2+1]=dat[k]/2;
			same[k*2]=true;
			same[k*2+1]=true;
		}
		addone(l,r,k*2,a,(a+b)/2);
		addone(l,r,k*2+1,(a+b)/2,b);
		dat[k]=dat[k*2]+dat[k*2+1];
		same[k]=false;
	}
	void addone(int l,int r)
	{
		addone(l,r,1,0,N);
	}
	void setzero(int l,int r,int k,int a,int b)
	{
		if(l<=a&&b<=r)
		{
			dat[k]=0;
			same[k]=true;
			return;
		}
		if(r<=a||b<=l)
		{
			return;
		}
		if(same[k]==true)
		{
			dat[k*2]=dat[k]/2;
			dat[k*2+1]=dat[k]/2;
			same[k*2]=true;
			same[k*2+1]=true;
		}
		setzero(l,r,k*2,a,(a+b)/2);
		setzero(l,r,k*2+1,(a+b)/2,b);
		dat[k]=dat[k*2]+dat[k*2+1];
		same[k]=false;
	}
	void setzero(int l,int r)
	{
		setzero(l,r,1,0,N);
	}
	int getnum(int l,int r,int k,int a,int b)
	{
		if(l<=a&&b<=r) return dat[k];
		if(r<=a||b<=l) return 0;
		if(same[k]==true)
		{
			if(dat[k]==0) return 0;
			return max(0,min(b,r)-max(a,l));
		}
		return getnum(l,r,k*2,a,(a+b)/2)+getnum(l,r,k*2+1,(a+b)/2,b);
	}
	int getnum(int l,int r)
	{
		return getnum(l,r,1,0,N);
	}/*
	void setallzero(int k)
	{
		dat[k]=0;
		if(k>=N) return
		setallzero(k*2);
		setallzero(k*2+1);
	}
	void setallone(int k)
	{*/
	void setall(int k,int l,int r)
	{
		if(r-l==1) return;
		if(same[k]==true)
		{
			for(int i=l+N;i<r+N;i++)
			{
				if(dat[k]==0) dat[i]=0;
				else dat[i]=1;
			}
			return;
		}
		setall(k*2,l,(l+r)/2);
		setall(k*2+1,(l+r)/2,r);
	}
	void setall()
	{
		setall(1,0,N);
	}
	void putarray(int *a,int N_)
	{
		setall();
		for(int i=0;i<N_;i++)
		{
			a[i]=dat[i+N];
		}
	}
	void print()
	{
		for(int i=0;i<2*N;i++) printf("%d ",dat[i]);
		printf("\n");
	}
};

segtree seg[26];

int tmp[26];

char ch[100100];

int res[26][100100];

int main()
{
	int N,M;
	FILE *fp1=freopen("input.txt","r",stdin);
	FILE *fp2=freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	scanf("%s",ch);
	for(int i=0;i<26;i++)
	{
		seg[i].init(N);
	}
	for(int i=0;i<N;i++)
	{
		seg[ch[i]-'a'].addone(i,i+1);
	}
	//seg[0].print();
	for(int q=0;q<M;q++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l--;
		int odd=0;
		int oddid=-1;
		for(int i=0;i<26;i++)
		{
			tmp[i]=seg[i].getnum(l,r);
			if(tmp[i]%2!=0)
			{
				odd++;
				oddid=i;
			}
		}
		if(odd>1) continue;
		for(int i=0;i<26;i++) seg[i].setzero(l,r);
		int done=l;
		for(int i=0;i<26;i++)
		{
			if(tmp[i]==0) continue;
			seg[i].addone(done,done+tmp[i]/2);
			done+=tmp[i]/2;
		}
		if(odd==1)
		{
			seg[oddid].addone(done,done+1);
			done++;
		}
		for(int i=25;i>=0;i--)
		{
			if(tmp[i]==0) continue;
			seg[i].addone(done,done+tmp[i]/2);
			done+=tmp[i]/2;
		}
		//seg[0].print();
	}
	for(int i=0;i<26;i++)
	{
		seg[i].putarray(res[i],N);
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(res[j][i]==1)
			{
				printf("%c",'a'+j);
				break;
			}
		}
	}
	printf("\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}