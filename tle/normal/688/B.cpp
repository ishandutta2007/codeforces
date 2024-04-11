#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
string s;
int main()
{
	cin>>s;
	cout<<s;
	reverse(s.begin(),s.end());
	cout<<s;
}