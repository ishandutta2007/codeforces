#include <stdio.h>
#include <unordered_map>
#include <cstring>
using namespace std;
#define ll long long
const int N=4050;
const ll mod=991948530947554;
unordered_map<ll,bool> vis;
char ch[N],b[N],e[N];
int sol;
bool Begin[N],End[N];
ll Mod(ll x){ return x<mod?x:x-mod;}
int main()
{
	int n,m,k,i,j,l;
	scanf("%s",&ch);n=strlen(ch);
	scanf("%s",&b);m=strlen(b);
	scanf("%s",&e);k=strlen(e);
	ll Hash;
	for(i=0;i<n;i++)
	{
		Begin[i]=1;
		for(j=0;j<m;j++) if(ch[i+j]!=b[j]) Begin[i]=0;
	}
	for(i=0;i<n;i++)
	{
		End[i+k-1]=1;
		for(j=0;j<k;j++) if(ch[i+j]!=e[j]) End[i+k-1]=0;
	}
	for(i=0;i<n;i++)
	{
		if(Begin[i])
		{
			Hash=0;
			for(j=i;j<n;j++)
			{
				//for(l=0;l<26;l++) Hash=Mod(Hash+Hash);
				Hash=Hash*26%mod;
				Hash=Mod(Hash+ch[j]-'a'+1);
				if(End[j] && !vis[Hash] && j-i+1>=m && j-i+1>=k)
				{
					sol++;
					vis[Hash]=1;
				}
			}
		}
	}
	printf("%i\n",sol);
	return 0;
}