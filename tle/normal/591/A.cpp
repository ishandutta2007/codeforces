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
	double l,p,q;
	cin>>l>>p>>q;
	double qq=l/(p+q)*p;
	printf("%.4lf\n",qq);
}