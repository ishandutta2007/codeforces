#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int tn=n;
	if(n<=2*k+1)
	{
		printf("1\n%d\n",(n+1)/2);
		return 0;
	}
	n-=k+1;
    int ans=1;
    while(n>k)
	{
        n=max(0,n-2*k-1);
        ans++;
    }
    cout<<ans<<endl;
    for(int i=1;i<=tn;i+=k)
	{
        printf("%d ",i+n);
        i+=k+1;
    }
	return 0;
}
//asfdljnacvnurheocwairof