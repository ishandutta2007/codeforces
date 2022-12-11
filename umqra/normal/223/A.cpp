#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int N = 2000000;
int seg[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    string str;
    cin >> str;
    stack <char> st;
    stack <int> num;    
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] == '(')
        {
            st.push(')');
            num.push(i);
        }
        else if (str[i] == '[')
        {
            st.push(']');
            num.push(i);
        }
        else
        {
            if (!st.empty() && st.top() == str[i])
            {
                seg[num.top()] = 1;
                seg[i] = 1;
                st.pop();
                num.pop();
            }
            else
            {   
                while (!st.empty())
                {                             
                    st.pop();
                    num.pop();
                }
                seg[i] = 2;
            }
        }                           
    }
    string best, loc = "";
    int t = -1, lt = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (seg[i] == 1)
        {
            loc += str[i];
            lt += (str[i] == '[') ? 1 : 0;
        }
        else
        {
            if (lt > t)
            {
                t = lt;
                best = loc;
            }
            loc = "";
            lt = 0;
        }
    }
    if (lt > t)
    {
        best = loc;
        t = lt;
    }
    if (t == -1)
        cout << 0;
    else
        cout << t << endl << best;

    return 0;
}