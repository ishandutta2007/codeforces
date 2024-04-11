#include <bits/stdc++.h>
using namespace std;

const int N = 300001, K = 300;
unordered_map<long long, int> mp;

vector<int> c[N];
int pos[N];

vector<pair<int, int>> vc[N];
int by[N];

int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        mp.clear();
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)
        {
            vc[i].clear();
            by[i] = 0;
            pos[i] = -1;
        }
        for(int i = 0; i < q; i++)
        {
            int k;
            scanf("%d", &k);
            c[i].resize(k);
            for(int j = 0; j < c[i].size(); j++)
            {
                scanf("%d", &c[i][j]);
                if(k <= K && j + 1 < k)
                    vc[c[i][j]].emplace_back(i, j);
            }
        }
        
        bool human = false;
        for(int i = 0; i < q; i++)
            if(c[i].size() > K)
            {
                for(int j = 0; j < c[i].size(); j++)
                    pos[c[i][j]] = j;
                for(int j = 0; j < q; j++)
                    if(i != j)
                    {
                        //printf("%d %d: ", i, j);
                        int prev = n + 1;
                        bool com = false;
                        for(int x: c[j])
                        {
                            //printf("(%d %d) ", prev, pos[x]);
                            if(pos[x] == -1)
                                com = false;
                            else
                            {
                                if(pos[x] < prev || (com && pos[x] == prev + 1))
                                {
                                    prev = pos[x];
                                    com = true;
                                }
                                else
                                {
                                    human = true;
                                    goto end;
                                    break;
                                }
                            }
                        }
                        //puts("");
                    }
                for(int x: c[i])
                    pos[x] = -1;
            }
        for(int i = 1; i <= n; i++)
        {
            for(auto p: vc[i])
            {
                int k = p.first, t = p.second, b = c[k][t+1];
                for(int j = t + 1; j < c[k].size(); j++)
                {
                    if(by[c[k][j]] == 0) by[c[k][j]] = c[k][t+1];
                    else if(by[c[k][j]] != c[k][t+1])
                    {
                        human = true;
                        goto end;
                    }
                }
            }
            for(auto p: vc[i])
            {
                int k = p.first, t = p.second;
                for(int j = t + 1; j < c[k].size(); j++)
                    by[c[k][j]] = 0;
            }
        }
        
end:
        puts(human ? "Human" : "Robot");
    }
}