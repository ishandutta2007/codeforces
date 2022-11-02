#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> digits;
vector<int> print;

int main() {
    scanf("%d",&n);
    for (int i=0;i<7;i++) digits.push_back(n%10), n/=10;
    reverse(digits.begin(),digits.end());
    while (true) {
        int cur = 0;
        for (int i=0;i<7;i++) {
            cur*=10;
            if (digits[i]) cur+=1, digits[i]-=1;
        }
        if (cur) print.push_back(cur);
        else break;
    }
    printf("%d\n",print.size());
    for (int i=0;i<print.size();i++) printf("%d ",print[i]);

    return 0;
}