#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
char str[150100];

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%s",str);
        n = strlen(str);
        vector<int>vec;
        for (int i=0;i+4<n;i++) {
            if (strncmp(str+i,"twone",5)==0) {
                str[i+2]='X';
                vec.push_back(i+2);
            }
        }
        for (int i=0;i+2<n;i++){
            if (strncmp(str+i,"two",3)==0||strncmp(str+i,"one",3)==0) {
                str[i+1]='X';
                vec.push_back(i+1);
            }
        }
        printf("%d\n",vec.size());
        for (int &v : vec)printf("%d ",v+1);
        puts("");
    }

	return 0;
}