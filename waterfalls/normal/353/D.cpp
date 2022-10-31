#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int ans = 0;
    int numOfF = 0;
    int BsLeft = 0;
    char next;
    while (true) {
        scanf("%c",&next);
        if (next=='M') {
            BsLeft+=1;
            if (numOfF) numOfF-=1;
        } else if (next=='F') {
            if (BsLeft!=0) {
                ans = max(ans,BsLeft+numOfF);
                numOfF+=1;
            }
        } else break;
    }
    printf("%d\n",ans);

    return 0;
}