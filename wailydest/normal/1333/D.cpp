#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    char s[3000];
    scanf("%d%d%s", &n, &k, s);
    
    vector<vector<int> > toswap;
    vector<int> buf1, buf2;
    vector<int> *current, *next;
    int op = 0;
    current = &buf1;
    next = &buf2;
    for (int i = 0; i < n - 1; ++i) if (s[i] == 'R' && s[i + 1] == 'L') current->push_back(i);
    
    while (op <= n * n + 1 && !current->empty()) {
        toswap.push_back(*current);
        for (int i = 0; i < current->size(); ++i) {
            swap(s[current->at(i)], s[current->at(i) + 1]);
            if (s[current->at(i)] >= 1 && s[current->at(i) - 1] == 'R') next->push_back(current->at(i) - 1);
            if (s[current->at(i)] + 2 < n && s[current->at(i) + 2] == 'L') next->push_back(current->at(i) + 1);
            ++op;
        }
        swap(current, next);
        next->clear();
    }
    
    if (op == n * n + 2 || k < toswap.size() || k > op) {
        printf("-1\n");
        return 0;
    }
    
    vector<int> stack;
    op = (int)toswap.size();
    for (int i = (int)toswap.size() - 1; i >= 0; --i) {
        for (int j = (int)toswap[i].size() - 1; j >= 0; --j) {
            if (op < k) {
                stack.push_back(toswap[i][j]);
                toswap[i].pop_back();
                ++op;
            }
            else break;
        }
        if (toswap[i].empty()) {
            toswap.pop_back();
            --op;
        }
        if (op == k) break;
    }
    
    for (int i = 0; i < toswap.size(); ++i) {
        printf("%d ", (int)toswap[i].size());
        for (int j = 0; j < toswap[i].size(); ++j) printf("%d ", toswap[i][j] + 1);
        printf("\n");
    }
    for (int i = (int)stack.size() - 1; i >= 0; --i) printf("1 %d\n", stack[i] + 1);
    
    return 0;
}