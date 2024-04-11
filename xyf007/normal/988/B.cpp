#include<bits/stdc++.h>
using namespace std;
string a[105];
bool cmp(string s1,string s2)
{
	return s1.size()<s2.size();
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<n;i++)
      if(a[i+1].find(a[i])==-1)
        {
          printf("NO");
          return 0;
		}
	printf("YES\n");
	for(int i=1;i<=n;i++)
	  cout<<a[i]<<endl;
	return 0;
}