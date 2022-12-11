#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair
const int N = (int)1e5;

int cnt[100];
int ansA[N], ansB[N], ansC[N];
int ind;

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }

    if (cnt[7] != 0 || cnt[5] != 0)
    {
        puts("-1");
        return 0;
    }
             
    while (1)
    {
        if (cnt[1] == 0 || cnt[3] == 0 || cnt[6] == 0)
            break;
        ansA[ind] = 1;
        ansB[ind] = 3;
        ansC[ind++] = 6;
        cnt[1]--;
        cnt[3]--;
        cnt[6]--;
    }

    int t = cnt[2];
    for (int i = 0; i < t; i++)
    {   
        if (cnt[1] == 0 || (cnt[4] == 0 && cnt[6] == 0))
        {
            puts("-1");
            return 0;
        }        
        if (cnt[4] > 0)
        {
            ansA[ind] = 1;
            ansB[ind] = 2;
            ansC[ind++] = 4;
            cnt[1]--;
            cnt[2]--;
            cnt[4]--;
        }
        else if (cnt[6] > 0)
        {
            ansA[ind] = 1;
            ansB[ind] = 2;
            ansC[ind++] = 6;
            cnt[1]--;
            cnt[2]--;
            cnt[6]--;
        }
    }   

    for (int i = 0; i < 8; i++)
    {
        if (cnt[i] > 0)
        {
            puts("-1");
            return 0;
        }
    }

    for (int i = 0; i < ind; i++)
    {
        printf("%d %d %d\n", ansA[i], ansB[i], ansC[i]);
    }

    return 0;
}