#include <bits/stdc++.h>
using namespace std;

vector<int> vt;
int dat[105];

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < k; i++) scanf("%d",&dat[i]);
    for (int i = 1; i <= n; i++) vt.push_back(i);
    int ptr = 0;

    for (int i = 0; i < k; i++)
    {
        int nxt = (ptr + dat[i]) % vt.size();
        printf("%d ", vt[nxt]);
        vt.erase(vt.begin() + nxt);
        ptr = nxt;
    }
    printf("\n");
}