#include <bits/stdc++.h>
using namespace std;

int s[100009];
int a[100009], n;
void imp() {
    puts("NO");
}
void pos() {
    puts("YES");
    for(int i = 0; i < n; i++)
        printf("%d ", s[i] - 1);
    putchar('\n');
}

int ign[100009];
map<int, int> nu;
int main() {
    int A, B, i;
    scanf("%d %d %d", &n, &A, &B);
    bool ok = true;
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] >= A && a[i] >= B) ok = false; 
        nu[a[i]] = i;
    }
    if(!ok) { imp(); return 0; }
    if(A == B) {
        for(i = 0; i < n; i++) {
            if(!nu.count(A - a[i])) { imp(); return 0; }
            s[i] = 1;
        }
        pos();
        return 0;
    }
    vector<int> d0;
    for(i = 0; i < n; i++) {
        bool hasA = nu.count(A - a[i]);
        bool hasB = nu.count(B - a[i]);
        if(!hasA && !hasB) { imp(); return 0; }
        if(hasA ^ hasB) d0.push_back(i);
    }
    while(!d0.empty()) {
        int x = d0.back();      
        d0.pop_back();
        if(ign[x]) continue;
        //printf("seeing %d (%d)\n", x, a[x]);
        if(nu.count(A - a[x])) {
            s[x] = 1; s[nu[A - a[x]]] = 1;
            if(nu.count(B - (A - a[x])) && ((B - (A - a[x])) != (A - a[x]))) d0.push_back(nu[B - (A - a[x])]);
            else ign[nu[A - a[x]]] = 1;
            //printf("erasing %d and %d\n", a[x], A - a[x]);
            nu.erase(a[x]); nu.erase(A - a[x]);
        } else if(nu.count(B - a[x])) {
            s[x] = 2; s[nu[B - a[x]]] = 2;
            if(nu.count(A - (B - a[x])) && ((A - (B - a[x])) != (B - a[x]))) d0.push_back(nu[A - (B - a[x])]);
            else ign[nu[B - a[x]]] = 1;
            //printf("erasing %d and %d\n", a[x], B - a[x]);
            nu.erase(a[x]); nu.erase(B - a[x]);
        } else {
            if(a[x] == (A - a[x])) { s[x] = 1; continue; }
            if(a[x] == (B - a[x])) { s[x] = 2; continue; }
            imp();
            return 0;
        }
    }
    pos(); 
}