#include <bits/stdc++.h>
using namespace std; const int n = 200005; int N, K;
int main(){
    cin >> N >> K;
    long long u = 0, s = 0;
    for(int i = 0; i <= N; ++i){
        long long a,c;
        if(i == N) a = 0;
        else cin >> a;
        c = u/K;
        if(u%K!=0) c++;
        s += c;
        //cout << c << " ";
        a -= c*K - u;
        a = max(a, (long long)0);
        u = a;
    }
    //cout << endl;
    cout << s << endl;

}