#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int n, T[30];
int gc, ind, sum, tmp;
char C[100005];

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", T+i);
		sum+=T[i];
		if(T[i]%2)
		{
			tmp++;
			ind=i;
		}
		if(gc==0)
			gc=T[i];
		else
			gc=__gcd(gc, T[i]);
	}
	if(tmp>1)
	{
		printf("0\n");
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<T[i]; j++)
				printf("%c", (char)((int)'a'+i));
		}
		printf("\n");
		return 0;
	}
	int l=sum/gc;
	printf("%d\n", gc);
	for(int i=0; i<n; i++)
		T[i]/=gc;
	//printf("%d %d %d\n", tmp, gc, l);
	if(gc%2)
	{
		int temp=0;
		for(int i=0; i<n; i++)
		{
			if(i==ind)
				continue;
			while(T[i]>0)
			{
				C[temp]=(char)((int)'a'+i);
				C[l-temp-1]=(char)((int)'a'+i);
				temp++;
				T[i]-=2;
			}
		}
		while(T[ind]>0)
		{
			C[temp]=(char)((int)'a'+ind);
			C[l-temp-1]=(char)((int)'a'+ind);
			temp++;
			T[ind]-=2;
		}
		for(int i=0; i<gc; i++)
			for(int j=0; j<l; j++)
				printf("%c", C[j]);
		printf("\n");
	}
	else
	{
		int temp=0;
		for(int i=0; i<n; i++)
		{
			while(T[i]>0)
			{
				C[temp]=(char)((int)'a'+i);
				temp++;
				T[i]--;
			}
		}
		for(int i=0; 2*i<gc; i++)
		{
			for(int j=0; j<l; j++)
				printf("%c", C[j]);
			for(int j=l-1; j>=0; j--)
				printf("%c", C[j]);
		}
		printf("\n");
	}
	return 0;
}