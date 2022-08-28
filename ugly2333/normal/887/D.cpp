//CF 887D
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
const int N = 3e5+35;
int n,l;
LL a,b,c,d,st;
int t[N],q[N];
LL s[N];
set<pair<LL,int> > S;
int main()
{
	int i,j;
	LL x,y;
	scanf("%d%lld%lld%lld%lld%lld%d",&n,&a,&b,&c,&d,&st,&l);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",t+i,q+i);
		if(q[i])
			s[i]=s[i-1]+c;
		else
			s[i]=s[i-1]-d;
	}
	t[0]=-1;
	j=1;
	x=st;
	S.insert(make_pair(0,0));
	for(i=0;i<=n;i=i+1){
		if(i){
			if(q[i])
				x+=a;
			else
				x-=b;
			S.erase(make_pair(s[i],i));
		}
		if(x<0){
			cout<<-1<<endl;
			return 0;
		}
		while(j<=n&&t[j]<=t[i]+l){
			S.insert(make_pair(s[j],j));
			j++;
		}
		y=(*(S.begin())).first-s[i];
		if(x+y>=0){
			cout<<t[i]+1<<endl;
			return 0;
		}
	}
	return 0;
}