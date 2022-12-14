#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
int n,k,a[N],b[N],vis[N];
void print(int *a)
{putchar('?');for(int i=1;i<=k;i++)printf(" %d",a[i]);puts("");fflush(stdout);}
pair<int ,int >tmp;
pair<int ,int > get_num(int *a)
{print(a);int x,y;scanf("%d%d",&x,&y);return make_pair(x,y);}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)a[i] = i;
	int tmp = get_num(a).second,m=0,flag = 0;
	for(int i=1;i<=k;i++)
	{
		a[i] = k+1;int tt = get_num(a).second;
		if(tmp < tt)m++;
		else if(tmp > tt)flag = 1 , m++;
		a[i] = i;
	}
	if(!flag)printf("! %d\n",m);
	else printf("! %d\n",k-m+1);
}