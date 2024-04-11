#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::string str;

int qry(int a, int b, int c) {
    std::cout << "? " << a+1 << ' ' << b+1 << ' ' << c+1 << std::endl;
    if(str.empty()) std::cin >> a;
    else {
        a = str[a]-'0' + str[b]-'0' + str[c]-'0';
        a = a >= 2 ? 1 : 0;
        std::cout << a << std::endl;
    }
    return a;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        //std::cin >> str;
        std::vector<int> a(n/3);
        for(int i = 0; i < n/3; i++) {
            a[i] = qry(3*i, 3*i+1, 3*i+2);
        }
        bool special = true;
        for(auto val : a) special = special && val == a[0];
        std::vector<int> ans(n, -1);
        if(special) {
            assert(0);
            int got = (qry(0, 3, 4) != a[0] || qry(0, 3, 5) != a[0] || qry(0, 4, 5) != a[0]) ? 0 : (qry(1, 3, 4) != a[0] || qry(1, 3, 5) != a[0] || qry(1, 4, 5) != a[0] ? 1 : 2);
            for(int i = 0; i < n; i++) {
                ans[i] = a[0];
            }
            ans[got] = 1-a[0];
            for(int i = 1; i < n/3; i++) {
                if(qry(got, 3*i, 3*i+1) == ans[got]) {
                    if(qry(got, 3*i, 3*i+2) == ans[got]) {
                        ans[3*i] = ans[got];
                    } else {
                        ans[3*i+1] = ans[got];
                    }
                } else {
                    ans[3*i+2] = ans[got];
                }
            }
        } else {
            int zero = 0, one = 0;
            while(a[zero] != 0) zero++;
            while(a[one] != 1) one++;
            int vals[] = {qry(3*zero, 3*one, 3*one+1), qry(3*zero, 3*one, 3*one+2), qry(3*zero, 3*one+1, 3*one+2), 
                          qry(3*zero+1, 3*one, 3*one+1), qry(3*zero+1, 3*one, 3*one+2), qry(3*zero+1, 3*one+1, 3*one+2)};
            int got = -1;
            ans[3*one] = ans[3*one+1] = ans[3*one+2] = 1;
            ans[3*zero] = ans[3*zero+1] = ans[3*zero+2] = 0;
            int sum = vals[0] + vals[1] + vals[2] + vals[3] + vals[4] + vals[5];
            if(sum == 6) {
                got = 3*one;
            } else if(sum == 2) {
                if(vals[0] == 1 || vals[3] == 1) {
                    got = 3*one+2;
                    ans[3*one+2] = 0;
                } else if(vals[1] == 1 || vals[4] == 1) {
                    got = 3*one+1;
                    ans[3*one+1] = 0;
                } else {
                    got = 3*one;
                    ans[3*one] = 0;
                }
            } else {
                assert(sum == 4);
                if(vals[0] == 1 && vals[3] == 1) {
                    got = 3*one+2;
                    ans[3*one+2] = 0;
                } else if(vals[1] == 1 && vals[4] == 1) {
                    got = 3*one+1;
                    ans[3*one+1] = 0;
                } else {
                    got = 3*one;
                    ans[3*one] = 0;
                }
            }
            assert(got != -1);
            // 4 more queries
            int got1 = -1;
            int got0 = -1;
            if(ans[got] == 0) {
                // look for one
                got1 = got == 3*one ? 3*one+1 : 3*one;
                got0 = got;
            } else {
                // look for one
                got1 = got;
                vals[0] = qry(3*zero, 3*zero+1, got), vals[1] = qry(3*zero, 3*zero+2, got), vals[2] = qry(3*zero+1, 3*zero+2, got);
                if(vals[0] + vals[1] + vals[2] == 0) {
                    got0 = 3*zero;
                } else if(vals[0] == 0) {
                    got0 = 3*zero;
                    ans[3*zero+2] = 1;
                } else if(vals[1] == 0) {
                    got0 = 3*zero;
                    ans[3*zero+1] = 1;
                } else {
                    got0 = 3*zero+1;
                    ans[3*zero] = 1;
                }
            }
            assert(got0 != -1 && got1 != -1);
            for(int i = 0; i < n/3; i++) if(i != got0/3 && i != got1/3) {
                ans[3*i] = ans[3*i+1] = ans[3*i+2] = a[i];
                int val = a[i] == 1 ? got0 : got1;
                if(qry(3*i, 3*i+1, val) != a[i]) {
                    if(qry(3*i, 3*i+2, val) != a[i]) {
                        ans[3*i] = 1-a[i];
                    } else {
                        ans[3*i+1] = 1-a[i];
                    }
                } else if(qry(3*i, 3*i+2, val) != a[i]) {
                    ans[3*i+2] = 1-a[i];
                }
            }
        }
        std::cout << "!";
        int f = 0;
        for(int i = 0; i < n; i++) {
            if(ans[i] == 0) f++;
        }
        std::cout << ' ' << f;
        for(int i = 0; i < n; i++) {
            if(ans[i] == 0) {
                std::cout << ' ' << i+1;
            }
        }
        std::cout << std::endl;
    }
}