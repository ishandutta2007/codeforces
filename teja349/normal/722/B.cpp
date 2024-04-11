#include<iostream>
using namespace std;
#include<stdio.h>
int main(){
	int n;
	cin>>n;
	int a[110],ans;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	char ch=getchar();
	
	for (int i = 0; i < n; ++i)
	{
		ch=getchar();
		ans=0;
		while(ch!='\n'){
			switch(ch){
				case 'a':case 'e':case 'i':case 'o':case 'u':case 'y': ans++;break;
			}
			ch=getchar();
		}
		//cout<<ans<<endl;
		if(ans!=a[i])
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}