#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int n;
char stuff[200013];
multiset<char> has;

int main() {
    scanf("%d %s",&n,&stuff);
    int ans = 0;
    for (int i=0;i<n-1;i++) {
        has.insert(stuff[2*i]);
        if (!has.count((char) (stuff[2*i+1]+'a'-'A'))) ans+=1;
        else has.erase(has.find((char) (stuff[2*i+1]+'a'-'A')));
    }
    printf("%d\n",ans);

    return 0;
}