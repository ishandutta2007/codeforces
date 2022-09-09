#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, a,b, ta, tb;
char str[200100];
vector<int> vec;

int main() {
    int i;

    scanf("%d%d%d",&n,&a,&b);ta=a;tb=b;
    scanf("%s",str);
    int p = -1, res = 0;
    for (i=0;i<=n;i++) {
        if (i==n||str[i]=='*') {
            vec.push_back(i-p-1);
            p = i;
        }
        else res++;
    }
    for (int &v:vec) {
        a-=v/2;b-=v/2;
    }
    for (int &v:vec) {
        if (v%2) {
            if (a>b) a--;
            else b--;
        }
    }
    printf("%d\n",(ta-max(a,0))+(tb-max(b,0)));

    return 0;
}