#include <iostream>
#include <algorithm>

using namespace std;

struct my_str{
    string s;
    long long cnt_s, cnt_h;
    my_str() {};
    my_str(string s) {
        this->s = s;
        cnt_s = cnt_h = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 's') cnt_s++;
            else cnt_h++;
        }
    }
};

bool cmp(my_str a, my_str b) {
    return ((a.cnt_s * b.cnt_h) > (b.cnt_s * a.cnt_h));
}

long long f(string s) {
    long long ans = 0, cnt_h = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'h') cnt_h++;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 's') ans += cnt_h;
        else cnt_h--;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    my_str arr[n];
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        arr[i] = my_str(s);
    }
    sort(arr, arr + n, cmp);
    s = "";
    for (int i = 0; i < n; i++) {
        s += arr[i].s;
    }
    cout << f(s) << endl;
    return 0;
}