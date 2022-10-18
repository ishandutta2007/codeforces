#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

string s;
bool f1[N], f2[N];
int n;
//fuyu
bool get1(int i){
    if (i < 0) return 0;
    return f1[i];
}

bool get2(int i){
    if (i < 0) return 0;
    return f2[i];
}

int main(){
    cin >> s;
    n = s.length();
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    bool found = 0;
    for (int i = 1; i < n; i++){
        if (s[i - 1] == 'A' && s[i] == 'B'){
            found |= get2(i - 2);
            f1[i] = 1;
        }
        if (s[i - 1] == 'B' && s[i] == 'A'){
            found |= get1(i - 2);
            f2[i] = 1;
        }
        f1[i] |= f1[i - 1];
        f2[i] |= f2[i - 1];
    }
    if (found) printf("YES\n");
    else printf("NO\n");
}