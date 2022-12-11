#include <bits/stdc++.h>
using namespace std;
 
int process(int *arr, int *cand, int size)
{
        bitset<200> visit;
 
        int ret = -1;
 
        for (int i = 0; i < size - 1; i++) visit[arr[i]] = true;
        for (int i = 0; i < size; i++)
        {
                if (!visit[cand[i]])
                {
                        if (ret == -1) ret = cand[i];
                        else return -1;
                }
        }
 
        return ret;
}
 
int main()
{
        int T;
        scanf("%d",&T);
        while (T--)
        {
                int n;
                scanf("%d",&n);
 
                int dat[200][200];
                int cnt[200];
                int ans[200];
 
                for (int i = 0; i < n - 1; i++)
                {
                        scanf("%d", &cnt[i]);
                        for (int j = 0; j < cnt[i]; j++) scanf("%d", &dat[i][j]);
                }
 
                bool yes = false;
 
                for (int i = 0; i < n - 1; i++)
                {
                        if (cnt[i] != 2) continue;
 
                        for (int o = 0; o < 2; o++)
                        {
                                ans[0] = dat[i][o];
                                ans[1] = dat[i][o ^ 1];
                                
                                bool visit[n] = {};
                                visit[i] = true;
 
                                bool wrong = false;
                                for (int k = 2; k < n; k++)
                                {
                                        bool found = false;
                                        for (int nxt = 0; nxt < n - 1; nxt++)
                                        {
                                                if (visit[nxt] || cnt[nxt] > k + 1) continue;
                                                if (int r = process(&ans[k + 1 - cnt[nxt]], dat[nxt], cnt[nxt]); r != -1)
                                                {
                                                        ans[k] = r;
                                                        visit[nxt] = true;
                                                        found = true;
                                                        break;
                                                }
                                        }
                                        if (!found)
                                        {
                                                wrong = true;
                                                break;
                                        }
                                }
 
                                if (!wrong)
                                {
                                        yes = true;
                                        break;
                                }
                        }
 
                        if (yes) break;
                }
 
                for (int i = 0; i < n; i++) printf("%d ", ans[i]);
                printf("\n");
        }
}