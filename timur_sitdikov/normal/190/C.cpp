#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

stack <int> stk;
string ans;

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, f=0, tmp, f1=0;
    char c[10];
    string str;
    cin >> n;
    while(scanf("%s", &c)==1)
    {
        if (f1) {printf("Error occurred"); return 0;}
        str=c;
        if (str=="pair")
        {
            while(!stk.empty() && stk.top()==2) {ans+=">"; stk.pop();}
            if (stk.empty() && f) {printf("Error occurred"); return 0;}
            if (!stk.empty())
            {
                if (stk.top()==1) ans+=",";
                tmp=stk.top();
                stk.pop();
                stk.push(tmp+1);
            }
            stk.push(0);
            ans+="pair<";
        }
        else
        {
            while(!stk.empty() && stk.top()==2) {ans+=">"; stk.pop();}
            if (stk.empty() && f) {printf("Error occurred"); return 0;}
            if (stk.empty()) f1=1;
            else
            {
                if (stk.top()==1) ans+=",";
                tmp=stk.top();
                stk.pop();
                stk.push(tmp+1);
            }
            ans+="int";
        }
        f=1;
    }
    while(!stk.empty() && stk.top()==2) {ans+=">"; stk.pop();}
    if (!stk.empty()) {printf("Error occurred"); return 0;}
    cout << ans;
}