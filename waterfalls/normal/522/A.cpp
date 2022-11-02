#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int n;
map<string,int> ids;
char a[30],b[30];

int main() {
    scanf("%d",&n);
    ids[string("polycarp")] = 1;
    int ans = 1;
    for (int i=0;i<n;i++) {
        scanf(" %s %*s %s",&a,&b);
        for (int j=0;a[j]!='\0';j++) if (a[j]<'a') a[j]+='a'-'A';
        for (int j=0;b[j]!='\0';j++) if (b[j]<'a') b[j]+='a'-'A';
        ids[string(a)] = 1+ids[string(b)];
        ans = max(ans,ids[string(a)]);
    }
    printf("%d\n",ans);

    return 0;
}