#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string a, b[5];

int main(){
    cin >> a;
    for(int i=0;i<5;i++)
        cin >> b[i];
    bool f=0;
    for(int i=0;i<5;i++){
        if(b[i][0]==a[0]||b[i][1]==a[1])f=1;
    }
    printf("%s\n",(f)?"YES":"NO");
    return 0;
}