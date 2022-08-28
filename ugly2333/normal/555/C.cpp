//C
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
map<int,pair<char,int> > M;
map<int,pair<char,int> >::iterator it;
pair<int,pair<char,int> > p;
int main()
{
	int n,q,x,t;
	char ch;
	scanf("%d%d",&n,&q);
	M[0]=make_pair('U',0);
	M[n+1]=make_pair('L',0);
	while(q--){
		scanf("%d%d%c%c",&x,&x,&ch,&ch);
		x=n+1-x;
		it=M.lower_bound(x);
		p=*it;
		if(p.first==x){
			printf("0\n");
			continue;
		}
		if(ch=='L'){
			it--;
			p=*it;
		}
		t=p.first-x;
		if(t<0)
			t=-t;
		if(p.second.first==ch)
			t+=p.second.second;
		printf("%d\n",t);
		M[x]=make_pair(ch,t);
	}
	return 0;
}
/*
10 6
2 9 U
10 1 U
1 10 U
8 3 L
10 1 L
6 5 U

*/