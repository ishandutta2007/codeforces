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

vector <string> v;
vector < pair <int, int> > of;

int main()
{   
    char c;
    string tmp;
    int i, j, lmax=0, lcur, f=0, sz, d;
    while((c=getchar())!=EOF)
    {
        if (c!='\n')
            tmp.push_back(c);
        else
        {
            v.push_back(tmp);
            if (tmp.length()>lmax) lmax=tmp.length();
            tmp.clear();
        }
    }
    if (!tmp.empty())
    {
        v.push_back(tmp);
        if (tmp.length()>lmax) lmax=tmp.length();
        tmp.clear();
    }
    sz=v.size();
    for(i=0; i<sz; i++)
    {
        lcur=v[i].length();
        d=(lmax-lcur)/2;
        if (2*d+lcur==lmax)
            of.push_back(make_pair(d,d));
        else
        {
            if (!f) of.push_back(make_pair(d,d+1));
            else of.push_back(make_pair(d+1,d));
            f^=1;
        }
    }
    for(i=0; i<=lmax+1; i++)
        putchar('*');
    putchar('\n');
    for(i=0; i<sz; i++)
    {
        putchar('*');
        for(j=0; j<of[i].first; j++)
            putchar(' ');
        cout << v[i];
        for(j=0; j<of[i].second; j++)
            putchar(' ');
        putchar('*');
        putchar('\n');
    }
    for(i=0; i<=lmax+1; i++)
        putchar('*');
}