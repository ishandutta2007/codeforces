#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=1048576,D=62;
int n,m;
char str[N];
int cnt[M][D],tcnt[M];
int Get(char ch)
{
	if(isdigit(ch))
		return ch-'0';
	if(islower(ch))
		return 10+int(ch-'a');
	return 36+int(ch-'A');
}
char rGet(int ch)
{
	if(ch<10)
		return ch+'0';
	if(ch<36)
		return (ch-10)+'a';
	return (ch-36)+'A';
}
void Union(int v)
{
	int lc=2*v,rc=2*v+1;
	for(int i=0;i<D;i++)
		cnt[v][i]=cnt[lc][i]+cnt[rc][i];
	tcnt[v]=tcnt[lc]+tcnt[rc]; 
}
void Create(int v,int l,int r)
{
	if(l==r)
	{
		cnt[v][Get(str[l])]++;
		tcnt[v]++;
	}
	else
	{
		int m=l+r>>1;
		Create(2*v,l,m);
		Create(2*v+1,m+1,r);
		Union(v);
	}
}
bool Rem(int v,int l,int r,int a,int b,int ch)
{
	if(a>tcnt[v]||b<1||cnt[v][ch]==0)
		return false;
	if(l==r)
	{
		cnt[v][ch]--;
		tcnt[v]--;
		return true;
	}
	else
	{
		int m=l+r>>1;
		bool fa=Rem(2*v+1,m+1,r,a-tcnt[2*v],b-tcnt[2*v],ch);
		bool fb=Rem(2*v,l,m,a,b,ch);
		if(fa||fb)
		{
			Union(v);
			return true;
		}
		return false;
	}
}
void Print(int v,int l,int r)
{
	if(l==r)
	{
		int ind=0;
		while(ind<D&&cnt[v][ind]==0)
			ind++;
		if(ind<D)
			printf("%c",rGet(ind));
	}
	else
	{
		int m=l+r>>1;
		Print(2*v,l,m);
		Print(2*v+1,m+1,r);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",str+1);
	Create(1,1,n);
	while(m--)
	{
		int a,b;
		char c;
		scanf("%d%d %c",&a,&b,&c);
		Rem(1,1,n,a,b,Get(c));
	} 
	Print(1,1,n);
	printf("\n");
	return 0;
}