#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1000050;
char s[N];
int main()
{
	int n,i;
	scanf("%s",s+1);
	n=strlen(s+1);
	int l,r;
	for(l=1;l<=n;l++) if(s[l]=='[') break;
	for(l++;l<=n;l++) if(s[l]==':') break;
	for(r=n;r>=1;r--) if(s[r]==']') break;
	for(r--;r>=1;r--) if(s[r]==':') break;
	if(l<r)
	{
		int cnt=4;
		for(int i=l+1;i<=r;i++) if(s[i]=='|') cnt++;
		printf("%i\n",cnt);
	}
	else printf("-1\n");
	return 0;
}