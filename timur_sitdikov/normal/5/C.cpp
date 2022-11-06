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

char c[1000005], c1[1000005];
set <int> st;

int main()
{   
    int i, ans=1, mx=0, cur=0, b=0, l, pos;
    scanf("%s", &c);
    l=strlen(c);
    for(i=0; i<l; i++)
    {
        c1[l-1-i]=c[i];
        if (c[i]=='(') 
        {
            b++; cur++;
        }
        else 
        {
            b--;
            if (b>=0) cur++;
            if (b==0)
            {
                if (cur>mx) 
                {mx=cur; ans=1; st.clear(); st.insert(i);}
                else if (cur==mx) 
                {ans++; st.insert(i);}
            }
            if (b==-1) {cur=0; b=0;}
        }
    }
    for(i=0; i<l; i++)
        if (c1[i]=='(') c1[i]=')';
        else c1[i]='(';
    for(i=0; i<l; i++) c[i]=c1[i];
    cur=b=0;
    for(i=0; i<l; i++)
    {
        c1[l-1-i]=c[i];
        if (c[i]=='(') 
        {
            b++; cur++;
        }
        else 
        {
            b--;
            if (b>=0) cur++;
            if (b==0)
            {
                pos=i-cur;
                pos=l-2-pos;
                if (cur>mx && st.find(pos)==st.end()) 
                {mx=cur; ans=1;}
                else if (cur==mx && st.find(pos)==st.end()) 
                    ans++;
            }
            if (b==-1) {cur=0; b=0;}
        }
    }
    if (mx==0) ans=1;
    printf("%d %d", mx, ans);
}