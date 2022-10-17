#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>

int n, K;
std::vector<int> a;

void answer(){
    std::sort(a.begin(), a.end());
    int eaten = 0;
    int same_number = 0;
    for(int i = 1; i < n; ++i){
        if(a[i] == a[i-1]) same_number++;
        else{
            if(a[i-1] + K >= a[i]){
                eaten += 1 + same_number;
            }
            same_number = 0;
        }
    }
    std::printf("%d\n", (int)(a.size()-eaten));
}

void read(){
    std::scanf("%d%d", &n, &K);
    a.resize(n);
    for(int i = 0; i < n; ++i) std::scanf("%d", &a[i]);
}

int main(){
    read();
    answer();
    return 0;
}