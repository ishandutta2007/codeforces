#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int N = 1e5 + 5;
int main()
{
    int T;
    cin>>T;
    while (T--){
        string S;
        cin>>S;
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < S.size(); i++){
            if ('0' <= S[i] && S[i] <= '9')
                x++;
            else if ('a' <= S[i] && S[i] <= 'z')
                y++;
            else
                z++;
        }
        if (x > 0 && y > 0 && z > 0){
            cout<<S<<endl;
            continue;
        }
        if (x + y == 0){
            S[0] = '1';
            S[1] = 'a';
            cout<<S<<endl;
            continue;
        }
        if (x + z == 0){
            S[0] = '1';
            S[1] = 'A';
            cout<<S<<endl;
            continue;
        }
        if (y + z == 0){
            S[0] = 'a';
            S[1] = 'A';
            cout<<S<<endl;
            continue;
        }
        if (x == 0){
            if (y > 1){
                for (int i = 0; i < S.size(); i++)
                    if ('a' <= S[i] && S[i] <= 'z'){
                        S[i] = '0';
                        break;
                    }
                cout<<S<<endl;
                continue;
            }
            if (z > 1){
                for (int i = 0; i < S.size(); i++)
                    if ('A' <= S[i] && S[i] <= 'Z'){
                        S[i] = '0';
                        break;
                    }
                cout<<S<<endl;
                continue;
            }
        }
        if (y == 0){
            if (x > 1){
                for (int i = 0; i < S.size(); i++)
                    if ('0' <= S[i] && S[i] <= '9'){
                        S[i] = 'a';
                        break;
                    }
                cout<<S<<endl;
                continue;
            }
            if (z > 1){
                for (int i = 0; i < S.size(); i++)
                    if ('A' <= S[i] && S[i] <= 'Z'){
                        S[i] = 'a';
                        break;
                    }
                cout<<S<<endl;
                continue;
            }
        }
        if (z == 0){
            if (y > 1){
                for (int i = 0; i < S.size(); i++)
                    if ('a' <= S[i] && S[i] <= 'z'){
                        S[i] = 'A';
                        break;
                    }
                cout<<S<<endl;
                continue;
            }
            if (x > 1){
                for (int i = 0; i < S.size(); i++)
                    if ('0' <= S[i] && S[i] <= '9'){
                        S[i] = 'A';
                        break;
                    }
                cout<<S<<endl;
                continue;
            }
        }
    }
    return 0;
}