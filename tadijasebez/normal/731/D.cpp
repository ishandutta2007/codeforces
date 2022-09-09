#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
const int N=500050;
const int M=2*N;
vector<int> s[N];
int BIT[M];
void Set1(int i, int f){ for(;i<M;i+=i&-i) BIT[i]+=f;}
void Set(int l, int r){ Set1(l+1,1);Set1(r+2,-1);}
int Get(int i){ int ret=0;for(i++;i;i-=i&-i) ret+=BIT[i];return ret;}
int main()
{
	int n,c,i,b,x,j;
	scanf("%i %i",&n,&c);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&b);while(b--) scanf("%i",&x),s[i].pb(x);
		if(i>1)
		{
			int sz=min(s[i].size(),s[i-1].size());
			for(j=0;j<sz;j++) if(s[i][j]!=s[i-1][j]) break;
			if(j==sz)
			{
				if(s[i-1].size()<=s[i].size()) Set(0,c-1);
			}
			else
			{
				int a=s[i-1][j];
				int b=s[i][j];
				if(a>b)
				{
					int l=c-a;
					int r=c-b;
					Set(l+1,r);
				}
				else
				{
					int l=c-b;
					int r=c-a;
					Set(0,l);
					Set(r+1,c);
				}
			}
		}
	}
	int sol=-1;
	for(i=0;i<c;i++) if(Get(i)==n-1){ sol=i;break;}
	printf("%i\n",sol);
	return 0;
}