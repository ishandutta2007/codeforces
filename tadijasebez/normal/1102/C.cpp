#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y;
	scanf("%i %i %i",&n,&x,&y);
	vector<int> a(n);
	int cnt=0;
	for(int i=0;i<n;i++) scanf("%i",&a[i]);
	if(x>y) return 0*printf("%i\n",n);
	sort(a.begin(),a.end());
	int r=-1;
	for(int i=0;i<n;i++) if(a[i]<=x) r=i;
	for(int i=0;i<n;i++) if(a[i]<=x)
	{
		cnt++;
		if(r>i)
		{
			a[r]+=y;
			if(a[r]>x) r--;
		}
		else break;
	}
	printf("%i\n",cnt);
	return 0;
}