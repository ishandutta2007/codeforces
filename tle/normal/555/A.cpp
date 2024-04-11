#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
int getint()
{
	int tmp=0; bool fu=0; char s;
	while(s=getchar(),s!='-'&&(s<'0'||s>'9')) ;
	if(s=='-') fu=1; else tmp=s-'0';
	while(s=getchar(),s>='0'&&s<='9') tmp=tmp*10+s-'0';
	if(fu) return -tmp; else return tmp;
}
#define IO =getint()
int n,k,cn,ans=0;
int cs[100001];
bool rp[100001];
int main()
{
	n IO, k IO;
	for(int i=1;i<=k;i++)
	{
		cn IO;
		for(int j=1;j<=cn;j++)
		{
			cs[j] IO;
		}
		for(int j=2;j<=cn;j++)
		{
			if(cs[j]!=cs[j-1]+1)
			{
				ans++; if(cs[1]==1) cs[1]=233;
			}
			else if(cs[1]==1) rp[cs[j-1]]=1;
			else ++ans;
		}
    }
	for(int i=1;i<n;i++) ans+=!rp[i];
	cout<<ans;
}