#include <iostream>
#include <string>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

    string str;
    cin >> str;
    bool t = false;
    for (int i = 0; i < (int)str.length(); i++)
    {
    	if (t)
    		cout << str[i];
    	else
    	{
    		if (str[i] == '0' || i == (int)str.length() - 1)
    		{
    			t = true;
    		}
    		else
    			cout << str[i];
    	}
    }
	
	return 0;
}