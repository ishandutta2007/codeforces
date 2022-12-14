#include<cstdio>
#include<stack>
#include<algorithm>

using namespace std;

int a[1000100];
long long sum[1000100];
int d1[1000100],d2[1000100];

stack<int> stk,stk2;

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",a+i);
	a[0]=0,a[N+1]=0;
	stk.push(0);
	for(int i=1;i<=N;i++)
	{
		while(!stk.empty()&&a[stk.top()]>=a[i]) stk.pop();
		d1[i]=i-stk.top();
		stk.push(i);
	}
	stk2.push(N+1);
	for(int i=N;i>=1;i--)
	{
		while(!stk2.empty()&&a[stk2.top()]>a[i]) stk2.pop();
		d2[i]=stk2.top()-i;
		stk2.push(i);
	}
	for(int i=1;i<=N;i++)
	{
		int v=a[i];
		sum[1]+=v;
		sum[d1[i]+1]-=v;
		sum[d2[i]+1]-=v;
		sum[d1[i]+d2[i]+1]+=v;
	}
	for(int i=1;i<=N;i++) sum[i]+=sum[i-1];
	for(int i=1;i<=N;i++) sum[i]+=sum[i-1];
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int n;
		scanf("%d",&n);
		printf("%.12f\n",(double)sum[n]/(N-n+1));
	}
	return 0;
}