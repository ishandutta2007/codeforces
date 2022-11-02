#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int a[30], b[30];

int main () {
    char s1[1010], s2[1010];
    cin >> s1 + 1 >> s2 + 1;
    int l1 = strlen(s1 + 1);
    int l2 = strlen(s2 + 1);
    for (int i = 1; i <= l1; i++)
        a[s1[i]-'a']++;
    for (int i = 1; i <= l2; i++)
        b[s2[i]-'a']++;
    int sum = 0;
    for (int i = 0; i <= 25; i++){
        if(a[i] == 0 && b[i]){
            cout << -1 << endl;
            return 0;
        }
        sum += min (a[i], b[i]);

    }
    if (sum) cout << sum;
    else cout << -1;
}