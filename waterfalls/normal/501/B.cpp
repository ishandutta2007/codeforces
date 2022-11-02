#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int q;
char aC[25],bC[25];
string a,b;
vector<string> olds;
vector<string> news;
map<string,int> ids;

int main() {
    scanf("%d",&q);
    for (int i=0;i<q;i++) {
        scanf(" %s %s",&aC,&bC);
        a = string(aC); b = string(bC);
        if (!ids.count(a)) {
            ids[a] = olds.size();
            olds.push_back(a);
            news.push_back(a);
        }
        ids[b] = ids[a];
        news[ids[a]] = b;
    }
    printf("%d\n",olds.size());
    for (int i=0;i<olds.size();i++) {
        printf("%s %s\n",olds[i].c_str(),news[i].c_str());
    }

    return 0;
}