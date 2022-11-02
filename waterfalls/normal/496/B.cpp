#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    vector<char> num;
    vector<char> ans;
    char c;
    for (int i=0;i<n;i++) {
        scanf(" %c",&c);
        num.push_back(c);
        ans.push_back(c);
    }
    for (int i=0;i<n;i++) {
        int diff = num[i]-'0';
        vector<char> cur;
        for (int j=0;j<n;j++) cur.push_back((char) ((num[(i+j)%n]-48-diff+10)%10+48));
        int flag = 1;
        for (int j=0;j<n && flag;j++) {
            if (ans[j]>cur[j]) {
                ans = cur;
                flag = 0;
            } else if (ans[j]<cur[j]) flag = 0;
        }
    }
    for (int i=0;i<n;i++) printf("%c",ans[i]);
    printf("\n");

    return 0;
}