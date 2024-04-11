#include<cstdio>
#include<cstdlib>

using namespace std;

int head,tail;

int q[110];
int tmp[110];

int goal[110];

int lns[110];
int ln=0;

bool visited[110];

int N;

int gcd(int a,int b)
{
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}

void th()
{
	int tmp2[110];
	for(int i=0;i<N;i++)
	{
		tmp2[i]=tmp[q[i]];
	}
	for(int i=0;i<N;i++) tmp[i]=tmp2[i];
	//for(int i=0;i<N;i++) printf("%d ",tmp[i]);
	//puts("");
}

void tt()
{
	int tmp2[110];
	for(int i=0;i<N;i++) tmp2[q[i]]=tmp[i];
	for(int i=0;i<N;i++) tmp[i]=tmp2[i];
}

void print(bool which)
{
	if(which) printf("YES\n");
	else printf("NO\n");
	exit(0);
}

void deb()
{
	printf("%d %d\n",head,tail);
}

int main()
{
	int K;
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++) scanf("%d",q+i);
	for(int i=0;i<N;i++) q[i]--;
	for(int i=0;i<N;i++) scanf("%d",goal+i);
	for(int i=0;i<N;i++) goal[i]--;
	for(int i=0;i<N;i++) tmp[i]=i;
	head=-1,tail=-1;
	for(int i=0;i<=K;i++)
	{
		bool ok=true;
		for(int j=0;j<N;j++)
		{
			if(tmp[j]!=goal[j]) ok=false;
		}
		if(ok) {head=i;break;}
		th();
	}
	for(int i=0;i<N;i++) tmp[i]=i;
	for(int i=0;i<=K;i++)
	{
		bool ok=true;
		for(int j=0;j<N;j++) if(tmp[j]!=goal[j]) ok=false;
		if(ok) {tail=i;break;}
		tt();
	}
	//deb();
	if(head==-1&&tail==-1) print(false);
	else if(head==-1||tail==-1)
	{
		int par=head+tail-1;
		if((par-K)%2==0) print(true);
		print(false);
	}
	else if(head==0)
	{
		print(false);
		return 0;
	}
	else if(K==1)
	{
		print(head==1||tail==1);
		//printf("%s\n",head==1||tail==1?"YES":"NO");
		return 0;
	}
	else if(head==1)
	{
		if(tail==1) print(false);
		if((tail-K)%2!=0&&K%2==0) print(false);
		//if(K%2==0) print(false);
		print(true);
	}
	else if(tail==1)
	{
		if((head-K)%2!=0&&K%2==0) print(false);
		//if(K%2==0) print(false);
		print(true);
	}
	else if((head-K)%2!=0&&(tail-K)%2!=0) print(false);
	else print(true);
	return 0;
}