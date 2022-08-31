#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int main()
{
	int a1,a2,t=0;
	cin>>a1>>a2;
	while(a1&&a2&&(a1>=2||a2>=2))
	{
		if(a1>a2) ++a2, a1-=2;
		else ++a1, a2-=2;
		++t;
	}
	cout<<t;
}