#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int n;
map<int,int> first;
map<int,int> second;
map<int,int> third;

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        first[a]+=1;
    }
    for (int i=0;i<n-1;i++) {
        int a;
        scanf("%d",&a);
        second[a]+=1;
    }
    for (map<int,int>::iterator it=first.begin();it!=first.end();it++) if (second[it->first]<it->second) printf("%d\n",it->first);
    for (int i=0;i<n-2;i++) {
        int a;
        scanf("%d",&a);
        third[a]+=1;
    }
    for (map<int,int>::iterator it=second.begin();it!=second.end();it++) if (third[it->first]<it->second) printf("%d\n",it->first);

    return 0;
}