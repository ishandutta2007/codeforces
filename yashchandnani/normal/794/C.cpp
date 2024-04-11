#include <bits/stdc++.h>
using namespace std;

int main(){

	string a,b;
	cin>>a>>b;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int n=a.size();
	char c[n];
	int l=0,r=n-1,l1=0,r1=n-1,l2=0,r2=n-1,oleg=(n+1)/2,igor=n/2;
	for (int i = 0; i < n; ++i)
	{
		if (i%2==0)
		{
			oleg--;
			if (b[r2]<=a[l1])
			{
				c[r]=a[l1+oleg];
				r1=l1+oleg-1;
				r--;
			}
			else{
				c[l]=a[l1];
				l++;
				l1++;
			}
		}
		else{
			igor--;
			if (b[r2]<=a[l1])
			{
				c[r]=b[r2-igor];
				l2=r2-igor+1;
				r--;

			}
			else{
				c[l]=b[r2];
				l++;
				r2--;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<c[i];
	}



	return 0;

}