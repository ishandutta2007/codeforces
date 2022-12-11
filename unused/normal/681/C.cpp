#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    int n;
    scanf("%d",&n);
        vector<pair<string, int>> vt;
    while (n--)
    {
        char op[111]; int num;
        scanf("%s%d",op,&num);


        if (op[0] == 'i')
        {
            vt.emplace_back(op, num);
            pq.push(num);
        }

        if (op[0] == 'r')
        {
            if (pq.empty())
            {
                vt.emplace_back("insert", 0);
            }
            else
            {
                pq.pop();
            }
            vt.emplace_back(op, 0);
        }

        if (op[0] == 'g')
        {
            while (pq.empty() == false && pq.top() < num)
            {
                vt.emplace_back("removeMin", 0);
                pq.pop();
            }

            if (pq.empty() || pq.top() != num)
            {
                vt.emplace_back("insert", num);
                pq.push(num);
            }

            vt.emplace_back("getMin", num);
        }
    }
    
    printf("%zd\n", vt.size());
    for (auto &&e : vt)
    {
        printf("%s", e.first.c_str());
        if (e.first[0] == 'r') printf("\n");
        else printf(" %d\n", e.second);
    }
}