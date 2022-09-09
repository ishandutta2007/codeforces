#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%i",&n);
	vector<int> a(n);
	for(int &i:a) scanf("%i",&i);
	sort(a.begin(),a.end());
	int sum=0;
	for(int i:a) sum+=i;
	for(int i=0;i<n;i++) sum-=i;
	for(int i=1;i+1<n;i++) if(a[i]==a[i-1]+1 && a[i]==a[i+1]) return 0*printf("cslnb\n");
    int cnt=0;
    for(int i=1;i<n;i++) if(a[i]==a[i-1]) cnt++;
    if(cnt>1) return 0*printf("cslnb\n");
    if(n>1 && a[0]==0 && a[1]==0) return 0*printf("cslnb\n");
	if(sum%2==0) printf("cslnb\n");
	else printf("sjfnb\n");
	return 0;
}