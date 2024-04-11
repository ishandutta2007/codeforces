#include<bits/stdc++.h>
using namespace std;
int n,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	 if (n%i==0)ans++;
	printf("%d\n",ans);  
}