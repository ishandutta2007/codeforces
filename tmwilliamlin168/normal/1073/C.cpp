#include <bits/stdc++.h>
using namespace std;

int n, x, y;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s >> x >> y;
    if(abs(x)+abs(y)>n||n%2!=((x+y)&1)) {
        cout << -1;
        return 0;
    }
    auto aa=[&](char c, int a) {
        if(c=='U')
			y+=a;
		else if(c=='D')
			y-=a;
		else if(c=='L')
			x-=a;
		else
			x+=a;
    };
    for(int i=0; i<n; ++i)
        aa(s[i], -1);
    int ans=n;
    for(int i1=0, i2=0; i1<n; ++i1) {
        while(abs(x)+abs(y)>i2-i1) {
            if(i2>=n)
                break;
            aa(s[i2++], 1);
        }
        if(abs(x)+abs(y)>i2-i1)
            break;
        ans=min(i2-i1, ans);
        aa(s[i1], -1);
    }
    cout << ans;
}