#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, a, b;

vector<int> ans;

int main() {
    scanf("%d%d%d", &n, &a, &b);
    if (b != 0) {
        int sum = 2;
        ans.push_back(2);
        for (int i = 0; i < b; ++i) {
            ans.push_back(sum + 1);
            sum += sum + 1;
        }
    } else {
        if (a != 0) {
            ans.push_back(2);
            ans.push_back(1);
        }
    }
    for (int i = 0; i < a; ++i) {
        ans.push_back(max(3, ans.back() + 1));
    }
    while ((int)ans.size() < n) {
        ans.push_back(1);
    }
    if ((int)ans.size() > n) {
        printf("-1\n");
    } else {
        for (int i = 0; i < n; ++i) {
            printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}