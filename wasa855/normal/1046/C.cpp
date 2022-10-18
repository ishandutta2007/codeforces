#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int t[200005];
int main()
{
	int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
	}
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        if(i!=1)
        {
        	t[i]=b[i];
		}
    }
    int k=a[d]+b[1];
    int rnk=1;
    int r=n;
    int l=1;
    for(int i=1;i<=n;i++)
    {
    	if(i!=d)
        {
            if(a[i]+t[r]>k)
			{
				l++;
				rnk++;
			}
            else
            {
            	r--;
			}
        }
	}
    cout<<rnk<<endl;
    return 0;
}