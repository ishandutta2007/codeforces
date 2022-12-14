#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
bitset<N >v[26],ans;
int n,Q;char s[N],t[N];
int main()
{
	scanf("%s%d",s+1,&Q);n=strlen(s+1);
	for(int i=1;i<=n;i++)v[s[i]-'a'][i]=1;
	for(int op,l,r;Q--;)
	{
		scanf("%d",&op);
		if(op==1)scanf("%d%s",&l,t+1),v[s[l]-'a'][l]=0,v[t[1]-'a'][l]=1,s[l]=t[1];
		else
		{
			scanf("%d%d%s",&l,&r,t);int m=strlen(t);
			if(m>r-l+1){puts("0");continue;}ans.set();
			for(int i=0;i<m;i++)ans&=(v[t[i]-'a']>>i);
			printf("%d\n",(int)((ans>>l).count())-(int)((ans>>(r-m+2)).count()));
		}
	}
}