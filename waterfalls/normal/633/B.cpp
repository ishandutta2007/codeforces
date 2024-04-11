#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

int main() {
    scanf("%d",&n);
    for (int i=5;i<=500000;i++) {
        int j = i;
        int cnt = 0;
        while (j) {
            cnt+=j/5;
            j/=5;
        }
        if (cnt==n) ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for (int i: ans) printf("%d ",i);
    printf("\n");

	return 0;
}