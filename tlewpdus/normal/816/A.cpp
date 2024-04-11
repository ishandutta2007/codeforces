#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

char str[10];

int rev(int a) {
    return (a%10)*10+a/10;
}

int main() {
    int i, m, h, cnt = 0;

    scanf("%s",str);
    h = ((str[0]-'0')*10+(str[1]-'0'));
    m = ((str[3]-'0')*10+(str[4]-'0'));
    while(rev(m)!=h) {
        m++;
        if (m==60) {h++; m = 0;}
        if (h==24) h = 0;
        cnt++;
    }
    printf("%d\n",cnt);

    return 0;
}