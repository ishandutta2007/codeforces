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
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair

int m[5], l[5], r[5];

void correct(int ind)
{
    while(m[ind]>1)
    {
        if ((!(m[ind]&1)) && (!(m[ind+1]&1)))
        {
            cout << "/" << ind << endl;
            m[ind]>>=1;
            m[ind+1]>>=1;
        }
        else if (m[ind]&1)
        {
            cout << "+" << ind << endl;
            m[ind]++;
            m[ind+1]++;
        }
        else
        {
            cout << "+" << ind+1 << endl;
            m[ind+2]++;
            m[ind+1]++;
        }
    }
}

void correct2(int ind)
{
    cout << "+" << ind << endl;
    m[ind]++;
    m[r[ind]]++;
    cout << "+" << l[ind] << endl;
    m[ind]++;
    m[l[ind]]++;
    if (ind==3)
    {
        cout << "/2" << endl;
        m[2]>>=1;
        m[3]>>=1;
    }
    else
    {
        cout << "/4" << endl;
        m[4]>>=1;
        m[1]>>=1;
    }
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i;
    for(i=1; i<5; i++)
        cin >> m[i];
    l[1]=4; l[2]=1; l[3]=2; l[4]=3;
    r[1]=2; r[2]=3; r[3]=4; r[4]=1;
    correct(1);
    correct(2);
    while(m[3]>1 || m[4]>1)
    {
        if ((m[3]&1) && (m[4]&1))
        {
            cout << "+3" << endl;
            m[3]++;
            m[4]++;
        }
        while(!(m[3]&1) && !(m[4]&1))
        {
            cout << "/3" << endl;
            m[3]>>=1;
            m[4]>>=1;
        }
        if ((m[3]&1)+(m[4]&1)==1)
        {
            while ((m[3]&1) && m[3]>1)
            {
                cout << "+2" << endl;
                m[2]++;
                m[3]++;
                cout << "/2" << endl;
                m[2]>>=1;
                m[3]>>=1;
            }
            while ((m[4]&1) && m[4]>1)
            {
                cout << "+4" << endl;
                m[4]++;
                m[1]++;
                cout << "/4" << endl;
                m[4]>>=1;
                m[1]>>=1;
            }
            if (m[3]==1 && m[4]>1)
                correct2(4);
            if (m[4]==1 && m[3]>1)
                correct2(3);
        }
    }
}