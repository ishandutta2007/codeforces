#include <bits/stdc++.h>
using namespace std;

char str[100005];
int last[26];

int main()
{
    scanf("%s",str);

    stack<char> stk;
    for (int i = 0; i < 26; i++) last[i] = -1;

    for (int i = 0; str[i]; i++) last[str[i] - 'a'] = i;

    int ptr = 0;
    for (int i = 'a'; i <= 'z'; i++)
    {
        while (stk.empty() == false && stk.top() <= i)
        {
            printf("%c", stk.top());
            stk.pop();
        }
        while (str[ptr] && ptr <= last[i - 'a'])
        {
            stk.push(str[ptr++]);
            while (stk.empty() == false && stk.top() <= i)
            {
                printf("%c", stk.top());
                stk.pop();
            }
        }
    }
    printf("\n");
}