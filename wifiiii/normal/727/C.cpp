#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ret;
    cin >> ret;
    return ret;
}
int ans[5005];
int main() {
    int n;
    cin >> n;
    int s12 = ask(1, 2);
    int s13 = ask(1, 3);
    int s23 = ask(2, 3);
    int d23 = s12 - s13;
    ans[2] = (s23 + d23) / 2;
    ans[1] = s12 - ans[2];
    ans[3] = s23 - ans[2];
    for(int i = 4; i <= n; ++i) {
        ans[i] = ask(2, i) - ans[2];
    }
    cout<<"! ";
    for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
    cout<<endl;
}