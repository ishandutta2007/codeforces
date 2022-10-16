#include<bits/stdc++.h>
using namespace std;
int main()
{long long a;cin>>a;
	int b=1;
	while(to_string(++a).find('8')==string::npos)    b++;
    cout << b;}