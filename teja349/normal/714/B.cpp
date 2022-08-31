#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long int a[100302];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	long long int p= a[0];
	long long int q= a[0];
	for (int i = 0; i < n; ++i)
	{
		if(a[i]>p)
			p=a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if(a[i]<q)
			q=a[i];
	}
	//cout<<p<<q;
	long long int r=p-q;
	if(r%2==1){
		for (int i = 0; i < n; ++i)
		{
			for (int i = 0; i < n; ++i)
		{
			if(((a[i]==p)||(a[i]==q))){

			}
				
			else{
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
		return 0;
		}
	}
	else{
		long long int h=p-r/2;
		for (int i = 0; i < n; ++i)
		{
			if(((a[i]==p)||(a[i]==q))||(a[i]==h)){

			}
				
			else{
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
		return 0;
	}
}