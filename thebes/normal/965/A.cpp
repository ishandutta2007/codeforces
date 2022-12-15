#include <bits/stdc++.h>
using namespace std;
int k,n,s,p;
int main(){
	scanf("%d%d%d%d",&k,&n,&s,&p);
	s = k*ceil((double)n/(double)s);
	p = ceil((double)s/(double)p);
	printf("%d\n",p);
	return 0;
}