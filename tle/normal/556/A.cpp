#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
int n,sb[1000];
string str;
int main()
{
	cin>>n>>str; 
	for(int i=0;i<str.length();i++) sb[str[i]]++;
	cout<<max(sb['0']-sb['1'],sb['1']-sb['0']);
}