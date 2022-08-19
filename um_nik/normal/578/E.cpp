#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int N = 100100;
string s;
int b[N];
vector<int> a[N];
vector<int> L, R;
int sz;
int n;
vector<int> LL, LR, RL, RR;

void print(int id)
{
    for (int x : a[id])
        printf("%d ", x + 1);
    return;
}

void printAnswer()
{
    if (RR.size() > LL.size())
    {
        for (int x : RL)
            print(x);
        for (int i = 0; i < (int)RR.size(); i++)
        {
            print(RR[i]);
            if (i < (int)LL.size())
                print(LL[i]);
        }
        for (int x : LR)
            print(x);
        printf("\n");
        return;
    }
    if (RR.size() < LL.size())
    {
        for (int x : LR)
            print(x);
        for (int i = 0; i < (int)LL.size(); i++)
        {
            print(LL[i]);
            if (i < (int)RR.size())
                print(RR[i]);
        }
        for (int x : RL)
            print(x);
        printf("\n");
        return;
    }
    if (!LL.empty())
    {
        for (int x : LR)
            print(x);
        print(LL[0]);
        for (int x : RL)
            print(x);
        for (int i = 0; i < RR.size(); i++)
        {
            if (i != 0)
                print(LL[i]);
            print(RR[i]);
        }
        printf("\n");
        return;
    }
    if (!RR.empty())
    {
        for (int x : RL)
            print(x);
        print(RR[0]);
        for (int x : LR)
            print(x);
        for (int i = 0; i < LL.size(); i++)
        {
            if (i != 0)
                print(RR[i]);
            print(LL[i]);
        }
        printf("\n");
        return;
    }
    throw;
}

int main()
{
    cin >> s;
    n = (int)s.length();
    sz = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            if (R.empty())
            {
                R.push_back(sz);
                sz++;
            }
            int x = R.back();
            R.pop_back();
            a[x].push_back(i);
            L.push_back(x);
            b[i] = x;
        }
        else
        {
            if (L.empty())
            {
                L.push_back(sz);
                sz++;
            }
            int x = L.back();
            L.pop_back();
            a[x].push_back(i);
            R.push_back(x);
            b[i] = x;
        }
    }
    printf("%d\n", sz - 1);

    for (int i = 0; i < sz; i++)
    {
        if (s[a[i][0]] == 'L')
        {
            if (s[a[i].back()] == 'L')
                LL.push_back(i);
            else
                LR.push_back(i);
        }
        else
        {
            if (s[a[i].back()] == 'L')
                RL.push_back(i);
            else
                RR.push_back(i);
        }
    }
    if (LL.empty() && RR.empty())
    {
        if (LR.empty() || RL.empty())
        {
            for (int i = 0; i < sz; i++)
                print(i);
            printf("\n");
            return 0;
        }
        if (s[n - 1] == 'L')
        {
            int x = b[n - 1];
            a[x].pop_back();
            int y = LR.back();
            LR.pop_back();
            a[y].push_back(n - 1);
            LL.push_back(y);
            RR.push_back(x);
            for (int i = 0; i < (int)RL.size(); i++)
            {
                if (RL[i] == x)
                {
                    swap(RL[i], RL.back());
                    RL.pop_back();
                    break;
                }
            }
        }
        else
        {
            int x = b[n - 1];
            a[x].pop_back();
            int y = RL.back();
            RL.pop_back();
            a[y].push_back(n - 1);
            RR.push_back(y);
            LL.push_back(x);
            for (int i = 0; i < (int)LR.size(); i++)
            {
                if (LR[i] == x)
                {
                    swap(LR[i], LR.back());
                    LR.pop_back();
                    break;
                }
            }
        }
    }

    printAnswer();

    return 0;
}