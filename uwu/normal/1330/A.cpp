#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
    int t; cin >> t;
    while (t--){
        int n,x; cin >> n >> x;
        bool uwu[301];
        memset(uwu,false,sizeof uwu);
        for (int i=0,a;i<n;++i){
            cin >> a;
            uwu[a]=true;
        }
        int count=x,index=1;
        while (count>0&&index<=300){
            if (!uwu[index]){
                uwu[index]=true;
                count--;
            }
            index++;
        }
        for (int i=1;i<=300;++i){
            if (!uwu[i]){
                cout << i-1 << '\n';
                break;
            }
        }
    }    
}