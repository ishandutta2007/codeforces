#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
char dat[55];
string names[55];

int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= 26; i++)
    {
        names[i].push_back('A' + i - 1);
    }
    for (int i = 27; i <= 50; i++)
    {
        names[i].push_back('A');
        names[i].push_back('a' + i - 27);
    }

    for (int i = 0; i < n; i++) ans.push_back(i + 1);

    for (int i = 0; i < n - k + 1; i++)
    {
        char zzz[11];
        scanf("%s",zzz);
        if (zzz[0] == 'N')
        {
            ans[i+k-1] = ans[i];
        }
    }

    for (int i = 0; i < n; i++) printf("%s ", names[ans[i]].c_str());
    printf("\n");
}