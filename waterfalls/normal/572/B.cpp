#include <cstdio>
#include <map>
#include <vector>

using namespace std;

map<int,int> buy;
map<int,int> sell;
int n,ss;

int main() {
scanf("%d%d",&n,&ss);
for (int i=0;i<n;i++) {
char c;
int p,q;
scanf(" %c%d%d",&c,&p,&q);
if (c=='B') {
buy[p]+=q;
} else sell[p]+=q;
}
vector<pair<int,int> > b,s;
for (auto i: buy) b.push_back(i);
for (auto i: sell) s.push_back(i);
int lim = ss;
if (lim>s.size()) lim = s.size();
for (int i=lim-1;i>=0;i--) printf("S %d %d\n",s[i].first,s[i].second);
lim = b.size()-ss;
if (lim<0) lim = 0;
for (int i=b.size()-1;i>=lim;i--) printf("B %d %d\n",b[i].first,b[i].second);
return 0;
}