#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair
#define F first
#define S second

int T[1000003];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {int a; scanf("%d", &a); T[i]=a;}
	sort(T, T+n);
	int li=n/2, w=n;
	//printf("li=%d\n", li);
	for(int i=0; i<n/2; i++)
	{
		//printf("AA ");
		//printf("%d, %d ", i, li);
		while(T[li]<2*T[i])
		{
			li++;
			if(li>=n) break;
		}
		if(li>=n) break;
		w--;
		li++;
	}
	printf("%d\n", w);
	return 0;
}