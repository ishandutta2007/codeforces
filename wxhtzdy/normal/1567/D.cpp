#include <bits/stdc++.h>
#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
using namespace std;

int dig[15];
long long pw[15];

void init(int n){
    while(accumulate(dig, dig + 11, 0) < n){
        ff(i,0,13){
            if(dig[i + 1] > 0){
                dig[i] += 10;
                dig[i + 1]--;
                break;
            }
        }
    }
}

void klirr(){
    ff(i,0,14)dig[i]=0;
}

void solve(){
    klirr();
    string s;
    cin >> s;
    int n;
    cin >> n;
    reverse(s.begin(), s.end());
    ff(i,0,s.size()-1)dig[i] = s[i] - '0';
    init(n);
    vector<int> ans;
    ff(i,0,13){
        while(n > 1 && dig[i] > 0){
            ans.push_back(pw[i]);
            n--;
            dig[i]--;
        }
    }
    int sum = 0;
    ff(i,0,13){
        sum += pw[i] * dig[i];
    }
    ans.push_back(sum);
    ff(i,0,ans.size()-1)cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    pw[0] = 1;
    ff(i,1,14)pw[i] = pw[i - 1] * 10;
    int tt;
    cin >> tt;
    while(tt--)solve();
    return 0;
}