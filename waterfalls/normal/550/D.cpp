#include <cstdio>
#include <algorithm>

using namespace std;

int k;

int on;
int make() { return on++; }

vector<int> other;
int one() {
    int head = make();
    other.clear();
    for (int i=0;i<k-1;i++) other.push_back(make());
    for (int& i: other) printf("%d %d\n",head,i);
    if (k!=1) {
        int a = make();
        int b = make();
        for (int& i: other) printf("%d %d\n",a,i);
        for (int& i: other) printf("%d %d\n",b,i);
        printf("%d %d\n",a,b);
        for (int& i: other) for (int& j: other) {
            if (i<=j || abs(j-i)==(k-1)/2) continue;
            printf("%d %d\n",i,j);
        }
    }
    return head;
}

void build() {
    int V = k==1 ? 2 : 2*(k+2);
    printf("%d %d\n",V,V*k/2);
    on = 1;
    int a = one();
    int b = one();
    printf("%d %d\n",a,b);
}

int main() {
    scanf("%d",&k);
    if (k%2==0) printf("NO\n");
    else {
        printf("YES\n");
        build();
    }

    return 0;
}