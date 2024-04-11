#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long int n,beg = 0,start;
	cin>>n;
	int a[n],z[n];
	for(long long int i=0;i<n;i++)
	{
	    cin>>a[i];
	    z[i]=a[i];
	}
	 sort(z,z+n);
    bool b=1;
    for(long long int i=1;i<n;i++)
    {
        int k1=i;
        bool bbb=1;
        for(int j=0;j<n;j++)
        {
            if(k1==n)
            {
                k1=0;
            }
            if(z[k1]!=a[j])
            {
                bbb=0;
                break;
            }
            k1++;
        }
        if(bbb==1)
        {
            beg=i;
            break;
        }
    }
    if(z[0]==a[0] && z[n-1]==a[n-1])
    {
        beg=0;
    }
    start = beg;
    for(long long int i=0;i<n;i++)
    {
        if(beg==n)
        {
            beg=0;
        }
        if(a[i]!=z[beg])
        {
            
            b=0;
            break;
        }
        beg+=1;
    }
    if(b==1)
    {
        cout<<start;
    }
    else
    {
        cout<<"-1";
    }
    return 0;
}