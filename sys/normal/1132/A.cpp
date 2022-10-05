#include <bits/stdc++.h>
using namespace std;
int cnt[5];
int main()
{
	scanf("%d%d%d%d",&cnt[1],&cnt[2],&cnt[3],&cnt[4]);
	if(cnt[1]==cnt[4]&&!(!cnt[1]&&cnt[3])) printf("1");
	else printf("0");
	return 0;
}