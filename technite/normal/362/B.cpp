#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	cin>>n>>m;
	int arr[m];
	for(int i=0;i<m;i++) cin>>arr[i];
	sort(arr,arr+m);
	int count=0;
	for(int i=1;i<m;i++)
	{
		if(arr[i]-arr[i-1]==1)
		{
			count++;
		}
		else count=0;
		if(count>=2) 
		{
			cout<<"NO";
			return 0;
		}
		else if(arr[0]==1||arr[m-1]==n) return cout<<"NO",0 ;

	}
	if(arr[0]==1||arr[0]==n) cout<<"NO";
	else cout<<"YES";

}