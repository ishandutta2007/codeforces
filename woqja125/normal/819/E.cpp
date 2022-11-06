#include <cstdio>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> a3;
vector<tuple<int, int, int, int>> a4;

void add(int a, int b, int c) {
    a3.emplace_back(a+1, b+1, c+1);
}
void add(int a, int b, int c, int d) {
    a4.emplace_back(a+1, b+1, c+1, d+1);
}

int main() {
    int n;
    scanf("%d", &n);
    int x, y, w;
    int mode = n%4;
    if(mode >= 2) {
        x = n/4*4;
        y = n/4*4+1;
    }
    if(mode == 1)
        w = n/4*4;
    if(mode == 3)
        w = n/4*4+2;

    for(int i=0; i<n/4; i++) {
        int b = i*4;

        if(mode&1) {
            add(b, b+1, w, b+3);
            add(w, b+1, b+3);
            add(b, w, b+2, b+3);
            add(w, b, b+2);
        }
        else {
            add(b, b+1, b+3);
            add(b, b+2, b+3);
        }
        add(b, b+1, b+2);
        add(b+3, b+1, b+2);

        if(mode >= 2) {
            if(mode == 2 && i == 0) {
                add(x, y, b);
                add(x, y, b+1);
                add(x, b, y, b+1);
            }
            else {
                add(x, b, y, b+1);
                add(x, b, y, b+1);
            }
            add(x, b+2, y, b+3);
            add(x, b+2, y, b+3);
        }

        for(int j=i+1; j<n/4; j++) {
            for(int u=i*4; u<i*4+4; u+=2) for(int v=j*4; v<j*4+4; v+=2) {
                add(u, v, u+1, v+1);
                add(u, v, u+1, v+1);
            }
        }
    }

    if(mode == 3) {
        add(x, y, w);
        add(x, y, w);
    }

    printf("%lu\n", a3.size() + a4.size());
    for(auto [a, b, c, d]: a4) printf("4 %d %d %d %d\n", a, b, c, d);
    for(auto [a, b, c]: a3) printf("3 %d %d %d\n", a, b, c);

    return 0;
}