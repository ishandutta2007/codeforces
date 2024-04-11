#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1000050;
char s[N],ans[N];
int sz;
bool use[N];
void Solve(int l, int r)
{
	if(l>r) return;
	if(s[l]==s[r])
	{
		use[l]=use[r]=1;
		Solve(l+1,r-1);
	}
	else if(l!=r)
	{
		if(s[l]==s[r-1])
		{
			use[l]=use[r-1]=1;
			Solve(l+1,r-2);
		}
		else if(s[l+1]==s[r])
		{
			use[l+1]=use[r]=1;
			Solve(l+2,r-1);
		}
		else Solve(l+1,r-1);
	}
}
int main()
{
	int n;
	scanf("%s",s+1);
	n=strlen(s+1);
	Solve(1,n);
	for(int i=1;i<=n;i++) if(use[i]) printf("%c",s[i]);
	return 0;
}