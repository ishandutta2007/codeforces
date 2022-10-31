#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int val[10];
int len[10];
char s[100001];
int n;
char query[100013];
vector<pair<int,vector<char> > > queries;
int MOD = 1000000007;

int expo(int len) {
    int ans = 1;
    int cur = 10;
    for (int i=0;i<31;i++) {
        if (len&(1<<i)) ans = ((long long) ans*cur)%MOD;
        cur = ((long long) cur*cur)%MOD;
    }
    return ans;
}

int main() {
    for (int i=0;i<10;i++) {
        val[i] = i;
        len[i] = 1;
    }
    scanf(" %s%d",&s,&n);
    int sLen = strlen(s);
    queries.push_back(make_pair(0,vector<char>()));
    for (int i=0;i<sLen;i++) queries[0].second.push_back(s[i]);
    for (int i=1;i<=n;i++) {
        scanf(" %s",&query);
        int queryLen = strlen(query);
        queries.push_back(pair<int,vector<char> >());
        queries[i].first = query[0]-48;
        for (int j=3;j<queryLen;j++) queries[i].second.push_back(query[j]);
    }
    for (int i=n;i>=0;i--) {
        int from = queries[i].first;
        vector<char> to = queries[i].second;
        int nLen = 0;
        for (int j=0;j<to.size();j++) nLen = (nLen+len[to[j]-48])%(MOD-1);
        int nVal = 0;
        int tens = 1;
        for (int j=0;j<to.size();j++) {
            nVal = (nVal+(long long) tens*val[to[to.size()-j-1]-48])%MOD;
            tens = ((long long) tens*expo(len[to[to.size()-j-1]-48]))%MOD;
        }
        val[from] = nVal;
        len[from] = nLen;
    }
    printf("%d\n",val[0]);

    return 0;
}