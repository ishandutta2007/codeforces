#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	scanf("%i",&n);
	vector<int> a(n),b(n);
	for(int &j:a) scanf("%i",&j);
	for(int &j:b) scanf("%i",&j);
	for(int i=n-1;i;i--) a[i]-=a[i-1],b[i]-=b[i-1];
	sort(a.begin()+1,a.end());
	sort(b.begin()+1,b.end());
	if(a==b) printf("Yes\n");
	else printf("No\n");
	return 0;
}