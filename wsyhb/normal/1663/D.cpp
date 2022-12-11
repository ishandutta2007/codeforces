#include<bits/stdc++.h>
using namespace std;
int main()
{
	string S;
	int X;
	cin>>S>>X;
	bool ans;
	if(S=="ABC")
		ans=X<=1999;
	else if(S=="ARC")
		ans=X<=2799;
	else
	{
		assert(S=="AGC");
		ans=X>=1200;
	}
	puts(ans?"YES":"NO");
	return 0;
}