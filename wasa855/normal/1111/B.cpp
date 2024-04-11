#include<bits/stdc++.h>
using namespace std;
#define eps 1e-7
double a[100005];
int main()
{
    double n,m,k;
    cin>>n>>m>>k;
    double sum=0;
    for(int i=1;i<=n;i++) 
	{
		scanf("%lf",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+(int)n+1);
    double maxi=(sum+min(n*m,k))*1.0/n;
    for(int i=1;i<=min(k,n-1);i++) 
	{
        sum-=a[i];
        maxi=max(maxi,(sum+min((n-i)*m,(k-i)))*1.0/(n-i));
    }
    printf("%.10lf\n",maxi);
    return 0;
}