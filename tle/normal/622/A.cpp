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
long long x;
int main()
{
	cin>>x;
	for(int i=1;x>i;i++) x-=i;
	cout<<x<<"\n";
}