#include <iostream>
using namespace std;


long long int gcd(long long int a,long long int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	int ans[k]={0};
	int totalgcd=k;
	int j=1;
	for(int i=0;i<n;i++)
	{
	    int a;
	    cin>>a;
	    a=a%k;
	    if(a!=0)
	    {
	        if(j==1)
	        {
	            totalgcd=gcd(a,k);
                    j=0;
	        }
	        else
	        {
	            totalgcd=gcd(totalgcd,gcd(a,k));
	        }
	    }
	}
	cout<<k/totalgcd<<endl;
	j=0; int y=totalgcd;
	while(j*y<k)
	{
	    cout<<j*y<<" ";
	    j++;
	}
	return 0;
}