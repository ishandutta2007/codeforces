#include <bits/stdc++.h>
using namespace std;
int main(){
	string x,y,z;
	cin>>x>>y;
	for (int i = 0; i < x.size(); ++i)
	{
		if (x[i]<y[i])
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<y<<endl;
	return 0;
}