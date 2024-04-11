#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

char n[100001];
vector<int> evens;

int main() {
    scanf(" %s",&n);
    int len = strlen(n);
    for (int i=0;i<len;i++) if ((n[i]-48)%2==0) evens.push_back(i);
    if (evens.size()==0) printf("-1\n");
    else {
        int where = 0;
        while (where<evens.size()-1 && n[evens[where]]>n[len-1]) where+=1;
        swap(n[evens[where]],n[len-1]);
        printf("%s\n",n);
    }
}