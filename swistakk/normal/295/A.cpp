#include <iostream>
#define uint long long int
#define N 100005
#define M 131072
using namespace std;
uint drz[2*M+5];
uint ile[2*M+5];
int init[N];
void dodaj(uint a, uint b, uint w, uint *t)
{
	a+=M-1;
	b+=M-1;
	t[a]+=w;
	if(a!=b)
	{
		t[b]+=w;
	}
	while(a/2 !=b/2)
	{
		if(a%2==0)
		{
			t[a+1]+=w;
		}
		if(b%2==1)
		{
			t[b-1]+=w;
		}
		a/=2;
		b/=2;
	}
}
uint czyt(int a, uint *t)
{
	uint sum=0;
	a+=M-1;
	while(a)
	{
		sum+=t[a];
		a/=2;
	}
	return sum;
}
int q[N][3];
int main()
{
	ios_base::sync_with_stdio(0);
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>init[i];
	}
	for(int i=1; i<=m; i++)
	{
		int l, r, d;
		cin>>l>>r>>d;
		q[i][0]=l;
		q[i][1]=r;
		q[i][2]=d;
		//dodaj(l, r, d, drz);
	}
	for(int i=1; i<=k; i++)
	{
		int l, r;
		cin>>l>>r;
		dodaj(l, r, 1, ile);
	}
	for(int i=1; i<=m; i++)
	{
		dodaj(q[i][0], q[i][1], q[i][2]*czyt(i, ile), drz);
	}
	for(int i=1; i<=n; i++)
	{
		cout<<init[i]+czyt(i, drz)<<" ";
	}
	cout<<endl;
	return 0;
}