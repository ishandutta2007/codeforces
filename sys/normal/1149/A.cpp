#include <bits/stdc++.h>
using namespace std;
int n,a[200005],cnt[4];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	if(cnt[2]) printf("2 "),cnt[2]--;
	for(int i=1;i<=(cnt[1]%2?cnt[1]:cnt[1]-1);i++)
		printf("1 ");
	if(cnt[1]) cnt[1]-=(cnt[1]%2?cnt[1]:cnt[1]-1);
	for(int i=1;i<=cnt[2];i++)
		printf("2 ");
	if(cnt[1])
		printf("1 ");
	return 0;
}