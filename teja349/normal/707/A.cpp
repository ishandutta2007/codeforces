#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	char a[103][103];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin>>a[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{	
			switch(a[i][j]){
				case 'C':case 'M': case 'Y':{
					cout<<"#Color";
					return 0;
				}
			}
		}
	}
	cout<<"#Black&White";
	return 0;

}