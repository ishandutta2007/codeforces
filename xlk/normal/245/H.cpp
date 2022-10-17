#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int>ii;
vector<ii>a[1000020];
long long h[5020];
long long r[5020];
long long pw[5020];
int z[1000020];
int w[5020],p=13131,q;
char s[5020];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		a[y].push_back(ii(x,i));
	}
	for(int i=pw[0]=1;i<=n;i++)
		pw[i]=pw[i-1]*p;
	for(int i=1;i<=n;i++)
		h[i]=h[i-1]*p+s[i];
	for(int i=n;i>0;i--)
		r[i]=r[i+1]*p+s[i];
	for(int i=1;i<=n;i++)
	{
		int t=0;
		for(int j=i;j>0;j--)
		{
			if(h[i]-h[j-1]*pw[i-j+1]==r[j]-r[i+1]*pw[i-j+1])
				t++;
			w[j]+=t;
		}
		fe(j,a[i])
			z[j->Y]=w[j->X];;
	}
	for(int i=0;i<q;i++)
		printf("%d\n",z[i]);
}