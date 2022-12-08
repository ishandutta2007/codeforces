#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std; 

int a,b,c;

int main() 
{
	int i,j; 
	cin>>a>>b>>c; 
	bool flag = false; 
	for (int i = 0; i <= c/a; ++i) 
		if ( (c-i*a) % b == 0 ) 
		{
			flag = true;
			break; 
		}
	if ( flag ) cout<<"Yes\n"; 
	else cout<<"No\n";  
}