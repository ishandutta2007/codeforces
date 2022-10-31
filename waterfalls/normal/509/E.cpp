#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

char s[500013];
double harmonic[500013];

int main() {
    scanf("%s",&s);
    int len = strlen(s);
    harmonic[0] = 0;
    for (int i=1;i<=len;i++) harmonic[i] = harmonic[i-1]+1./i;
    double ans = 0;
    double cur = 0;
    for (int i=0;i<len;i++) {
        cur+=harmonic[len-i]-harmonic[i];
        if (s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='Y') ans+=cur;
    }
    printf("%1.8f\n",ans);

    return 0;
}