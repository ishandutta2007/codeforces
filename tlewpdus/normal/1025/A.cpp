#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
char str[100100];
int cnt[30];

int main() {
    int i;

    scanf("%d",&n);
    scanf("%s",str);
    for (i=0;i<n;i++) cnt[str[i]-'a']++;
    bool flag = true;
    for (i=0;i<26;i++) {
        if (cnt[i]>1) flag = false;
    }
    puts((n!=1&&flag)?"No":"Yes");

    return 0;
}