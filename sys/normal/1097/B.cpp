#include <bits/stdc++.h>
using namespace std;
int n,num[20];
set <int> Se;
int main()
{
	scanf("%d",&n);
	scanf("%d",&num[1]);
	Se.insert(360-num[1]);
	Se.insert(num[1]);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&num[i]);
		set <int> tmp;
		tmp.clear();
		for(set <int>::iterator it=Se.begin();it!=Se.end();it++)
			tmp.insert((*it+num[i])%360),tmp.insert(((*it-num[i])%360+360)%360);
		Se=tmp;
	}
	if(Se.find(0)!=Se.end()) printf("Yes");
	else printf("No");
	return 0;
}