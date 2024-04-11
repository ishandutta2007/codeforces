#include <iostream>
using namespace std;
int main()
{
	int arr[100];
	int n;cin>>n;
	for(int a=0;a<n;a++)cin>>arr[a];
	for(int a=0;a<n;a++)
	{
		for(int b=a+1;b<n;b++)
		{
			for(int c=0;c<n;c++)
			{
				if(arr[a]+arr[b]==arr[c])
				{
					cout<<c+1<<" "<<b+1<<" "<<a+1;
					exit(0);
				}
			}
		}
	}
	cout<<-1;
}