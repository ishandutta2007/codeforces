#include <bits/stdc++.h>
using namespace std;

int main()
{
    string f, r;
    bool dot = false;

    for (;;)
    {
        char ch;
        if (scanf(" %c",&ch) != 1) break;

        if (ch == '.') dot = true;
        else if (dot == false)
        {
            if (f.empty() && ch == '0') continue;
            f.push_back(ch);
        }
        else
        {
            r.push_back(ch);
        }
    }

    while (r.empty() == false && r.back() == '0') r.pop_back();

    if (f.empty())
    {
        int skipped = 0;
        while (r[skipped] == '0') skipped++;
        if (r.size() > skipped + 1) printf("%c.%s", r[skipped], &r[skipped + 1]);
        else printf("%c", r[skipped]);
        printf("E-%d\n", skipped + 1);
        return 0;
    }
    else
    {
        if (f.size() == 1 && r.empty())
        {
            printf("%s\n", &f[0]);
        }
        else
        {
            string rr = string(&f[1]) + r;
            while (rr.empty() == false && rr.back() == '0') rr.pop_back();
            if (rr.empty() == false) rr.insert(rr.begin(), '.');
            printf("%c%s", f[0], &rr[0]);
            if (f.size() >= 2) printf("E%d\n", (int)f.size() - 1);
        }
    }
}