//CF 947D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
int ls,lt,ss[N],bs[N],tt[N],bt[N];
char s[N],t[N];
int main()
{
	int q,i,j,l,r,x,y;
	scanf("%s%s",s+1,t+1);
	s[0]='_',t[0]='_';
	ls=strlen(s)-1,lt=strlen(t)-1;
	for(i=1;i<=ls;i=i+1){
		ss[i]=ss[i-1];
		bs[i]=bs[i-1];
		if(s[i]!='A')
			ss[i]=i,bs[i]++;
	}
	for(i=1;i<=lt;i=i+1){
		tt[i]=tt[i-1];
		bt[i]=bt[i-1];
		if(t[i]!='A')
			tt[i]=i,bt[i]++;
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d%d",&l,&r,&x,&y);
		i=(r-max(ss[r],l-1))-(y-max(tt[y],x-1));
		j=(bt[y]-bt[x-1])-(bs[r]-bs[l-1]);
		if((i<0)||(j<0)||(j&1)){
			cout<<0;
			continue;
		}
		if(i%3)
			j-=2;
		if(j<0||(j>0&&bs[r]-bs[l-1]==0&&i==0))
			cout<<0;
		else
			cout<<1;
	}
	return 0;
}