#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int n,b[N];
void ask(int i)
{
	printf("? %i\n",i);fflush(stdout);
	int x;scanf("%i",&x);
	printf("? %i\n",i+n/2);fflush(stdout);
	int y;scanf("%i",&y);
	b[i]=x-y;b[i+n/2]=y-x;
}
int Sgn(int x){ return x/abs(x);}
int Search(int l, int r)
{
	if(r-l<2) return -1;
	int mid=l+r>>1;
	ask(mid);
	if(b[mid]==0) return mid;
	if(Sgn(b[mid])!=Sgn(b[l])) return Search(l,mid);
	else return Search(mid,r);
}
int main()
{
	int i;
	scanf("%i",&n);ask(1);
	if(abs(b[i])&1) return 0*printf("-1\n");
	printf("! %i\n",Search(1,n/2+1));
	return 0;
}