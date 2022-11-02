#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char one[1013];
char two[1013];

int main() {
    scanf("%d %s %s",&n,&one,&two);
    int ans = 0;
    for (int i=0;i<n;i++) ans+=min((one[i]-two[i]+10)%10,(two[i]-one[i]+10)%10);
    printf("%d\n",ans);

    return 0;
}