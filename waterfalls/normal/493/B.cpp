#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    vector<int> first;
    vector<int> second;
    long long score1 = 0;
    long long score2 = 0;
    int last;
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        if (a>0) {
            first.push_back(a);
            score1+=a;
            last = 1;
        } else {
            second.push_back(-a);
            score2+=-a;
            last = 2;
        }
    }
    if (score1>score2) printf("first\n");
    else if (score2>score1) printf("second\n");
    else {
        bool flag = true;
        for (int i=0;i<min(first.size(),second.size()) && flag;i++) {
            if (first[i]>second[i]) {
                printf("first\n");
                flag = false;
            } else if (second[i]>first[i]) {
                printf("second\n");
                flag = false;
            }
        }
        if (flag) {
            if (first.size()>second.size()) printf("first\n");
            else if (second.size()>first.size()) printf("second\n");
            else {
                if (last==1) printf("first\n");
                else printf("second\n");
            }
        }
    }

    return 0;
}