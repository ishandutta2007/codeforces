#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
                     
string str;

void printStr(int a, int b)
{
	putchar('<');
	for (int i = a; i <= b; i++)
		putchar(str[i]);
	putchar('>');
	puts("");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
                        
	getline(cin, str);
                         
    int n = (int)str.length();
    int st = -1;
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
    	if (str[i] != ' ')
    	{
    		if (str[i] == '"')
    		{
    			if (flag)
    			{
    				flag = false;
    				printStr(st, i - 1);
    				st = -1; 
    			}
    			else
    			{
    				flag = true;
    				st = i + 1;   
    			}
    		}
    		else
    		{
    			if (st == -1)
    				st = i;
    		}
    	}
    	else
    	{
    		if (st != -1 && !flag)
    		{
    			printStr(st, i - 1);
    			st = -1;
    		}
    	}
    }

    if (st != -1)
    	printStr(st, n - 1);
	
	return 0;
}