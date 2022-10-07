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

const ll N = 3e5 + 5;

int n, m;

string S[N];
string s[N];
int pas = N + 5;
string ans[N];
char ch[4] = {'A', 'C', 'G', 'T'};
int a[4];
int A[2];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i = 1; i <= n; i++){
        cin>>S[i];
        S[i] = "#" + S[i];
        s[i] = S[i];
        ans[i] = S[i];
    }
    for (a[0] = 0; a[0] < 4; a[0]++)
        for (a[1] = a[0] + 1; a[1] < 4; a[1]++)
            for (a[2] = 0; a[2] < 4; a[2]++)
            if (a[0] != a[2] && a[1] != a[2]){
                a[3] = 6 - a[0] - a[1] - a[2];
                if (a[3] < a[2])
                    continue;
                for (int I = 0; I < 4; I += 2){
                    for (int i = 1 + I / 2; i <= n; i += 2){
                        int x = 0, y = 0;
                        for (int j = 1; j <= m; j++){
                            if (S[i][j] == ch[a[I + j % 2]])
                                x++;
                            if (S[i][j] == ch[a[I + 1 - j % 2]])
                                y++;
                        }
                        A[0] = a[I];
                        A[1] = a[I + 1];
                        if (x < y)
                            swap (A[0], A[1]);
                        for (int j = 1; j <= m; j++)
                            s[i][j] = ch[A[j % 2]];
                    }
                }
                int c = 0;
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= m; j++)
                        if (s[i][j] != S[i][j])
                            c++;
                if (c < pas){
                    pas = c;
                    for (int i = 1; i <= n; i++)
                        ans[i] = s[i];
                }
            }
    for (a[0] = 0; a[0] < 4; a[0]++)
        for (a[1] = a[0] + 1; a[1] < 4; a[1]++)
            for (a[2] = 0; a[2] < 4; a[2]++)
            if (a[0] != a[2] && a[1] != a[2]){
                a[3] = 6 - a[0] - a[1] - a[2];
                if (a[3] < a[2])
                    continue;
                for (int I = 0; I < 4; I += 2){
                    for (int i = 1 + I / 2; i <= m; i += 2){
                        int x = 0, y = 0;
                        for (int j = 1; j <= n; j++){
                            if (S[j][i] == ch[a[I + j % 2]])
                                x++;
                            if (S[j][i] == ch[a[I + 1 - j % 2]])
                                y++;
                        }
                        A[0] = a[I];
                        A[1] = a[I + 1];
                        if (x < y)
                            swap (A[0], A[1]);
                        for (int j = 1; j <= n; j++)
                            s[j][i] = ch[A[j % 2]];
                    }
                }
                int c = 0;
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= m; j++)
                        if (s[i][j] != S[i][j])
                            c++;
                if (c < pas){
                    pas = c;
                    for (int i = 1; i <= n; i++)
                        ans[i] = s[i];
                }
            }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            cout<<ans[i][j];
        cout<<endl;
    }
    return 0;
}