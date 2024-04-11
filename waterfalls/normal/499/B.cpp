#include <cstdio>
#include <map>
#include <string>

using namespace std;

int n,m;
map<string,string> words;
char first[11],second[11];
string word;

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        scanf(" %s %s",&first,&second);
        words[string(first)] = string(second);
    }
    for (int i=0;i<n;i++) {
        scanf(" %s",&first);
        word = string(first);
        if (words[word].size()<word.size()) printf("%s ",words[word].c_str());
        else printf("%s ",first);
    }

    return 0;
}