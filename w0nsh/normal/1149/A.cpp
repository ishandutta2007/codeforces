#include <bits/stdc++.h>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        std::cin >> A[i];
        if(A[i] == 1) cnt++;
    }
    std::sort(A.begin(), A.end());
    int xd = std::lower_bound(A.begin(), A.end(), 2)-A.begin();
    if(xd < n) std::swap(A[0], A[xd]);
    if(cnt % 2 == 0 && xd < n && n > 2) std::swap(A[xd], A.back());
    for(int i = 0; i < n; ++i) std::cout << A[i] << " ";
    return 0;
}